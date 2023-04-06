#include "./hash_tables.h"

/**
 * hash_table_print - This function prints a hash table.
 * @hash_t: A pointer to the hash table to be printed.
 *
 * Description: Key/value pairs will be printed in the order in which 
 *              they appear in the array of the hash table.
 */
void hash_table_print(const hash_table_t *hash_t)
{
	hash_node_t *node;
	unsigned long int i;
	unsigned char flag = 0;

	if (hash_t == NULL)
		return;

	printf("{");
	for (i = 0; i < hash_t->size; i++)
	{
		if (hash_t->array[i] != NULL)
		{
			if (flag == 1)
				printf(", ");

			node = hash_t->array[i];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			flag = 1;
		}
	}
	printf("}\n");
}
