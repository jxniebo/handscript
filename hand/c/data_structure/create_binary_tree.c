#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INDEX 80
#define POS ' '
#define MOD '_'
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct node {
  int value;
  struct node* lchild;
  struct node* rchild;
  struct node* parent;
  int lsize;
  int rsize;
  int ldepth;
  int rdepth;
}Node;

void tree_print(Node* head, char** string_stack, int depth, int location) {
  //use location to put the node
  // should modify location if has children to fill location
  if(head) {
    if(head->parent) {
      if(head == head->parent->rchild) {
        for(int i = 0; i < head->lsize; i++) {
          *(*(string_stack + depth + 1) + location++) = MOD;
          *(*(string_stack + depth + 1) + location++) = MOD;
        }
      } else {
        for(int i = 0; i < head->rsize; i++) {
          *(*(string_stack + depth + 1) + location--) = MOD;
          *(*(string_stack + depth + 1) + location--) = MOD;
        }
      }
    }
    int value = head->value;
    *(*(string_stack + depth) + location) = (value / 10) > 0 ? (value / 10) + '0' : (value % 10) + '0';
    *(*(string_stack + depth) + location + 1) = value / 10 > 0 ? value % 10 + '0' : ' ';
    if(head->lchild) {
      *(*(string_stack + depth - 1) + location - 1) = '/';
      tree_print(head->lchild, string_stack, depth - 2, location -  2);
    }
    if(head->rchild) {
      *(*(string_stack + depth - 1) + location + 1) = '\\';
      tree_print(head->rchild, string_stack, depth - 2, location +  2);
    }
  }
}



Node* create_node(int value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->parent = node->rchild = node->lchild = NULL;
  node->rdepth = node->ldepth = node->lsize = node->rsize = 0;
  return node;
}

void maintain_parent(Node* parent) {
  while(parent) {
    if(parent->lchild) {
      parent->lsize = 1 + parent->lchild->lsize + parent->lchild->rsize;
      parent->ldepth = MAX(parent->lchild->ldepth, parent->lchild->rdepth) + 1;
    }
    if(parent->rchild) {
      parent->rsize = 1 + parent->rchild->lsize + parent->rchild->rsize;
      parent->rdepth = MAX(parent->rchild->ldepth, parent->rchild->rdepth) + 1;
    }
    parent = parent->parent;
  }

}

Node* create_binary_tree(int* array, int length) {
  Node* head = NULL;
  int left = length;

  while(left > 0) {
    Node** travel = &head;
    Node* parent = *travel;
    int is_right;
    int value = array[length - left];

    //append new node to current tree
    while(*travel != NULL) {
      parent = *travel;
      if(value < (*travel)->value) {
        is_right = 0;
        travel = &((*travel)->lchild);
      }
      else {
        is_right = 1;
        travel = &((*travel)->rchild);
      }
    }
    *travel = create_node(value);

    //maintain parent
    (*travel)->parent = parent;
    if(parent != NULL) {
      if(is_right == 1) {
        parent->rchild = *travel;
      } else {
        parent->lchild = *travel;
      }
    }

    //maintain size and depth
    maintain_parent(parent);
    left--;
  }

  return head;
}

int main(int argc, char** argv) {
  srand((unsigned)time(NULL));

  int size = 0;
  if(argc > 1) {
    char* count = *(argv + 1);
    char arg;
    while((arg = *count++) != '\0') {
      size = size * 10 + (arg - '0');
    }
  }
  size = size > 0 ? size : INDEX;
  int* array = (int*)malloc(sizeof(int)*size);
  for(int i = 0; i < size; i++) {
    array[i] = rand() % size;
    printf("%d ", array[i]);
  }
  printf("\n");
  Node* root = create_binary_tree(array, size);
  int width = (root->rsize + root->lsize + 1) * 2 + 1;
  int depth = 2 * MAX(root->rdepth, root->ldepth) + 1;
  char** string_stack = (char**)malloc(sizeof(char*)*depth);
  for(int i = 0; i < depth; i++) {
    *(string_stack + i) = (char*)malloc(sizeof(char)*width);
    char* stack = *(string_stack + i);
    *(stack + width - 1) = '\0';
    for(int i = 0; i < width - 1; i++) {
      *(stack + i) = POS;
    }
  }
  int root_location = root->lsize * 2;
  tree_print(root, string_stack, depth - 1, root_location) ;
  for(int i = depth - 1; i >= 0; i--) {
    printf("%s\n", *(string_stack + i));
  }

  for(int i = 0; i < depth; i++) {
    free(*(string_stack + i));
  }
  free(string_stack);

  return 0;
}
