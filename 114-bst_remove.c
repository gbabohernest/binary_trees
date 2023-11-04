#include "binary_trees.h"

bst_t *find_min(bst_t *node);
bst_t *bst_remove_node(bst_t *root, bst_t *node);
bst_t *custom_bst_remove_recursive(bst_t *root, bst_t *node, int value);


/**
* find_min - Find the node with the minimum value in a BST
* @node: A pointer to the root of the BST
* Return: A pointer to the node with the minimum value
*/

bst_t *find_min(bst_t *node)
{
	bst_t *current = node;

	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
* bst_remove_node - Removes a node from a Binary Search Tree.
* @root: A pointer to the root node of the BST
* @node: A pointer to the node to remove from the BST.
*
* Return: Pointer to the new root node after removal.
*/

bst_t *bst_remove_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/*No children or right-child only*/
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;

		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return ((parent == NULL ? node->right : root));
	}

	/*left-child only*/
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;

		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return ((parent == NULL ? node->left : root));
	}

	/*two children*/
	successor = find_min(node->right);
	node->n = successor->n;

	return (bst_remove_node(root, successor));
}

/**
* custom_bst_remove_recursive - Removes a node from a
*				binary search tree recursively.
* @root: A pointer to the root node of the BST to remove a node from.
* @node: A pointer to the current node in the BST.
* @value: The value to remove from the BST.
*
* Return: A pointer to the root node after deletion.
*/

bst_t *custom_bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_remove_node(root, node));
		if (node->n > value)
			return (custom_bst_remove_recursive(root, node->left, value));

		return (custom_bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
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

	return (custom_bst_remove_recursive(root, root, value));
}
