#include "binary_trees.h"
/**
* binary_tree_depth - Measures the depth of a node in a binary tree
* @tree: A pointer to the node to measure the depth
* Return: if tree is NULL, return 0, otherwise depth of tree
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
