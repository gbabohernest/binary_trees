#include "binary_trees.h"

#define MAX(a, b) ((a > b) ? (a) : (b))

size_t tree_height(const binary_tree_t *tree);
int get_balance(const binary_tree_t *node);
avl_t *avl_insert_helper(avl_t **tree, avl_t *parent, int value);
void avl_balance(avl_t **tree, int value);


/**
* tree_height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, return 0, else return height.
*/

size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
	/*return (1 + MAX(left_height, right_height));*/
}


/**
* get_balance - Calculates the balance factor of a node in an AVL tree.
* @node: A pointer to the node to calculate the balance factor for.
*
* Return: The balance factor of the node.
*/

int get_balance(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (tree_height(node->left) -
		tree_height(node->right));
}


/**
* avl_insert_helper - Inserts a value into an AVL tree recursively.
* @tree: A double pointer to the root node of the AVL tree to insert into.
* @parent: The parent node of the current working node.
* @value: The value to insert into the AVL tree.
*
* Return: A pointer to the new root after insertion, or NULL on failure.
*/
avl_t *avl_insert_helper(avl_t **tree, avl_t *parent, int value)
{
	if (*tree == NULL)
		return (binary_tree_node(parent, value));

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert_helper(&(*tree)->left, *tree, value);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert_helper(&(*tree)->right, *tree, value);
	}
	else
	{
		/*duplicate value are not allowed*/
		return (*tree);
	}

	return (*tree);
}


/**
* avl_balance - Balances an AVL tree after insertion.
* @tree: A double pointer to the root node of the AVL tree.
* @value: The value that was just inserted.
*
* void (nothing)
*/

void avl_balance(avl_t **tree, int value)
{
	avl_t *current = *tree;

	while (current)
	{
		/*bf = balance_factor*/
		int bf = get_balance(current);

		if (bf > 1 && value < current->left->n)
			*tree = binary_tree_rotate_right(*tree);
		else if (bf < -1 && value > current->right->n)
			*tree = binary_tree_rotate_left(*tree);
		else if (bf > 1 && value > current->left->n)
		{
			current->left = binary_tree_rotate_left(current->left);
			*tree = binary_tree_rotate_right(*tree);
		}
		else if (bf < -1 && value < current->right->n)
		{
			current->right = binary_tree_rotate_right(current->right);
			*tree = binary_tree_rotate_left(*tree);
		}

		current = current->parent;

	}
}



/**
* avl_insert - Inserts a value into an AVL tree.
* @tree: A double pointer to the root node of the AVL tree.
* @value: The value to insert into the AVL tree.
*
* Return: A pointer to the newly inserted node, or NULL on failure.
*/

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = avl_insert_helper(tree, NULL, value);

	if (new_node)
		avl_balance(tree, value);

	return (new_node);
}
