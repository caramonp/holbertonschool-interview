#include "binary_trees.h"
/**
 * sorted_array_to_avl - sorted avl to tree
 * @array: array.
 * @size: size of array.
 * Return: tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	tree = add_node(array, 0, (int)size - 1);
	if (!tree)
		return (NULL);
	return (tree);
}
/**
 * create_node - create node
 * @n: number
 * Return: node
 */
avl_t *create_node(int n)
{
	avl_t *node = NULL;

	if (n == 0)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->n = n;
	return (node);
}
/**
 * add_node - add node with recursive fuction
 * @array: array.
 * @ben: begin.
 * @end: end.
 * Return: tree
 */
avl_t *add_node(int *array, int ben, int end)
{
	avl_t *left = NULL, *right = NULL, *parent = NULL;
	size_t n = 0;

	if (ben > end)
		return (NULL);
	n = (ben + end) / 2;
	left = add_node(array, ben, n - 1);
	right = add_node(array, n + 1, end);
	parent = create_node(array[n]);
	if (!parent)
		return (NULL);
	parent->left = left;
	parent->right = right;
	if (left)
		left->parent = parent;
	if (right)
		right->parent = parent;
	return (parent);
}
