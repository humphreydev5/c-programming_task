#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodePtr;

// struct defn and typedef below are 
//broken into two parts for clarity of explaining
// in our code we would usually combine the two list together
struct node
{
  /* data */
  int data;
  nodePtr next;
  //nodePtr data;
};
 /*call a struct node a node*/
 typedef struct node node;

int main (int argc, const char * argv[]){
  nodePtr first = NULL;

  //create the first pointer using malloc
  first = malloc (sizeof (node));
  first ->next = NULL;

  //Don't try this at home
  //node firstNode;
  //firstNode.next;


  // insert code here....
  first->data = 61;

  //first->next = malloc (sizeof (node));
  //(first->next)->next = NULL;
  //(first->next)->data =  62;

  nodePtr temp;
  temp = malloc (sizeof (node));
  temp->next = first;
  first = temp;


  printf("Hello Nigeria\n");
  return 0;
}
 