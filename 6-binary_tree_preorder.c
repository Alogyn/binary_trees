#include "binary_trees.h"

/* Task 6. Pre-order traversal */

/**
  * binary_tree_preorder - Goes through a binary tree using pre-order traversal
  *
  * @tree: Pointer to the root node of the tree to traverse
  * @func: Pointer to a function to call for each node
  *        The value in the node must be passed as a parameter to this function
  *
  * Return: None
  */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Visit the root node */
	func(tree->n);

	/* Recursively traverse the left subtree */
	binary_tree_preorder(tree->left, func);

	/* Recursively traverse the right subtree */
	binary_tree_preorder(tree->right, func);
}
