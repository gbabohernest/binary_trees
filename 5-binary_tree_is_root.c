#include "binary_trees.h"

/**
* binary_tree_is_root - Checks if a given node is a root node.
* @node: A pointer to the node to check.
* Return: 1 if node is a root, otherwise 0
*	 if node is NULL, return 0
*/

int binary_tree_is_root(const binary_tree_t *node)
{
	binary_tree_t *is_root;

	if (node == NULL)
		return (0);

	is_root = node->parent;

	if (!is_root)
		return (1);

	return (0);
}
