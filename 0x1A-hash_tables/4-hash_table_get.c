#include "hash_tables.h"

/**
 * hash_table_get - Collect and store the value associated with
 *                  a key in a hash table.
 * @hash_t: A pointer that points to the hash table.
 * @key: The key whose value is being recieved.
 *
 * Return: If a match for the key cannot be found - NULL.
 *        Else - return the value associated with key in hash_t.
 */
char *hash_table_get(const hash_table_t *hash_t, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (hash_t == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, hash_t->size);
	if (index >= hash_t->size)
		return (NULL);

	node = hash_t->array[index];
	while (node && strcmp(node->key, key) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->value);
}
