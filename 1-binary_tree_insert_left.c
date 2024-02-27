#include "binary_trees.h"

/* Task 1. Insert left */

/**
  * binary_tree_insert_left - Inserts a node as the left-child of another node
  *
  * @parent: Pointer to the node to insert the left-child in
  * @value: The value to store in the new node
  * Return: Pointer to the created node, or NULL on failure or if parent is NULL
  */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	
	if (parent == NULL)
		return (NULL);
	
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	
	new_node->n = value;
	new_node->parent = parent;
	/* Set the new node's left child to parent's current left child */
	new_node->left = parent->left;
	new_node->right = NULL;
	
	if (parent->left != NULL)
	{
		/* Set the parent of the old left child to the new node */
		parent->left->parent = new_node;
	}
	
	/* Finally, set the parent's left child to the new node */
	parent->left = new_node;
	
	return (new_node);
}
