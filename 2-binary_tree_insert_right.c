#include "binary_trees.h"

/**
 * binary_tree_insert_right - function inserts a right child
 * @parent: pointer to the parent node
 * @value: value to put into right child
 * Return:
 * 1. upon success, return pointer to right child
 * 2. upon fail, return NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child = NULL;

	if (parent == NULL)
		return (NULL);

	right_child = malloc(sizeof(binary_tree_t));
	if (right_child == NULL)
		return (NULL);

	right_child->n = value;
	right_child->left = NULL;
	right_child->right = NULL;
	right_child->parent = parent;

	if (parent->right != NULL)
	{
		right_child->right = parent->right;
		(parent->right)->parent = right_child;
	}
	parent->right = right_child;
	return (right_child);
}
