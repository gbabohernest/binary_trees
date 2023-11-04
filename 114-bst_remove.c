#include "binary_trees.h"

bst_t *find_min(bst_t *node);

/**
* find_min - Find the node with the minimum value in a BST
* @node: A pointer to the root of the BST
* Return: A pointer to the node with the minimum value
*/

bst_t *find_min(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
		current = current->left;

	return (current);
}

/**
* bst_remove - Removes a node from a Binary Search Tree.
* @root: A pointer to the root node of the tree
*	 where node will be remove
* @value: Value to remove in the tree.
*
* Return: Pointer to the root node.
*/

bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	/*Recursively search for the node to be removed*/
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/*Node with the value to be removed found*/

		/*node has only one child or no child*/
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		/* node has two children*/
		/*find the in-order successo*/
		bst_t *temp = find_min(root->right);

		root->n = temp->n;

		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
