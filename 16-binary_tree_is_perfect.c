#include "binary_trees.h"

/* Task 16. Is perfect */

/**
  * binary_tree_depth - Measures the depth of a node in a binary tree
  *
  * @tree: Pointer to the node to measure the depth
  *
  * Return: The depth of the tree
  */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
  * is_perfect_recursive - Recursively checks if a binary tree is perfect
  *
  * @tree: Pointer to the root node of the tree to check
  * @depth: Depth of the current node
  * @level: Level of the current node
  *
  * Return: 1 if tree is perfect, 0 otherwise
  */

int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	/* Check leaf node */
	if (tree->left == NULL && tree->right == NULL)
		return ((depth == level + 1));

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
  * binary_tree_is_perfect - Checks if a binary tree is perfect
  *
  * @tree: Pointer to the root node of the tree to check
  *
  * Return: 1 if tree is perfect, 0 otherwise or if tree is NULL
  */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth = binary_tree_depth(tree);

	return (is_perfect_recursive(tree, depth, 0));
}
