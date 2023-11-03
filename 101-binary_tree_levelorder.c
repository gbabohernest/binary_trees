#include "binary_trees.h"

/**
* binary_tree_levelorder - Goes through a binary tree
*			using level-order traversal
* @tree: A pointer to the root node of the tree
* @func: A pointer to a function to call for each node
*
* Description: if tree | func is NULL, do nothing
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *queue[5000], *current_node;
	int front, rear;

	if (tree == NULL || func == NULL)
		return;

	front = 0;
	rear = 0;
	queue[rear++] = tree;

	while (front < rear)
	{
		/*  dequeue front node & process it */
		current_node = queue[front++];
		func(current_node->n);

		/* enqueue left & right children node if they exists */
		if (current_node->left)
			queue[rear++] = current_node->left;
		if (current_node->right)
			queue[rear++] = current_node->right;
	}
}
