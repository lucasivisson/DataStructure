#include <stdio.h>
#include <stdlib.h>
#include "arvore_rb.h"

/* 
A função minimum recebe um ponteiro para o nó e retorna o nó com o menor valor na subárvore com raiz nesse nó. A implementação é uma busca iterativa pelo filho esquerdo até encontrar um nó que não tenha filho esquerdo.
*/
Node *minimumNode(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/*
A função findNode recebe um ponteiro para o nó raiz da árvore e o valor a ser buscado na árvore, e retorna o ponteiro para o nó que contém o valor buscado. A implementação é uma busca recursiva na árvore, comparando o valor desejado com o valor do nó atual, e continuando a busca recursivamente no filho esquerdo ou direito, dependendo do valor.*/
Node *findNode(Node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return findNode(root->left, key);
    } else {
        return findNode(root->right, key);
    }
}

/*
A função transplant substitui a subárvore enraizada no nó u pela subárvore enraizada no nó v, mantendo as propriedades da árvore rubro-negra. A implementação verifica se o nó u é a raiz da árvore e atualiza a raiz da árvore, se necessário. Em seguida, atualiza o pai do nó v para apontar para o pai de u.*/
void transplant(Node **root, Node *u, Node *v) {
    if (u->parent == NULL) {
        *root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}


Node *createNode(int key) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->color = RED;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void leftRotate(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void insertFixup(Node **root, Node *z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node *y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                // Caso 1: o tio é vermelho
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    // Caso 2: o tio é preto e z é filho à direita
                    z = z->parent;
                    leftRotate(root, z);
                }
                // Caso 3: o tio é preto e z é filho à esquerda
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node *y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                // Caso 1: o tio é vermelho
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    // Caso 2: o tio é preto e z é filho à esquerda
                    z = z->parent;
                    rightRotate(root, z);
                }
                // Caso 3: o tio é preto e z é filho à direita
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void insertRb(Node **root, int key) {
    // Cria um novo nó
    Node *z = createNode(key);

    // Insere o nó como uma árvore binária de busca
    Node *y = NULL;
    Node *x = *root;
    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NULL) {
        *root = z; // a árvore estava vazia
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    // Corrige as propriedades da árvore rubro-negra
    insertFixup(root, z);
}

void deleteFixup(Node **root, Node *x, Node *x_parent) {
    while (x != *root && (x == NULL || x->color == BLACK)) {
        if (x == x_parent->left) {
            Node *w = x_parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x_parent->color = RED;
                leftRotate(root, x_parent);
                w = x_parent->right;
            }
            if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK)) {
                w->color = RED;
                x = x_parent;
                x_parent = x->parent;
            } else {
                if (w->right == NULL || w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x_parent->right;
                }
                w->color = x_parent->color;
                x_parent->color = BLACK;
                if (w->right != NULL) {
                    w->right->color = BLACK;
                }
                leftRotate(root, x_parent);
                x = *root;
                x_parent = NULL;
            }
        } else {
            Node *w = x_parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x_parent->color = RED;
                rightRotate(root, x_parent);
                w = x_parent->left;
            }
            if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK)) {
                w->color = RED;
                x = x_parent;
                x_parent = x->parent;
            } else {
                if (w->left == NULL || w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(root, w);
                    w = x_parent->left;
                }
                w->color = x_parent->color;
                x_parent->color = BLACK;
                if (w->left != NULL) {
                    w->left->color = BLACK;
                }
                rightRotate(root, x_parent);
                x = *root;
                x_parent = NULL;
            }
        }
    }
    if (x != NULL) {
        x->color = BLACK;
    }
}

void deleteRb(Node **root, int key) {
    // Encontra o nó a ser removido
    Node *z = findNode(*root, key);
    if (z == NULL) {
        return;
    }

    Node *y = z;
    Color y_original_color = y->color;
    Node *x, *x_parent;

    if (z->left == NULL || z->right == NULL) {
        // Caso 1: z tem no máximo um filho
        x = (z->left == NULL) ? z->right : z->left;
        x_parent = z->parent;
        transplant(root, z, x);
    } else {
        // Caso 2: z tem dois filhos
        y = minimumNode(z->right);
        y_original_color = y->color;
        x = y->right;
        x_parent = y;
        if (y->parent == z) {
            x_parent = y;
        } else {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == BLACK) {
        deleteFixup(root, x, x_parent);
    }
    free(z);
}

Node *search(Node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}