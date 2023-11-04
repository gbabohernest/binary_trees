#include "binary_trees.h"

bst_t *find_min(bst_t *node);

/**
* find_min - Find the node with the minimum value in a BST
* @node: A pointer to the root of the BST
* Return: A pointer to the node with the minimum value
*/

bst_t *find_min(bst_t *node)
{
	while (node && node->left)
		node = node->left;

	return (node);
}

/**
* bst_remove - Removes a node form a Binary Search Tree
* @root: A pointer to the root node of the tree
*	 where node will be remove
* @value: Value to remove in the tree
*
* Return: A pointer to the new root node
*/

bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{

		if (root->left == NULL)
		{
			/*node has right child*/
			bst_t *temp_node = root->right;
			/*bst_t *temp_node = root;*/

			/*root = root->right;*/
			free(root);
			return (temp_node);
		}
		else if (root->right == NULL)
		{
			/*node has a left child*/
			bst_t *temp_node = root->left;
			/*bst_t *temp_node = root;*/

			/*root = root->left;*/
			free(root);
			return (temp_node);
		}
		else
		{
			/*node has 2 children*/
			bst_t *temp_node  = find_min(root->right);

			root->n = temp_node->n;
			root->right = bst_remove(root->right, temp_node->n);
		}
	}
	return (root);
}
