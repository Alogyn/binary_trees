#include "binary_trees.h"

/* Task 19. Lowest common ancestor (Advanced) */

/**
  * tree_depth - Measures the depth of a node in a binary tree
  *
  * @tree: Pointer to the node to measure the depth
  *
  * Return: If tree is NULL, your function must return 0, else return depth
  */

size_t tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

/**
  * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
  *
  * @first: Pointer to the first node
  * @second: Pointer to the second node
  *
  * Return: Pointer to the lowest common ancestor node of the two given nodes
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t depth_first = tree_depth(first), depth_second = tree_depth(second);
	const binary_tree_t *deeper = depth_first > depth_second ? first : second;
	const binary_tree_t *shallower = depth_first > depth_second ? second : first;
	size_t depth_diff = depth_first > depth_second ?
		depth_first - depth_second : depth_second - depth_first;

	/* Equalize the depth of deeper node */
	while (depth_diff--)
		deeper = deeper->parent;

	/* Now move both nodes up until we find a common ancestor */
	while (deeper && shallower && deeper != shallower)
	{
		deeper = deeper->parent;
		shallower = shallower->parent;
	}

	/* Cast is safe because deeper == shallower or NULL */
	return ((binary_tree_t *)(deeper));
}
