#include "main.h"

/**
 * print_square - prints square
 * @size: param
 */

void print_square(int size)
{
	int i = 0, y;

	if (size > 0)
	{
		for (; i < size; i++)
		{
			for (y = 0; y < size; y++)
				_putchar(35);
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
