#include "binary_trees.h"

/* Task 22. Rotate left (Advanced) */

/**
  * binary_tree_rotate_left - Performs a left-rotation on a binary tree
  *
  * @tree: Pointer to the root node of the tree to rotate
  *
  * Return: Pointer to the new root node of the tree once rotated
  */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	tmp = pivot->left;
	pivot->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	return (pivot);
}
