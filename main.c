// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define _USE_MATH_DEFINES // for C
#include <math.h>

#include "functions.h"

int main()
{
   setlocale(LC_ALL, "Russian");
   srand((unsigned int)time(NULL));

   return 0;
}
