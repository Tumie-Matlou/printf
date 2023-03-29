#include "main.h"

/**
 * count_int_digits - returns the number of digits in an integer
 * @n: the integer to count digits in
 *
 * Return: the number of digits in n
 */
int count_int_digits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
