#include "binary_trees.h"

/**
 * bst_search - searches for a value in BST
 * @tree: pointer to the root node
 * @value: value to search
 * Return:
 * 1. upon success, return pointer to the node
 * 2. upon fail, return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* if there's no root node */
	if (tree == NULL)
	{
		return (NULL);
	}

	if (tree->n == value)
	{
		return ((bst_t *)tree);
	}

	if (tree->n > value)
	{
		return (bst_search(tree->left, value));
	}
	else
	{
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
