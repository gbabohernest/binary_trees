#include "binary_trees.h"

/**
* bst_search - Searches for a value in a Binary Search Tree
* @tree: A pointer to the root node of the BST
* @value: Value to search in the tree
*
* Return: A pointer to the node containing the value, or NULL if not found.
*	  if the tree is NULL or nothing is found, return NULL
*/

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}
	if (tree->n == value)
	{
		/*Found the value at the current node */
		return ((bst_t *)tree);
	}
	if (value < tree->n)
	{
		/*value is smaller, search left sub-tree*/
		return (bst_search(tree->left, value));
	}
	else
	{
		/*value is larger, search right sub-tree*/
		return (bst_search(tree->right, value));
	}
}
