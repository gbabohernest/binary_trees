#include "binary_trees.h"
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_nodes_count(const binary_tree_t  *tree);

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: A pointer to the root node of the tree to measure height
* Return: if tree is NULL, return 0
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
* binary_tree_count_nodes - Count the number of nodes in a binary tree
* @tree: A pointer to the root of the binary tree
* Return: The number of nodes in the tree
*/
size_t binary_tree_count_nodes(const binary_tree_t *tree)
{
	size_t left_node_count = 0, right_node_count = 0;

	if (tree == NULL)
		return (0);

	left_node_count += binary_tree_count_nodes(tree->left);
	right_node_count += binary_tree_count_nodes(tree->right);

	return (1 + left_node_count + right_node_count);
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect
* @tree: A pointer to the root node of the tree to check
* Return: 1 if tree is perfect, otherwise 0
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height, node_count;

	if (tree == NULL)
		return (0);

	tree_height = binary_tree_height(tree);
	node_count = binary_tree_count_nodes(tree);

	return (node_count == (size_t)((1 << tree_height) - 1));
}
