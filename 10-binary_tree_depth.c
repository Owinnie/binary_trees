#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of binary tree
 * @tree: ptr to node to measure depth
 * Return:
 * 1. upon success, return depth
 * 2. upon fail, return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
	{
		return (0);
	}

	while (tree)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth - 1);
}
