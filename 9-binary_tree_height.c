#include "binary_trees.h"

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: A pointer to the root node of the tree to measure height
* Return: if tree is NULL, return 0
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
	{
		left_height += 1;
		left_height += binary_tree_height(tree->left);
	}
	if (tree->right)
	{
		right_height += 1;
		right_height += binary_tree_height(tree->right);
	}

	return ((left_height > right_height) ? left_height : right_height);
}
