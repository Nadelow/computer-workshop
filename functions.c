// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.co


#include <stdio.h>
#include <math.h> // Стандартная математическая библиотека
#include <stdlib.h>


#include "functions.h"

int EvenCount(int t_)
{   
   // Количество четных цифр
   int count = 0;

   // Берём последнюю цифру числа t_ и смотрим её чётность
   while (t_ != 0)
   {
      // Последняя цифра в числе
      int x = t_ % 10;

      if (x % 2 == 0)
         count++;

      t_ /= 10; // t_ = t_ / 10;
   }

   return count;
}

int PI(int x_)
{
   // Обработаем исключения: проверим x_ < 2
   if (x_ < 2)
      return 0;

   int count = 0;

   for (unsigned int number = 2; number != x_; ++number)
      if (IsPrime(number))
         ++count;

   return count;
}

bool IsPrime(int number_)
{
   // Обработаем исключения: проверим number_ на отрицательность
   if (number_ < 2)
      return false;

   unsigned int nSqrt = (int)sqrt(number_) + 1; // т.к ф-я sqrt возвращает тип double, а нам нужно целое, то "приводим тип" к нужному с помощью (int)

   if (number_ == 2)
      return true;

   if (number_ % 2 == 0)
      return false;

   for (unsigned int i = 3; i <= nSqrt; i += 2)
   {
      if (number_ % i == 0)
         return false;
   }

   return true;
}

int FI(int x_)
{
   if (x_ < 1)
      return 0;

   int count = 0;

   for (int i = 1; i < x_; ++i)
      if (Gcd(i, x_) == 1)
         ++count;

   return count;
}

int Gcd(int a, int b)
{
   if (a < 0)
      a = abs(a);

   if (b < 0)
      b = abs(b);

   while (a != b)
   {
      if (a > b)
         a -= b;
      else
         b -= a;
   }

   return a;
}

unsigned long long Fact(int x_)
{
   if (x_ < 0)
   {
      printf("В функцию Fact поступило отрицательно значение %d\n", x_);
      exit(EXIT_FAILURE);
   }

   if (x_ == 0)
      return 1;

   unsigned long long res = 1;

   for (int i = 1; i <= x_; ++i)
      res *= i;

   return res;
}

unsigned long long DFact(int x_)
{
   if (x_ < 0)
   {
      printf("В функцию DFact поступило отрицательно значение %d\n", x_);
      exit(1);
   }

   if (x_ == 0)
      return 1;

   unsigned long long res = 1;

   int i = 0;
   if (x_ % 2 == 0)
      i = 2;
   else
      i = 1;

   for (; i <= x_; i += 2)
      res *= i;

   return res;
}

unsigned long long Euler_2(int x_)
{
   if (x_ < 0)
   {
      printf("В функцию Euler_2 подан отрицательный аргумент\n");
      exit(EXIT_FAILURE);  
   }

   unsigned long long sum = 0;

   unsigned long long prev = 0;
   unsigned long long cur = 1;

   while (cur <= x_)
   {
      if (cur % 2 == 0)
         sum += cur;

      unsigned long long next = cur + prev;

      prev = cur;
      cur = next;
   }

   return sum;
}

unsigned long long Euler_3(long long n_)
{
   if (n_ < 1)
   {
      printf("Error input argument Euler_3(%lli)\n", n_);
      exit(EXIT_FAILURE);
   }

   unsigned long long factor = 3;
   unsigned long long lastFactor = 1;

   if (n_ % 2 == 0)
   {
      n_ /= 2;
      lastFactor = 2;
      
      while (n_ % 2 == 0)
         n_ /= 2;  
   }

   unsigned long long maxFactor = ceil(sqrt(n_));

   while (n_ > 1 && factor <= maxFactor)
   {
      if (n_ % factor == 0)
      {
         lastFactor = factor;
         n_ /= factor;

         while (n_ % factor == 0)
            n_ /= factor;

         maxFactor = ceil(sqrt(n_));
      }

      factor += 2;
   }

   if (n_ == 1)
      return lastFactor;
   else
      return n_;
}

unsigned long long Fib(int n_)
{
   if (n_ < 0)
   {
      printf("Error input argument Fib(%d)\n", n_);
      exit(EXIT_FAILURE);
   }

   if (n_ < 2)
      return n_;

   return Fib(n_ - 1) + Fib(n_ - 2);
}

void Gallows(int numberOfAttempts_)
{
   if (numberOfAttempts_ < 1)
   {
      printf("Wrong number of attempts!\n");
      return;
   }

   int guess = 1 + rand() % 101;

   do
   {
      int n = 0;

      printf("Enter guess number (%d attempts): ", numberOfAttempts_);
      scanf_s("%d", &n);

      if (n == guess)
      {
         printf("You are winner!\n");
         return;
      }

      if (n < guess)
         printf("Your guess less!\n");

      if (n > guess)
         printf("Your guess more!\n");

      numberOfAttempts_--;

   } while (numberOfAttempts_ > 0);

   printf("You lose! Number is %d\n", guess);
   return;
}
