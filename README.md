[![License](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-blue.svg)](https://bit.ly/cc-by-nc-sa-40)

# Template repository

This is a template repository for programming laboratory works in BSUIR.

# Usage

To compile and run a program use:
```
$ ./build.sh gcc src/<filename>
```

Executable will be started automatically. It can be found in `build/scr/` folder.

# Semester \<2\> lab \<2\>

## Task \<1\>

Структура содержит информацию о сериалах: количество серий (число), название (указатель), вложенное объединение – дату выхода на экран (строка фиксированной длины) и количество сезонов. Найти сериалы с *минимальным количеством сезонов*. Удалить сериалы с *заданной датой выхода на экран*.

1. Организовать структуру, содержащую объединение (по варианту), в main объявить динамический массив структур, проверить выделение памяти и освободить её в конце программы (1 балл, 5 мин).
2. Дополнить функции для ввода и вывода первых двух полей структуры из ЛР1 вводом и выводом остальных полей (+1 балл, 10 мин).
3. Написать функцию поиска в массиве структур по заданному параметру (+2 балла, 20 мин).
4. Написать функцию удаления структур из массива по заданному параметру (+2 балла, 20 мин).
5. Для решения задачи организовать меню для работы с массивом структур и всевозможные проверки на корректность получаемых данных (+4 балла, 25 мин).

# Credits

Written by Alexey Filich.

# License

This repository is licensed under [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International](LICENCE.md).

# Notes

For compiling with SDL2:
```
-lmingw32 -lSDL2main -lSDL2
```

For compiling with ncurses
```
-lncursesw
```

## Description for some `include` files:

- stdarg.h

    Variable arguments with `va_list args; va_start(args, last_variable_in_function); va_arg(args, type)`.

- stdbool.h

    `True` and `false`.

- stdio.h

    `printf`, `scanf`, `NULL`, etc.

- stdlib.h

    Memory: `malloc`, `calloc`, `free`, \
    Random: `rand`, `srand`.

- string.h

    `memset`, `memcpy`, `memmove`.

- time.h

    `time(0)`.
