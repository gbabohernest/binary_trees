#include "binary_trees.h"

/**
* binary_tree_sibling - Finds the sibling of a node
* @node: A pointer to the node to find the sibling
*
* Description: if node is NULL | parent is NULL
*	       return NULL
*	       if node has no sibling, return NULL
* Return: A pointer to the sibling node, otherwise NULL
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent_of_node, *sibling_node;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent_of_node = node->parent;

	if ((parent_of_node->left == node) && (parent_of_node->right != NULL))
	{
		sibling_node = parent_of_node->right;
		return (sibling_node);
	}
	else if ((parent_of_node->left != NULL) && (parent_of_node->right == node))
	{
		sibling_node = parent_of_node->left;
		return (sibling_node);
	}
	return (NULL);
}
