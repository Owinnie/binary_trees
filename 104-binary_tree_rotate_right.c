#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right rotate binary tree
 * @tree: pointer to the root node
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new = NULL, *root = NULL;

	if (tree == NULL)
		return (tree);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (tree);

	new = tree->left;

	tree->left = new->right;

	if (new->right != NULL)
		new->right->parent = tree;

	new->parent = tree->parent;

	if (tree->parent == NULL)
		root = new;
	else if (tree == tree->parent->right)
		tree->parent->right = new;
	else
		tree->parent->left = new;

	new->right = tree;
	tree->parent = new;

	if (root)
		return (root);
	return (new);
}
