#include "binary_trees.h"

/* Task 17. Sibling */

/**
  * binary_tree_sibling - Finds the sibling of a node
  *
  * @node: Pointer to the node to find the sibling of
  *
  * Return: Pointer to the sibling node, or NULL if node is NULL,
  * the parent is NULL, or the node has no sibling
  */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
