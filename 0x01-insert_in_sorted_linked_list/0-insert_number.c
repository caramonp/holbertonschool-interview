#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node -add a new elements of a listint_t listint
 * @head: pointer to head of list
 * @number: direction of the new element
 * Return:  address of the new node, or NULL
 */
listint_t *insert_node(listint_t **head, int number){

  listint_t *node;
  listint_t *current;

  node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);
	node->n = number;
	if (!head || !(*head))
	{
		node->next = NULL;
    *head = node;
	}
	else if (number < (*head)->n)
	{
		node->next = *head;
    *head = node;
	}
	else
	{
		current = *head;
		while (current->next && current->next->n < number)
			current = current->next;

		if (!current->next)
		{
			node->next = NULL, current->next = node;
		}
		else
		{
			node->next = current->next;
			current->next = node;
		}
	}
	return (node);
}
