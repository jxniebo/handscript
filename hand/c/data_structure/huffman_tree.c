#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INDEX 26

#define MAX(x, y) ((x) > (y)? (x): (y))

typedef struct node {
  double weight;
  char* contains;
  int lsize;
  int rsize;
  int hdepth;
  struct node* lchild;
  struct node* rchild;
  struct node* parent;
}Node;


void prepare_stack_content(Node* head, char** string_stack, int depth, int location) {
  if(head) {
    char* node_line = string_stack[depth * 2];
    if(head->parent) {
      char* point_line = string_stack[depth * 2 + 1];
      if(head == head->parent->rchild) {
        point_line[location - 1] = '\\';
        for(int i = 0; i < head->lsize; i++) {
          point_line[location++] = '_';
          point_line[location++] = '_';
        }
      }
      if(head == head->parent->lchild) {
        point_line[location + 1] = '/';
        for(int i = 0; i < head->rsize; i++) {
          point_line[location--] = '_';
          point_line[location--] = '_';
        }
      }
    }
    node_line[location] = head->hdepth == 0? *head->contains : '@';
    if(head->lchild)
      prepare_stack_content(head->lchild, string_stack, depth - 1, location - 2);
    if(head->rchild)
      prepare_stack_content(head->rchild, string_stack, depth - 1, location + 2);
  }
}

// print a tree of which all nodes maintain rsize lsize hdepth parent
void tree_print(Node* head) {
  int stack_depth = head->hdepth * 2 + 1;
  int stack_width = (head->lsize + head->rsize + 1) * 2 + 1;
  char** string_stack = (char**)malloc(sizeof(char*) * stack_depth);

  for(int i = 0; i < stack_depth; i++) {
    string_stack[i] = (char*)malloc(sizeof(char) * stack_width);
    for(int j = 0; j < stack_width; j++) {
      string_stack[i][j] = ' ';
    }
    string_stack[i][stack_width - 1] = '\0';
  }
  int location_for_head = 2 * head->lsize;
  prepare_stack_content(head, string_stack, head->hdepth, location_for_head);

  for(int i = stack_depth - 1; i >= 0; i--) {
    printf("%s\n", string_stack[i]);
    free(string_stack[i]);
  }
  free(string_stack);
}


void adjust_nodes(Node** nodes, int min, int min_step, int size) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->weight = nodes[min]->weight + nodes[min_step]->weight;
  new_node->lchild = nodes[min];
  new_node->rchild = nodes[min_step];
  new_node->hdepth = MAX(new_node->lchild->hdepth, new_node->rchild->hdepth) + 1;
  new_node->lsize = new_node->lchild->lsize + new_node->rchild->rsize + 1;
  new_node->rsize = new_node->rchild->lsize + new_node->lchild->rsize + 1;
  new_node->lchild->parent = new_node->rchild->parent = new_node;
  int contain_size = 0;
  char* contains = nodes[min]->contains;
  while(*contains++ != '\0')
    contain_size++;
  contains = nodes[min_step]->contains;
  while(*contains++ != '\0')
    contain_size++;
  new_node->contains = (char*)malloc(sizeof(char) * contain_size + 1);
  contains = nodes[min]->contains;
  while((*new_node->contains++ = *contains++) != '\0')
    ;
  new_node->contains--;
  contains = nodes[min_step]->contains;
  while((*new_node->contains++ = *contains++) != '\0')
    ;
  new_node->contains -= contain_size + 1;
  if(min == size - 1) {
    nodes[min_step] = new_node;
  } else {
    nodes[min_step] = nodes[size - 1];
    nodes[min] = new_node;
  }
}

Node* make_huffman_tree(Node** nodes, int size) {
  if(size <= 0) return NULL;
  if(size == 1) return nodes[0];

  int min, min_step;
  if(nodes[0]->weight < nodes[1]->weight) {
    min = 0;
    min_step = 1;
  } else {
    min = 1;
    min_step = 0;
  }

  for(int i = 2; i < size; i++) {
    if(nodes[i]->weight < nodes[min]->weight) {
      min_step = min;
      min = i;
    } else if(nodes[i]->weight < nodes[min_step]->weight) {
      min_step = i;
    }
  }
  adjust_nodes(nodes, min, min_step, size);
  return make_huffman_tree(nodes, size - 1);
}

void tree_free(Node* head) {
  if(head->lchild)
    tree_free(head->lchild);
  if(head->rchild)
    tree_free(head->rchild);
  free(head);
}


void nodes_initial(Node** nodes, int size) {
  printf("begin initiate nodes:\n");

  for(int i = 0; i < size; i++) {
    nodes[i] = (Node*)malloc(sizeof(Node));
  }
  double sum = 0;
  for(int i = 0; i < size; i++) {
    nodes[i]->weight = (double)(rand() % size * i);
    sum += nodes[i]->weight;
    nodes[i]->contains = (char*)malloc(sizeof(char) * 2);
    *nodes[i]->contains = 'a' + i;
    *(nodes[i]->contains + 1) = '\0';
    nodes[i]->lchild = nodes[i]->rchild = nodes[i]->parent = NULL;
    nodes[i]->hdepth = nodes[i]->lsize = nodes[i]->rsize = 0;
  }
  for(int i = 0; i < size; i++) {
    nodes[i]->weight /= sum;
    printf("Nodes[%d] has weight %f contains %s\n", i, nodes[i]->weight, nodes[i]->contains);
  }
}


int main(int argc, char** argv) {
  srand((unsigned)(time(NULL)));

  Node* nodes[INDEX];
  nodes_initial(nodes, INDEX);

  Node* debug = make_huffman_tree(nodes, INDEX);
  //  printf("%s\n", debug->contains);

  tree_print(debug);
  tree_free(debug);

  return 0;
}
