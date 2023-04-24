#ifndef RBTREE_H
#define RBTREE_H

#include <stddef.h>

// Create a red-black tree
struct rbNode *createNode(int);

// Insert an node
void insertion(int);

// Delete a node
void deletion(int);

// Print the inorder traversal of the tree
void inorderTraversal(struct rbNode *node);

#endif