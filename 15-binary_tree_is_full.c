#include "binary_trees.h"
/*int is_tree_full_recursion(const binary_tree_t *tree);*/
/**
* binary_tree_is_full - Checks if a binary tree is full
* @tree: A pointer to the root node of the tree to check
* Return: 0, if tree is NULL, not full | otherwise 1
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	int  is_left_full, is_right_full;

	if (tree == NULL)
		return (0);

	if ((tree->left == NULL && tree->right) ||
		(tree->left && tree->right == NULL))
		return (0);

	if (tree->left && tree->right)
	{
		is_left_full = binary_tree_is_full(tree->left);
		is_right_full = binary_tree_is_full(tree->right);
	}

	return (is_left_full && is_right_full);
}
