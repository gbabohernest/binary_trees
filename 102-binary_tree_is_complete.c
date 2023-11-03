#include "binary_trees.h"

/**
* binary_tree_is_complete - Checks if a binary tree is complete
* @tree: A pointer to the root node of the tree to check
* Return: 0, if tree is NULL | not complete, otherwise 1
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int front, rear, null_flag;
	binary_tree_t *queue[5000], *current_node;

	if (tree == NULL)
		return (0);

	front = 0;
	rear = 0;
	null_flag = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current_node = queue[front++];

		if (current_node == NULL)
		{
			null_flag = 1;
		}
		else
		{
			if (null_flag)
				return (0); /*tree is not complete*/
			queue[rear++] = current_node->left;
			queue[rear++] = current_node->right;
		}
	}
	return (1); /*tree is complete*/
}
