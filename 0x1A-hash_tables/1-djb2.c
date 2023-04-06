#include "hash_tables.h"

/**
 * hash_djb2 - A hash function implementing the djb2 algorithm.
 * @str: The string that will be hashed.
 *
 * Return: The hash to be calculated.
 */
unsigned long int hash_djb2_func(const unsigned char *str)
{
	unsigned long int hash;
	int num;

	hash = 5381;
	while ((num = *str++))
		hash = ((hash << 5) + hash) + num; /* hash * 33 + num */

	return (hash);
}
