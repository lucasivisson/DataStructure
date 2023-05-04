#ifndef SPLAY_H
#define SPLAY_H

struct no {
  int key;
  struct no* left;
  struct no* right;
};

typedef struct no Node;

Node* create_node(int key);
Node* splay(Node* root, int key);
Node* insert(Node* root, int key);
Node* remove_node(Node* root, int key);
void pre_order(Node* root);
void in_order(Node* root);
void pos_order(Node* root);
#endif