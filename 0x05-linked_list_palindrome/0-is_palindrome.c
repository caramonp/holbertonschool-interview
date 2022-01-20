#include "lists.h"
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: head of list.
 * Return: 0 or 1.
 */
int is_palindrome(listint_t **head)
{
	listint_t *n, *node;

	if (*head == NULL || (*head)->next == NULL)
	return (1);

	node = *head;
	while (node->next)
	{
		node = node->next;
	}
	n = *head;
	while (node >= n)
	{
		if (n->n == node->n)
		{
			n = n->next;
			node -= 2;
		}
		else
			return (0);
	}
	return (1);
}

