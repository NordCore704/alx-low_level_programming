#include "hash_tables.h"

/**
 * hash_table_set - Add to or update an element in an existing hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to be added - this cannot be an empty string.
 * @value: The value associated with key.
 *
 * Return: On fail - 0.
 *         On Success - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *value_copy;
	unsigned long int idx, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	copy_value= strdup(value);
	if (copy_value== NULL)
		return (0);

	idx = key_idx((const unsigned char *)key, ht->size);
	for (i = idx; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_copy;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[idx];
	ht->array[idx] = new;

	return (1);
}
