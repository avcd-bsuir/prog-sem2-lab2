// License: CC BY-NC-SA 4.0
/*
 * task2.c
 *
 * Serial manager.
 *
 * Written by AlexeyFilich
 * 22 feb 2021
 */

#define STORAGE_OPTIMAL

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Interactions.h>
#include <storage/Storage.h>

typedef enum {
    DATA_SEASONS,
    DATA_RELEASE_DATE
} UnionData;

typedef union {
    int seasons;
    char release_date[10];
} ReleaseInfo;

typedef struct {
    int episodes;
    char * name;
    UnionData data;
    ReleaseInfo info;
} Serial;

// Add serial to array
void pushSerial(Array * array, int episodes, char * name, UnionData data, int seasons, char release_date[]) {
    Serial serial;
    serial.episodes = episodes;
    serial.name = name;
    serial.data = data;
    if (data == DATA_SEASONS)
        serial.info.seasons = seasons;
    else if (data == DATA_RELEASE_DATE)
        strcpy(serial.info.release_date, release_date);
    aArrayPush(array, &serial);
}

// Print fields
void printSerial(Serial serial) {
    printf("Serial information:\n");
    printf("  Name: %s\n", serial.name);
    printf("  Episodes: %d\n", serial.episodes);
    if (serial.data == DATA_SEASONS)
        printf("  Seasons: %d\n", serial.info.seasons);
    else
        printf("  Seasons: no data provided\n");
    if (serial.data == DATA_RELEASE_DATE)
        printf("  Release date: %s\n", serial.info.release_date);
    else
        printf("  Release date: no data provided\n");
    printf("\n");
}

void findSerial(Array * array) {
    if (array->size == 0) {
        printf("No serials to find\n");
        return;
    }

    int seasons = -1;
    for (int i = 0; i < array->size; i++) {
        if ((*(Serial *)aArrayGet(array, i)).data == DATA_SEASONS) {
            seasons = (*(Serial *)aArrayGet(array, i)).info.seasons;
            break;
        }
    }

    for (int i = 0; i < array->size; i++)
        if ((*(Serial *)aArrayGet(array, i)).data == DATA_SEASONS && (*(Serial *)aArrayGet(array, i)).info.seasons < seasons)
            seasons = (*(Serial *)aArrayGet(array, i)).info.seasons;

    for (int i = 0; i < array->size; i++)
        if ((*(Serial *)aArrayGet(array, i)).data == DATA_SEASONS && (*(Serial *)aArrayGet(array, i)).info.seasons == seasons)
            printSerial(*(Serial *)aArrayGet(array, i));
}

void deleteSerial(Array * array) {
    char date[11];

    printf("Release date: ");
    fgets(date, 11, stdin);

    for (int i = 0; i < array->size; i++) {
        if ((*(Serial *)aArrayGet(array, i)).data == DATA_RELEASE_DATE && !strcmp((*(Serial *)aArrayGet(array, i)).info.release_date, date)) {
            aArrayRemove(array, i);
            i--;
            printf("A serial was deleted\n");
        }
    }

    printf("\n");
}

int main(int argc, char* args[]) {
    // Init serials
    Array array;
    aArrayInit(&array, 0, Serial);
    pushSerial(&array, 51, "Breaking Bad", DATA_RELEASE_DATE, 0, "19.10.2002");
    pushSerial(&array, 12, "The Walking Dead", DATA_SEASONS, 5, "xx.xx.xxxx");
    pushSerial(&array, 31, "WinX Club", DATA_SEASONS, 7, "xx.xx.xxxx");
    pushSerial(&array, 14, "'24'", DATA_SEASONS, 5, "xx.xx.xxxx");
    pushSerial(&array, 712, "Santa Barbara", DATA_RELEASE_DATE, 0, "15.04.1995");

    // Menu
    while (true) {
        printf("-- Serial manager\n");
        printf("  1. Print data of all serials\n");
        printf("  2. Find serial with least of seasons\n");
        printf("  3. Delete serial with specific release date\n");
        printf("  4. Exit\n");

        int option;
        do {
            aScanCheck("> ", "%d", &option);
        } while (option < 1 || option > 4);
        printf("\n");

        switch (option) {
            case 1:
                for (int i = 0; i < array.size; i++)
                    printSerial(*(Serial *)aArrayGet(&array, i));
                break;
            case 2:
                findSerial(&array);
                break;
            case 3:
                deleteSerial(&array);
                break;
            case 4:
                aArrayDestroy(&array);
                printf("Goodbye...\n");
                exit(0);
                break;
        }
    }

    return 0;
}
