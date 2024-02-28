#include "binary_trees.h"

/* Task 14. Balance factor */

/**
  * binary_tree_height - Measures the height of a binary tree
  *
  * @tree: Pointer to the root node of the tree to measure the height
  *
  * Return: The height of the tree, If tree is NULL, height is 0
  */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return ((left_height > right_height) ? left_height : right_height);
}

/**
  * binary_tree_balance - Measures the balance factor of a binary tree
  *
  * @tree: Pointer to the root node of the tree to measure the balance factor
  *
  * Return: The balance factor, If tree is NULL, return 0
  */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Calculate heights of left and right subtrees */
	left_height = tree->left ? (int)binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? (int)binary_tree_height(tree->right) + 1 : 0;

	/* Balance factor is left height minus right height */
	return (left_height - right_height);
}
