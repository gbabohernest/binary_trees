#include "binary_trees.h"
int is_leaf_node(const binary_tree_t *tree);
size_t has_children(const binary_tree_t *tree);

/**
* binary_tree_is_full - Checks if a binary tree is full
* @tree: A pointer to the root node of the tree to check
* Return: 0, if tree is NULL, not full | otherwise 1
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	/*int  is_left_full, is_right_full,*/
	int is_leafNode;

	if (tree == NULL)
		return (0);

	/*
	 * if ((tree->left == NULL && tree->right) ||
	 *	(tree->left && tree->right == NULL) ||
	 *	binary_tree_is_full(tree->left) == 0 ||
	 *	binary_tree_is_full(tree->right) == 0)
	*/
		/*return (0);*/

	/*if (tree->left && tree->right)*/
	/*{*/
		/*is_left_full = binary_tree_is_full(tree->left);*/
		/*is_right_full = binary_tree_is_full(tree->right);*/
	/*}*/

	/*return (is_left_full && is_right_full);*/
	is_leafNode = is_leaf_node(tree);
	if (is_leafNode)
		return (1);

	if (has_children(tree))
	{
		return (binary_tree_is_full(tree->left) * binary_tree_is_full(tree->right));
	}
	return (0);
}


/**
* is_leaf_node - Checks if a node is a leaf node
*		(no children) at left and right
* @tree: A pointer to the root node of the tree to check
* Return: 1 if node is a leaf, 0 if not
*/

int is_leaf_node(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		return (0);

	return (1);
}

/**
* has_children - Checks if a node has two children
* @tree: A pointer to the root node of the tree to check
* Return:  1 if there are 2 children, 0 otherwise
*/

size_t has_children(const binary_tree_t *tree)
{
	if (tree->left  && tree->right)
		return (1);

	return (0);
}
