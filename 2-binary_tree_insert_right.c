#include "binary_trees.h"

/**
* binary_tree_insert_right - Inserts a node as the
*			right-child of another node
* @parent: A pointer to the node to insert the right-child in
* @value: Is the value to store in the new node
*
* Return: A pointer to the created node |
*	  NULL on failure | if parent is NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_right;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	old_right = parent->right;

	if (old_right != NULL)
	{
		new_node->right = old_right;
		old_right->parent = new_node;
	}

	parent->right = new_node;
	return (new_node);
}
