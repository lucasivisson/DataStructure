#ifndef ARVORE_RB_H_INCLUDED
#define ARVORE_RB_H_INCLUDED

typedef enum {RED, BLACK} Color;

typedef struct Node {
    int key;
    Color color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

void leftRotate(Node **root, Node *x);
void rightRotate(Node **root, Node *y);
void insertFixup(Node **root, Node *z);
void insertRb(Node **root, int key);
void deleteFixup(Node **root, Node *x, Node *x_parent);
void deleteRb(Node **root, int key);
Node *search(Node *root, int key);

#endif // ARVORE_RB_H_INCLUDED