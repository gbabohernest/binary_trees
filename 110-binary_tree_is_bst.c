#include <limits.h>
#include "binary_trees.h"

int is_valid_bst(const binary_tree_t *node, int *prev);
/**
* is_valid_bst - recursively checks if a binary tree is a valid BST
* @node: current node being checked
* @prev: the previous node's value in the in-order traversal
*
* Return: 1 if the tree is a valid BST, 0 otherwise
*/

int is_valid_bst(const binary_tree_t *node, int *prev)
{
	if (node == NULL)
		return (1);

	if (!is_valid_bst(node->left, prev))
		return (0);

	if (node->n <= *prev)
		return (0);

	*prev = node->n;

	return (is_valid_bst(node->right, prev));
}


/**
* binary_tree_is_bst - checks if a binary tree is a valid binary search tree
* @tree: pointer to the root node of the tree
*
* Return: 1 if valid BST, 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev = INT_MIN;

	if (tree == NULL)
		return (0);

	return (is_valid_bst(tree, &prev));
}
