#include "binary_trees.h"

/* Task 18. Uncle */

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

	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}

/**
  * binary_tree_uncle - finds the uncle of a node
  * @node: pointer to the node to find the uncle of
  *
  * Return: pointer to the uncle node, or NULL if node is NULL or has no uncle
  */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* The uncle of a node is the sibling of the node's parent */
	return (binary_tree_sibling(node->parent));
}
