// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <stdio.h>
#include <locale.h>

#include "functions.h"

int main()
{
   setlocale(LC_ALL, "Russian");

   int x = 0;

   printf("Введите число: ");
   scanf_s("%d", &x);

   //printf("Функция FI(%d) = %d", x, FI(x));

   //printf("Функция Fact(%d) = %llu\n", x, Fact(x));

   //printf("Функция DFact(%d) = %llu\n", x, DFact(x));

   //printf("Задача Эйлера №2 при входном параметре %d равна %llu\n", x, Euler_2(x));

   //printf("%d-й член ряда Фибоначчи равен %llu", x, Fib(x));

   return 0;
}

/*
   Домашнее задание:

   Функция FI(x) - функция Эйлера. Нужно её вычислить!

   Подсчитывает количество чисел взаимно простых с x.

   Число "X" и "Y" взаимно простые, если НОД(X, Y) = 1 (НОД - Наибольший общий делитель).

*/

/*
* Д / З:
* Дан ряд Фибоначчи.
* Найти сумму всех четных элементов ряда Фибоначчи,
* которые не превышают 4 миллиона.
*/

/*
* Д / З:
* Простые делители числа 13195 - это 5, 7, 13 и 29.
* Каков самый большой делитель числа 600851475143, являющийся простым числом?
*/