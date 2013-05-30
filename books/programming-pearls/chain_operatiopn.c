#include <stdio.h>
#include <stdlib.h>

typedef struct Node {int value; Node* next;};

Node* make_chain_recursive(int* values, int length) {
  if(length <= 0) return NULL;
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = *values;
  node->next = make_chain_recursive(++values, --length);
  return node;
}

Node* make_chain_iterate(int* values, int length) {
  if(length <= 0) return NULL;
  Node* node = (Node*)malloc(sizeof(Node));
  Node* head = node;
  for(int i = 1; i < length; i++) {
    node->value = *(values++);
    node->next = (Node*)malloc(sizeof(Node));
    node = node->next;
  }
  node->value = *values;
  node->next = NULL;
  return head;
}

Node* make_chain_sec_pointer(int* values, int length) {
  Node* head;
  Node** traveler = &head;
  while(--length >= 0) {
    *traveler = (Node*)malloc(sizeof(Node));
    (*traveler)->value = *(values++);
    traveler = &(*traveler)->next;
  }
  *traveler = NULL;
  return head;
}

void print_chain(Node* head) {
  while(head != NULL) {
    printf("%d->", head->value);
    head = head->next;
  }
  printf("NULL\n");
}

Node* chain_invert(Node* head) {
  if(head == NULL) return head;
  Node* prev = NULL;
  while(head->next != NULL) {
    Node* tmp = head->next;
    head->next = prev;
    prev = head;
    head = tmp;
  }
  head->next = prev;
  return head;
}

Node* chain_append(Node* head, Node* node) {
  if(!head) {
    return node;
  }
  Node* node_traveler = head;
  while(node_traveler->next) {
    node_traveler = node_traveler->next;
  }
  node_traveler->next = node;
  return head;
 }

void delete_chain(Node** node, int value) {
  Node* delete;
  while(*node !=NULL){
    if((*node)->value == value){
      delete = *node;
      *node = delete->next;
      free(delete);
    } else node = &((*node)->next);
  }
}

Node* delete_chain_v2(Node* head, int value) {
  Node* curr = head;
  Node* prev = NULL;
  while(curr) {
    if(curr->value == value) {
      if(!prev) {
        head = curr->next;
      } else {
        prev->next = curr->next;
      }
      free(curr);
    } else {
      prev = curr;
    }
    curr = prev? prev->next : head? head->next : NULL;
  }
  return head;
}


int main() {
  int values[] = {1, 3, 5, 6, 2, 3, 8, 4};
  int length = sizeof(values) / sizeof(int);
  Node* head = make_chain_recursive(values, length);
  print_chain(head);
  free(head);
  head = make_chain_iterate(values, length);
  print_chain(head);
  free(head);
  head = make_chain_sec_pointer(values, length);
  head = chain_invert(head);
  print_chain(head);
  head = delete_chain_v2(head, 1);
  head = delete_chain_v2(head, 8);
  head = delete_chain_v2(head, 8);
  head = delete_chain_v2(head, 6);
  print_chain(head);
  delete_chain(&head, 4);
  delete_chain(&head, 2);
  delete_chain(&head, 5);
  print_chain(head);
  delete_chain(&head, 3);
  print_chain(head);

}
