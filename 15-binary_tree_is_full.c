#include "binary_trees.h"

/* Task 15. Is full */

/**
  * binary_tree_is_full - Checks if a binary tree is full
  *
  * @tree: Pointer to the root node of the tree to check
  *
  * Return: 1 if tree is full, 0 otherwise or if tree is NULL
  */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Leaf node */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If both left and right children exist, check if they are full */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If it's neither a leaf node nor a node with two children, it's not full */
	return (0);
}
