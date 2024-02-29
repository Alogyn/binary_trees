#include "binary_trees.h"

/* Task 25. BST - Insert (Avanced) */

/**
  * bst_insert - Inserts a value in a Binary Search Tree
  *
  * @tree: Double pointer to the root node of the BST to insert the value
  * @value: The value to store in the node to be inserted
  *
  * Return: Pointer to the created node, or NULL on failure or if value exists
  */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current = NULL, *parent = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;

	while (current != NULL)
	{
		parent = current;

		if (value < current->n)
		{
			current = current->left;
			if (current == NULL)
			{
				parent->left = binary_tree_node(parent, value);
				return (parent->left);
			}
		}
		else if (value > current->n)
		{
			current = current->right;
			if (current == NULL)
			{
				parent->right = binary_tree_node(parent, value);
				return (parent->right);
			}
		}
		else
			return (NULL);
	}
	return (NULL);
}
