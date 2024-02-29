#include "binary_trees.h"

/* Task 20. Level-order traversal (Advanced) */

/**
  * binary_tree_levelorder - Goes through a binary tree
  * using level-order traversal
  *
  * @tree: Pointer to the root node of the tree to traverse
  * @func: Pointer to a function to call for each node
  *
  * Return: None
  */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	int front = 0, rear = 0, queue_size = 1024;

	if (!tree || !func)
		return;
	/* Allocate memory for the queue */
	queue = malloc(queue_size * sizeof(*queue));
	if (!queue)
		return;
	/* Enqueue the root */
	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		func(current->n);
		if (current->left)
		{
			if (rear >= queue_size)
			{
				queue_size *= 2;
				queue = realloc(queue, queue_size * sizeof(*queue));
				if (!queue)
					return;
			}
			queue[rear++] = current->left;
		}
		if (current->right)
		{
			if (rear >= queue_size)
			{
				queue_size *= 2;
				queue = realloc(queue, queue_size * sizeof(*queue));
				if (!queue)
					return;
			}
			queue[rear++] = current->right;
		}
	}
	free(queue);
}
