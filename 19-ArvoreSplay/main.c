#include "splay.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node* root = create_node(10);
  root->left = create_node(4);
  root->left->left = create_node(2);
  root->left->left->left = create_node(1);
  root->left->left->right = create_node(3);
  root->left->right = create_node(6);
  root->left->right->left = create_node(5);
  root->left->right->right = create_node(8);
  root->left->right->right->left = create_node(7);
  root->left->right->right->right = create_node(9);
  root->right = create_node(11);
  root->right->right = create_node(12);
  root->right->right->right = create_node(13);

  printf("pre order, in order and pos order traversal of the splay tree without search: \n");
  pre_order(root);
  printf("\n");
  in_order(root);
  printf("\n");
  pos_order(root);
  printf("\n");

  printf("pre order, in order and pos order traversal of the splay tree after search 3: \n");
  root = splay(root, 3);
  pre_order(root);
  printf("\n");
  in_order(root);
  printf("\n");
  pos_order(root);
  printf("\n");

  printf("pre order, in order and pos order traversal of the splay tree after search 9: \n");
  root = splay(root, 9);
  pre_order(root);
  printf("\n");
  in_order(root);
  printf("\n");
  pos_order(root);
  printf("\n");

  printf("pre order, in order and pos order traversal of the splay tree after search 1: \n");
  root = splay(root, 1);
  pre_order(root);
  printf("\n");
  in_order(root);
  printf("\n");
  pos_order(root);
  printf("\n");

  printf("pre order, in order and pos order traversal of the splay tree after search 5: \n");
  root = splay(root, 5);
  pre_order(root);
  printf("\n");
  in_order(root);
  printf("\n");
  pos_order(root);
  printf("\n");

  return 0;
}