#include "search.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * search_skip - search for a value.
 * @ben: main node
 * @end: last node
 * @value: value
 * Return: NULL
 */
skiplist_t *search_skip(skiplist_t *ben, skiplist_t *end, int value)
{
	char *format = "Value found between indexes [%li] and [%li]\n";
	char *fmt = "Value checked at index [%li] = [%i]\n";

	printf(format, ben->index, end->index);
	while (ben != end->next)
	{
		printf(fmt, ben->index, ben->n);
		if (value == ben->n)
			return (ben);
		ben = ben->next;
	}
	return (NULL);
}
/**
 * linear_skip - search for a number in a linear skip
 * @head: list of type skiplis_t
 * @value: value
 * Return: NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *ben, *end;
	char *format = "Value checked at index [%li] = [%i]\n";

	if (!head)
		return (NULL);
	end = head;
	while (end && end->next && end->n < value)
	{
		ben = end;
		if (!end->express)
		{
			while (end->next)
				end = end->next;
			continue;
		}
		else
			end = end->express;
		printf(format, end->index, end->n);
	}
	return (search_skip(ben, end, value));
}
