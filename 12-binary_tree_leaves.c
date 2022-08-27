#include "binary_trees.h"

/**
 * binary_tree_leaves - counts leaves of a binary tree
 * @tree: pointer to node to count leaves
 * Return:
 * 1. upon success, return number of leaves
 * 2. upon fail, return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if ((tree->left == NULL) && (tree->right == NULL))
	{
		return (1);
	}

	leaves = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
	return (leaves);
}
