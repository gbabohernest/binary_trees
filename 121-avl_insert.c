#include "binary_trees.h"

size_t tree_height(const binary_tree_t *tree);
int get_balance(const binary_tree_t *node);
avl_t *avl_insert_helper(avl_t **tree, avl_t *parent,
			avl_t **new_node, int val);

/**
* tree_height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, return 0, else return height.
*/
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
* get_balance - Calculates the balance factor of a node in an AVL tree.
* @node: A pointer to the node to calculate the balance factor for.
*
* Return: The balance factor of the node, otherwise 0.
*/

int get_balance(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (tree_height(node->left) - tree_height(node->right));
}

/**
* avl_insert_helper - Inserts a value into an AVL tree recursively.
* @tree: A double pointer to the root node of the AVL tree to insert into.
* @parent: The parent node of the current working node.
* @new_node: A double pointer to store the new node.
* @val: The value to insert into the AVL tree.
*
* Return: A pointer to the new root after insertion, or NULL on failure.
*/

avl_t *avl_insert_helper(avl_t **tree, avl_t *parent,
				avl_t **new_node, int val)
{
	int bal_factor;

	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, val);
		return (*new_node);
	}

	if ((*tree)->n > val)
	{
		(*tree)->left = avl_insert_helper(&(*tree)->left, *tree, new_node, val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = avl_insert_helper(&(*tree)->right, *tree, new_node, val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bal_factor = get_balance(*tree);
	if (bal_factor > 1 && val < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (bal_factor < -1 && val > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (bal_factor > 1 && val > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_factor < -1 && val < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
* avl_insert - Inserts a value into an AVL tree.
* @tree: A double pointer to the root node of the AVL tree to insert into.
* @value: The value to insert into the AVL tree.
*
* Return: A pointer to the inserted node, or NULL on failure.
*/

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_helper(tree, *tree, &new_node, value);
	return (new_node);
}
