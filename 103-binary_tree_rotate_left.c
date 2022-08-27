#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left rotate binary tree
 * @tree: pointer to the root node
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new = NULL, *root = NULL;

	if (tree == NULL)
		return (tree);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (tree);

	new = tree->right;
	tree->right = new->left;
	if (new->left != NULL)
		new->left->parent = tree;
	new->parent = tree->parent;
	if (tree->parent == NULL)
		root = new;
	else if (tree == tree->parent->left)
		tree->parent->left = new;
	else
		tree->parent->right = new;
	new->left = tree;
	tree->parent = new;
	if (root)
		return (root);
	return (new);
}
