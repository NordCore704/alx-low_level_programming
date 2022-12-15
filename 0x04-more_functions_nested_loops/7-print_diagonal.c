#include "main.h"

/**
 * print_diagonal - print slash
 * @n: params
 */

void print_diagonal(int n)
{
	int i = 0;
	int y;

	if (n > 0)
	{
		for (; i < n; i++)
		{
			for (y = 0; y < i; y++)
			{
				_putchar(' ');
			}
			_putchar(92);
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
