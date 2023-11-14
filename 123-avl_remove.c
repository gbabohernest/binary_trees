#include "binary_trees.h"
avl_t *find_in_order_successor(avl_t *node);
avl_t *avl_balance(avl_t **root);

/**
* find_in_order_successor - Finds the in-order successor of a given node.
* @node: A pointer to the node for which to find the successor.
*
* Return: A pointer to the in-order successor node.
*/

avl_t *find_in_order_successor(avl_t *node)
{
	avl_t *current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}

	return (current);
}

/**
* avl_balance - Balance an AVL tree.
* @root: A pointer to the root of the AVL tree.
*
* Return: A pointer to the balanced AVL tree.
*/
avl_t *avl_balance(avl_t **root)
{
	int balance;

	if (*root == NULL)
		return (NULL);

	balance = binary_tree_balance(*root);

	if (balance > 1)  /* Left Heavy */
	{
		if (binary_tree_balance((*root)->left) >= 0)
			return (binary_tree_rotate_right(*root));
		else
			return (binary_tree_rotate_left(*root));
	}
	else if (balance < -1)  /* Right Heavy */
	{
		if (binary_tree_balance((*root)->right) <= 0)
			return (binary_tree_rotate_left(*root));
		else
			return (binary_tree_rotate_right(*root));
	}

	return (*root);
}


/**
* avl_remove - Removes a node from an AVL tree.
* @root: A pointer to the root node of the tree.
* @value: The value to remove from the tree.
*
* Return: A pointer to the new root node of the tree
*         after removal and rebalancing.
*/

avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}
		else if (root->left == NULL || root->right == NULL)
		{
			avl_t *temp = (root->left != NULL) ? root->left : root->right;

			free(root);
			return (temp);
		}
		else
		{
			avl_t *successor = find_in_order_successor(root->right);

			root->n = successor->n;
			root->right = avl_remove(root->right, successor->n);
		}
	}
	return (avl_balance(&root));
}
