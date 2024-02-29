#include "binary_trees.h"

/* Task 28. BST - Remove (Advanced) */

/**
  * bst_find_min - Finds the node with the minimum value in a BST
  *
  * @root: The root of the BST
  *
  * Return: The node with the minimum value
  */

bst_t *bst_find_min(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;

	return (root);
}

/**
  * bst_remove - Removes a node from a BST
  *
  * @root: The root of the BST
  * @value: The value to remove
  *
  * Return: The new root of the BST
  */

bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* Node with only one child or no child */
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		/* Node with two children: Get the in-order successor */
		bst_t *temp = bst_find_min(root->right);

		/* Copy the in-order successor's content to this node */
		root->n = temp->n;

		/* Delete the in-order successor */
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
