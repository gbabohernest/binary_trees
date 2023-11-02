#include "binary_trees.h"

/**
* binary_tree_leaves - Counts the leaves in a binary tree
* @tree: A pointer to the root node
* Return: 0, if tree is NULL, otherwise number of leaves
*/

size_t binary_tree_leaves(const binary_tree_t *tree)
{	size_t n_leaf = 0, left_leaf = 0, right_leaf = 0;
	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (n_leaf + 1);

	left_leaf += binary_tree_leaves(tree->left);
	right_leaf += binary_tree_leaves(tree->right);

	n_leaf  += left_leaf + right_leaf;
	return (n_leaf);
}
