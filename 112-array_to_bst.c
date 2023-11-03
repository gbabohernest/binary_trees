#include "binary_trees.h"

/**
* array_to_bst - Builds a Binary Search Tree from an array
* @array: A pointer to the first element of the array
* @size: Number of element in the array
*
* Return: pointer to the root node of the BST or NULL if failed
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	root = NULL;

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
