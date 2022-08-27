#include "binary_trees.h"
bst_t *recurse_for_bst_insert(bst_t *tree, int value);
/**
 * bst_insert - insert node into BST
 * @tree: pointer to root of tree
 * @value: value to stored in inserted node
 *
 * Return: pointer to inserted node; NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *parent = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	parent = recurse_for_bst_insert(*tree, value);

	if (parent)
		new_node = binary_tree_node(parent, value);
	else
		return (NULL);

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
/**
 * recurse_for_bst_insert - recursively search tree
 * @tree: pointer to root of tree/subtree
 * @value: value being added
 *
 * Return: pointer to parent of new node; NULL on failure
 */
bst_t *recurse_for_bst_insert(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value < tree->n)
	{
		if (tree->left != NULL)
			return (recurse_for_bst_insert(tree->left, value));
		else
			return (tree);
	}

	else if (value > tree->n)
	{
		if (tree->right != NULL)
		{
			return (recurse_for_bst_insert(tree->right, value));
		}
		else
			return (tree);
	}

	return (NULL);
}
