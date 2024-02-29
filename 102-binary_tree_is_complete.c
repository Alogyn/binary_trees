#include "binary_trees.h"

/* Task 21. Is complete (Advanced) */

int enqueue_node(binary_tree_t ***queue, int *rear, int *queue_size,
		const binary_tree_t *node);

/**
  * process_node - Process a node during traversal
  *
  * @current: Current node being processed
  * @queue: Pointer to the queue
  * @rear: Rear index of the queue
  * @queue_size: Size of the queue
  * @node_missing_children: Flag indicating if a node missing children
  *                         has been encountered
  *
  * Return: 1 if successful, 0 if a non-complete condition is detected
  */

int process_node(const binary_tree_t *current, binary_tree_t ***queue,
		int *rear, int *queue_size, int *node_missing_children)
{
	if (!current->left || !current->right)
	{
		if (!current->left && current->right)
			return (0);
		*node_missing_children = 1;
	}
	else if (*node_missing_children)
		return (0);

	if (current->left)
		if (!enqueue_node(queue, rear, queue_size, current->left))
			return (0);

	if (current->right)
		if (!enqueue_node(queue, rear, queue_size, current->right))
			return (0);

	return (1);
}

/**
  * enqueue_node - Enqueue a node into the queue
  *
  * @queue: Pointer to the queue
  * @rear: Pointer to the rear index of the queue
  * @queue_size: Pointer to the size of the queue
  * @node: Node to be enqueued
  *
  * Return: 1 if successful, 0 on failure
  */

int enqueue_node(binary_tree_t ***queue, int *rear, int *queue_size,
		const binary_tree_t *node)
{
	if (*rear >= *queue_size)
	{
		*queue_size *= 2;
		*queue = realloc(*queue, *queue_size * sizeof(**queue));
		if (!*queue)
			return (0);
	}
	(*queue)[(*rear)++] = (binary_tree_t *)node;

	return (1);
}

/**
  * binary_tree_is_complete - Checks if a binary tree is complete
  *
  * @tree: Pointer to the root node of the tree to check
  *
  * Return: 1 if tree is complete, 0 otherwise
  */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	int front = 0, rear = 0, queue_size = 1024, node_missing_children = 0;

	if (!tree)
		return (0);

	queue = malloc(queue_size * sizeof(*queue));
	if (!queue)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		if (!process_node(current, &queue, &rear, &queue_size,
					&node_missing_children))
		{
			free(queue);
			return (0);
		}
	}

	free(queue);
	return (1);
}
