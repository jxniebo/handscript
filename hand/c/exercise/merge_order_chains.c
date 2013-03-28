#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;
}Node;

Node* node_create(Node* proto) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->value = proto->value;
  new_node->next = NULL;
  return new_node;
}

int node_compare(Node* node1, Node* node2) {
  return node1->value < node2->value ? -1 : 1;
}

//this function is used to create a new chain, which contains all the
//elements in chain1 and chain2. And the new chain is ordered
//while chain1&&chain2
//if comp(chain1, chain2) < 0
//create new node duplicate chain1
//chain1 = chain1->next
//else create new node duplicate chain2
//chain2 = chain2->next
//end while
//append left chain1 nodes to new chain
//append left chain2 nodes to new chain
//return new chain
//end function
//should keep Node* head, Node* traveler
//traveler used to keep the last element of new chain
Node* merge_order_chains(Node* chain1, Node* chain2) {
  Node* head = NULL;
  Node* traveler = NULL;
  if(chain1 || chain2) {
    if(chain1 && chain2) {
      if(node_compare(chain1, chain2) < 0) {
        head = node_create(chain1);
        chain1 = chain1->next;
      } else {
        head = node_create(chain2);
        chain2 = chain2->next;
      }
      traveler = head;
    }
    while(chain1 && chain2) {
      if(node_compare(chain1, chain2) < 0) {
        traveler->next = node_create(chain1);
        chain1 = chain1->next;
      } else {
        traveler->next = node_create(chain2);
        chain2 = chain2->next;
      }
      traveler = traveler->next;
    }
    while(chain1) {
      traveler->next = node_create(chain1);
      chain1 = chain1->next;
      traveler = traveler->next;
    }
    while(chain2) {
      traveler->next = node_create(chain2);
      chain2 = chain2->next;
      traveler = traveler->next;
    }
  }
  return head;
}

Node* merge_order_chains_v2(Node* chain1, Node* chain2) {
  Node* head = NULL;
  Node* traveler = NULL;
  if(chain1 || chain2) {
    if(node_compare(chain1, chain2) < 0) {
      head = chain1;
      chain1 = chain1->next;
    } else {
      head = chain2;
      chain2 = chain2->next;
    }
    traveler = head;

    while(chain1 && chain2) {
      if(node_compare(chain1, chain2) < 0) {
        traveler->next = chain1;
        chain1 = chain1->next;
      } else {
        traveler->next = chain2;
        chain2 = chain2->next;
      }
      traveler = traveler->next;
    }
    traveler->next = chain1? chain1 : chain2;
  }
  return head;
}

void node_print(Node* head) {
  while(head) {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("NULL\n");
}


int get_chain_length(Node* node) {
  int length = 0;
  //in case has loop
  if(!node) return length;
  if(!node->next) {
    length++;
    return length;
  }
  Node* p1 = node;
  Node* p2 = node->next;
  while(p2 && p1 != p2) {
    length ++;
    p1 = p1->next;
    p2 = p2->next;
    if(p2) {
      length++;
      p2 = p2->next;
    }
  }
  if(p2) {
    int length_circle = 1;
    Node* traveler = p2;
    while(traveler != p2) {
      traveler = traveler->next;
      length_circle++;
    }
    int length_revert = 1;
    Node* curr = node->next;
    Node* prev = node;
    while(curr != node) {
      length_revert++;
      Node* tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
      length = (length_revert - length_circle) / 2 + length_circle;
    }
  }

  return length;
}
//in case has loop


void test_merge() {
  Node* head1 = (Node*)malloc(sizeof(Node));
  Node* head2 = (Node*)malloc(sizeof(Node));
  Node* traveler1 = head1;
  Node* traveler2 = head2;
  for(int i = 0; i < 100; i += 2) {
    traveler1->value = i;
    traveler2->value = i + 1;
    traveler1->next = (Node*)malloc(sizeof(Node));
    traveler2->next = (Node*)malloc(sizeof(Node));
    traveler1 = traveler1->next;
    traveler2 = traveler2->next;
  }
  traveler1->value = 110;
  traveler2->value = 111;
  traveler1->next = NULL;
  traveler2->next = NULL;
  node_print(head1);
  node_print(head2);
  node_print(merge_order_chains(head1, head2));
  node_print(head1);
  node_print(merge_order_chains_v2(head1, head2));
  node_print(head2);
  while(head1) {
    Node* tmp = head1->next;
    free(head1);
    head1 = tmp;
  }
  while(head2) {
    Node* tmp = head2->next;
    free(head2);
    head2 = tmp;
  }
  free(NULL);
  head1 = head2 = traveler1 = traveler2 = NULL;
  printf("sdalfs\n");
}




int main() {
  test_merge();
  //  test_get_chain_length();
  return 0;
}
