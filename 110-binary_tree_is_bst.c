#include "binary_trees.h"

/* Task 24. Is BST (Advanced) */

/**
  * bst_helper - Recursively checks if a binary tree is a valid BST
  *
  * @tree: Pointer to the root node of the tree to check
  * @min: Minimum value a node's key can have
  * @max: Maximum value a node's key can have
  *
  * Return: 1 if tree is a valid BST, and 0 otherwise
  */

int bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	/* Check if the current node's value violates the min/max constraint */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Recursively check the left and right subtrees */
	/* with updated constraints */
	return (bst_helper(tree->left, min, tree->n) &&
			bst_helper(tree->right, tree->n, max));
}

/**
  * binary_tree_is_bst - Checks if a binary tree is a valid BST
  *
  * @tree: Pointer to the root node of the tree to check
  *
  * Return: 1 if tree is a valid BST, and 0 otherwise
  */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_helper(tree, INT_MIN, INT_MAX));
}
