#include "binary_trees.h"

/* Task 30. Is AVL (Advanced) */

/**
  * isBSTUtil - utility function to check if binary tree is BST
  *
  * @tree: Pointer to the root node of the tree to check
  * @min: Minimum value
  * @max: MMaximum value
  *
  * Return: 1 if tree is a BST, otherwise 0
  */

int isBSTUtil(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (isBSTUtil(tree->left, min, tree->n - 1) &&
		isBSTUtil(tree->right, tree->n + 1, max));
}

/**
  * height - Measures the height of a binary tree
  *
  * @tree: Pointer to the root node of the tree to measure the height
  *
  * Return: The height of the tree
  */

int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
  * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
  *
  * @tree: pPinter to the root node of the tree to check
  *
  * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
  */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	if (abs(left_height - right_height) <= 1 &&
		isBSTUtil(tree, INT_MIN, INT_MAX) &&
		binary_tree_is_avl(tree->left) &&
		binary_tree_is_avl(tree->right))
		return (1);

	return (0);
}
