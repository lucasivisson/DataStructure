#include "splay.h"
#include <stdio.h>
#include <stdlib.h>

Node* create_node(int key) {
  Node* node = (Node*)malloc(sizeof(Node));
  if(node != NULL) {
    node->key = key;
    node->left = NULL;
    node->right = NULL;
  }
  return node;
}

Node* right_rotate(Node* x) {
  Node* y = x->left;
  x->left = y->right;
  y->right = x;
  return y;
}

Node* left_rotate(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  y->left = x;
  return y;
}

Node* splay(Node* root, int key) {
  if (root == NULL || root->key == key) {
    return root;
  }

  if (root->key > key) {
    if (root->left == NULL) {
      return root;
    }
    if (root->left->key > key) {
      root->left->left = splay(root->left->left, key);
      root = right_rotate(root);
    }
    else if (root->left->key < key) {
      root->left->right = splay(root->left->right, key);
      if (root->left->right != NULL) {
        root->left = left_rotate(root->left);
      }
    }

    return (root->left == NULL) ? root : right_rotate(root);
  }
  else {
    if (root->right == NULL) {
      return root;
    }
    if (root->right->key > key) {
      root->right->left = splay(root->right->left, key);
      if (root->right->left != NULL) {
          root->right = right_rotate(root->right);
      }
    }
    else if (root->right->key < key) {
      root->right->right = splay(root->right->right, key);
      root = left_rotate(root);
    }

    return (root->right == NULL) ? root : left_rotate(root);
  }
}

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