#include "binary_trees.h"

/* Task 2. Insert right */

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if the parent is NULL */
	if (parent == NULL)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node */
	new_node->n = value;
	new_node->parent = parent;
	/* Set the new node's right child to parent's current right child */
	new_node->right = parent->right;
	new_node->left = NULL;

	if (parent->right != NULL)
		/* Set the parent of the old right child to the new node */
		parent->right->parent = new_node;

	/* Set the parent's right child to the new node */
	parent->right = new_node;

	return (new_node);
}
