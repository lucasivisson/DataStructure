#include <stdio.h>
#include <stdlib.h>
#include "arvore_rb.h"

int main() {
  int ch, data;
  Node *root = NULL;

  while (1) {
    printf("1. Insertion\t2. Deletion\n");
    printf("3. Search\t4. Exit");
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("Enter the element to insert:");
        scanf("%d", &data);
        insertRb(&root, data);
        break;
      case 2:
        printf("Enter the element to delete:");
        scanf("%d", &data);
        deleteRb(&root, data);
        break;
      case 3:
        printf("Enter the element to insert:");
        scanf("%d", &data);
        Node *no = search(root, data);
        if(no == NULL) {
          printf("O no nao foi encontrado\n");
        } else {
          printf("O no foi encontrado\n");
        }
        break;
      case 4:
        exit(0);
      default:
        printf("Not available\n");
        break;
    }
    printf("\n");
  }
  return 0;
}