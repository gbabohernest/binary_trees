#include "binary_trees.h"

/**
* binary_tree_uncle - Finds the uncle of a node
* @node: A pointer to the node to find the uncle
*
* Description: if node is NULL, return NULL
*	       if node has no uncle, return NULL
* Return: A pointer to the uncle node, otherwise NULL
*/

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent_of_node, *grand_parent_node, *uncle_node;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent_of_node = node->parent;
	grand_parent_node = parent_of_node->parent;

	if ((grand_parent_node->left == parent_of_node) &&
		(grand_parent_node->right != NULL))
	{
		uncle_node = grand_parent_node->right;
		return (uncle_node);
	}
	else if ((grand_parent_node->left != NULL) &&
		(grand_parent_node->right == parent_of_node))
	{
		uncle_node = grand_parent_node->left;
		return (uncle_node);
	}

	return (NULL);
}
