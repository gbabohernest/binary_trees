#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node as the
*			left-child of another node
* @parent: A pointer to the node to insert the left-child in
* @value: Is the value to store in the new node

* Return: A pointer to the created node |
*	  NULL on failure | if parent is NULL
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *new_node, *tmp;

	new_node = binary_tree_node(parent, value);
	/*new_node = malloc(sizeof(binary_tree_t));*/

	if (!new_node)
		return (NULL);

	/*new_node->n = value;*/
	/*new_node->parent = parent;*/

	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else
	{
		tmp = parent->left;
		parent->left = new_node;
		new_node->left = tmp;
		tmp->parent = new_node;
	}
	return (new_node);
}
