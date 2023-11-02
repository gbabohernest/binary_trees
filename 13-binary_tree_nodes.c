#include "binary_trees.h"

/**
* binary_tree_nodes - Counts the nodes with atleast
*		      1 child in a binary tree
* @tree: A pointer to the root node of the tree
* Return: 0, if tree is NULL, otherwise number of nodes
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t total_nodes = 0, total_ln = 0, total_rn = 0;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (total_nodes);

	if (tree->left || tree->right)
		total_nodes = 1;

	total_ln += binary_tree_nodes(tree->left);
	total_rn += binary_tree_nodes(tree->right);

	total_nodes  +=  total_ln + total_rn;

	return (total_nodes);
}
