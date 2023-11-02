#include "binary_trees.h"

/**
* binary_tree_balance - Measures the balance factor
*			of a binary tree
* @tree: A pointer to the root node of the tree
*	measure the balance factor
* Return: 0, if tree is NULL, otherwise the balance factor
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int b_factor = 0;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (b_factor);

	if (tree->left && tree->right)
		b_factor += 2;

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		b_factor -= 1;

	return (b_factor);
}
