#include "binary_trees.h"
#include "limits.h"

size_t binary_tree_height(const binary_tree_t *tree);
int is_valid_avl_tree(const binary_tree_t *tree, int min, int max);

/**
* binary_tree_height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, return 0, else return height.
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}


/**
* is_valid_avl_tree - Checks if a binary tree is a valid AVL tree.
* @tree: A pointer to the root node of the tree to check.
* @min: The minimum value that the current node's value can be.
* @max: The maximum value that the current node's value can be.
*
* Return: If the tree is a valid AVL tree, 1, otherwise, 0.
*/

int is_valid_avl_tree(const binary_tree_t *tree, int min, int max)
{
	size_t left_height, right_height, height_diff;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	height_diff = (left_height > right_height ? left_height
			- right_height : right_height - left_height);

	if (height_diff > 1)
		return (0);

	return (is_valid_avl_tree(tree->left, min, tree->n) &&
		is_valid_avl_tree(tree->right, tree->n, max));
}

/**
* binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
* @tree: A pointer to the root node of the tree to check.
*
* Return: 1 if tree is a valid AVL tree, and 0 otherwise
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_avl_tree(tree, INT_MIN, INT_MAX));
}
