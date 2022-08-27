#include "binary_trees.h"

size_t recurse_for_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to node to measure the balance factor
 * Return:
 * 1. upon success, return balance factor
 * 2. upon fail, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if ((tree->left == NULL) && (tree->right == NULL))
	{
		return (0);
	}

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (left - right);
}

/**
 * binary_tree_height - measure height of tree
 * @tree: tree to measure
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	return (recurse_for_height(tree) - 1);
}

/**
 * recurse_for_height - measure height
 * @tree: tree to measure
 *
 * Return: height
 */
size_t recurse_for_height(const binary_tree_t *tree)
{
	size_t heightR, heightL;

	if (!tree)
		return (0);

	heightL = recurse_for_height(tree->left);
	heightR = recurse_for_height(tree->right);

	if (heightL > heightR)
		return (heightL + 1);
	else
		return (heightR + 1);
}
