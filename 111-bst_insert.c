#include "binary_trees.h"

/**
* bst_insert - Inserts a value into a Binary Search Tree
* @tree: Double pointer to the root node of the tree
* @value: Value to store in the node to be inserted
*
* Description: if the address stored in tree is NULL
*	       the created node must become the root node
*	       if the value is already present in the tree
*	       it must be ignored.
*
* Return: Pointer to the created node || NULL on failure
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current_node, *parent;

	if (tree == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* checks if the root node(*tree) is NULL, tree is initially empty*/
	/* no node in the tree.  set root node to be the new node*/
	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}

	current_node = *tree;
	while (current_node)
	{
		parent = current_node;
		if (value < current_node->n)
			current_node = current_node->left;
		else if (value > current_node->n)
			current_node = current_node->right;
		else
		{
			free(new_node);
			return (NULL); /*duplicate value*/
		}
	}

	/*sets parent of the new node to the last visited node*/
	new_node->parent = parent;
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}
