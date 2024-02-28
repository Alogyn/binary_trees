#include "binary_trees.h"

/* Tsk 5. Is root */

/**
  * binary_tree_is_root - Checks if a given node is the root of a binary tree
  *
  * @node: Pointer to the node to check
  *
  * Return: 1 if node is the root, otherwise 0.
  * If node is NULL, return 0
  */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}
