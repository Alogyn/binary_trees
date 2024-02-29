#include "binary_trees.h"

/* Task 27. BST - Search (Advanced) */

/**
  * bst_search - Searches for a value in a Binary Search Tree
  *
  * @tree: Pointer to the root node of the BST to search
  * @value: The value to search in the tree
  *
  * Return: Pointer to the node containing a value equals to value
  *         If tree is NULL or if nothing is found, returns NULL
  */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}