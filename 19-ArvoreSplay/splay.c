#include "splay.h"
#include <stdio.h>
#include <stdlib.h>

/* Helper function that allocates a new node with the given key and
 NULL left and right pointers. */
Node* create_node(int key) {
  Node* node = (Node*)malloc(sizeof(Node));
  if(node != NULL) {
    node->key = key;
    node->left = NULL;
    node->right = NULL;
  }
  return node;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
Node* right_rotate(Node* x) {
  Node* y = x->left;
  x->left = y->right;
  y->right = x;
  return y;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node* left_rotate(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  y->left = x;
  return y;
}

// This function brings the key at root if key is present in tree.
// If key is not present, then it brings the last accessed item at
// root.  This function modifies the tree and returns the new root
Node* splay(Node* root, int key) {
   // Base cases: root is NULL or key is present at root
  if (root == NULL || root->key == key) {
    return root;
  }

  // Key lies in left subtree
  if (root->key > key) {
    // Key is not in tree, we are done
    if (root->left == NULL) {
      return root;
    }
    // Zig-Zig (Left Left)
    if (root->left->key > key) {
      // First recursively bring the key as root of left-left
      root->left->left = splay(root->left->left, key);

      // Do first rotation for root, second rotation is done after else
      root = right_rotate(root);
    }
    else if (root->left->key < key) { // Zig-Zag (Left Right)
      // First recursively bring the key as root of left-right
      root->left->right = splay(root->left->right, key);

      // Do first rotation for root->left
      if (root->left->right != NULL) {
        root->left = left_rotate(root->left);
      }
    }

    // Do second rotation for root
    return (root->left == NULL) ? root : right_rotate(root);
  }
  else {  // Key lies in right subtree

    // Key is not in tree, we are done
    if (root->right == NULL) {
      return root;
    }

    // Zag-Zig (Right Left)
    if (root->right->key > key) {
      // Bring the key as root of right-left
      root->right->left = splay(root->right->left, key);

      // Do first rotation for root->right
      if (root->right->left != NULL) {
          root->right = right_rotate(root->right);
      }
    }
    else if (root->right->key < key) {
      // Bring the key as root of right-right and do first rotation
      root->right->right = splay(root->right->right, key);
      root = left_rotate(root);
    }

    // Do second rotation for root
    return (root->right == NULL) ? root : left_rotate(root);
  }
}

// A utility function to create node and insert into the tree.
// The function also bring the predecessor of the inserted node to near of root of tree.
Node* insert(Node* root, int key) {
    if (root == NULL) {
      return create_node(key);
    }

    root = splay(root, key);

    if (root->key == key) {
      return root;
    }

    Node* new_node = create_node(key);

    if (root->key > key) {
      new_node->right = root;
      new_node->left = root->left;
      root->left = NULL;
    }
    else {
      new_node->left = root;
      new_node->right = root->right;
      root->right = NULL;
    }

    return new_node;
}

// A utility function to remove root node of the tree.
// The function also bring the predecessor of the removed node to the root of tree.
Node* remove_node(Node* root, int key) {
    if (root == NULL) {
      return NULL;
    }

    root = splay(root, key);

    if (root->key != key) {
      return root;
    }

    Node* left_subtree = root->left;
    Node* right_subtree = root->right;
    free(root);

    if (left_subtree == NULL) {
      return right_subtree;
    }

    left_subtree = splay(left_subtree, key);
    left_subtree->right = right_subtree;

    return left_subtree;
}

// A utility function to print inorder traversal of the tree.
// The function also prints height of every node
void in_order(Node* root) {
    if (root != NULL) {
      in_order(root->left);
      printf("%d ", root->key);
      in_order(root->right);
    }
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void pre_order(Node* root) {
    if (root != NULL) {
      printf("%d ", root->key);
      pre_order(root->left);
      pre_order(root->right);
    }
}

// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void pos_order(Node* root) {
    if (root != NULL) {
      pos_order(root->left);
      pos_order(root->right);
      printf("%d ", root->key);
    }
}