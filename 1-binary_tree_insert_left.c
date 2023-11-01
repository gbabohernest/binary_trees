#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node as the
*			left-child of another node
* @parent: A pointer to the node to insert the left-child in
* @value: Is the value to store in the new node
*
* Return: A pointer to the created node |
*	  NULL on failure | if parent is NULL
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_left;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	/*new_node = malloc(sizeof(binary_tree_t));*/

	if (!new_node)
		return (NULL);


	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else
	{
		old_left = parent->left;
		parent->left = new_node;
		new_node->left = old_left;
		old_left->parent = new_node;
	}
	return (new_node);
}
