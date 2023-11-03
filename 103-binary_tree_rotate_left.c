#include "binary_trees.h"

/**
* binary_tree_rotate_left - Performs a left-rotation on a binary tree
* @tree: A pointer to the root node of the tree to rotate
* Return: A pointer to the new root node of the tree
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp_ref, *new_root;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_root = tree->right;
	temp_ref = new_root->left;

	/*perform left rotation on the tree */
	new_root->left = tree;
	tree->right = temp_ref;

	if (temp_ref)
		temp_ref->parent = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;

	if (new_root->parent)
	{
		if (new_root->parent->left == tree)
		{
			new_root->parent->left = new_root;
		}
		else
		{
			new_root->parent->right = new_root;
		}
	}
	return (new_root);
}
