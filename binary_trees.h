#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Standard libreries */
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>


/* Data structures & types */

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

/* Basic Binary Tree */
typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

/* Print function */
void binary_tree_print(const binary_tree_t *);

/* Task 0. New node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Task 1. Insert left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Task 2. Insert right */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* Task 3. Delete */
void binary_tree_delete(binary_tree_t *tree);

/* Task 4. Is leaf */
int binary_tree_is_leaf(const binary_tree_t *node);

/* Task 5. Is root */
int binary_tree_is_root(const binary_tree_t *node);

/* Task 6. Pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/* Task 7. In-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* Task 8. Post-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Task 9. Height */
size_t binary_tree_height(const binary_tree_t *tree);

/* Task 10. Depth */
size_t binary_tree_depth(const binary_tree_t *tree);

/* Task 11. Size */
size_t binary_tree_size(const binary_tree_t *tree);

/* Task 12. Leaves */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* Task 13. Nodes */
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Task 4. Balance factor */
int binary_tree_balance(const binary_tree_t *tree);

/* Task 15. Is full */
int binary_tree_is_full(const binary_tree_t *tree);

/* Task 16. Is perfect */
int binary_tree_is_perfect(const binary_tree_t *tree);

/* Task 17. Sibling */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* Task 18. Uncle */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Task 19. Lowest common ancestor (Advanced) */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);

/* Task 20. Level-order traversal (Advanced) */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/* Task 21. Is complete (Advanced) */
int binary_tree_is_complete(const binary_tree_t *tree);

/* Task 22. Rotate left (Advanced) */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* Task 23. Rotate right (Advanced) */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* Task 24. Is BST (Advanced) */
int binary_tree_is_bst(const binary_tree_t *tree);

/* Task 25. BST - Insert (Advanced) */
bst_t *bst_insert(bst_t **tree, int value);

/* Task 26. BST - Array to BST (Advanced) */
bst_t *array_to_bst(int *array, size_t size);

/* Task 27. BST - Search (Advanced) */
bst_t *bst_search(const bst_t *tree, int value);

/* Task 28. BST - Remove (Advanced) */
bst_t *bst_remove(bst_t *root, int value);

/* Task 30. Is AVL (Advanced) */
int binary_tree_is_avl(const binary_tree_t *tree);

/* Task 31. AVL - Insert (Advanced) */
avl_t *avl_insert(avl_t **tree, int value);

/* Task 32. AVL - Array to AVL (Advanced) */
avl_t *array_to_avl(int *array, size_t size);

/* Task 33. AVL - Remove (Advanced) */
avl_t *avl_remove(avl_t *root, int value);

/* Task 34. AVL - From sorted array (Advanced) */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Task 36. Is Binary heap (Advanced) */
int binary_tree_is_heap(const binary_tree_t *tree);

/* Task 37. Heap - Insert (Advanced) */
heap_t *heap_insert(heap_t **root, int value);

/* Task 38. Heap - Array to Binary Heap (Advanced) */
heap_t *array_to_heap(int *array, size_t size);

/* Task 39. Heap - Extract (Advanced) */
int heap_extract(heap_t **root);

/* Task 40. Heap - Sort (Advanced) */
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* BINARY_TREES_H */
