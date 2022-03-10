#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//Defining a variable(struct) as node_struct
struct node_struct
{
    int data;
    struct node_struct *next;
   
};
//Type redefinition as node
typedef struct node_struct node;
//Assigning start pointer variable as node
node* start;

//Addition from beginnig of Normal linked kist
void add_left(int value);
//Normal Linked list printer
void printList(node* current);

int main()
{
    int i;              //Dummy counting variable
    int value;          //Value has range 0 to 100
    start = NULL;        //Assiging as NULL at first
    srand(time(NULL));  //Using time function to create random values

    printf( "\nLINKED LIST PROGRAM\n\n" );

    for ( i = 0; i < 4  ; i++)
    {
        value = rand()%25; 
        
        add_left(value);
    }
    printList(start);

    return 0;
}
//Addition from beginnig of Normal linked kist
void add_left(int value)
{    
    node *new_node = (node*) malloc(sizeof(node)); //Allocating memory for a new node
    new_node->data = value;                        //Assigning entered value to new allocated node's data
    new_node->next = start;                         //Arranging start node as the next node of new node
    start = new_node;                               //Assigning (global)start node pointer as new node
}
//Normal Linked list printer
void printList(node* current)
{ 
    
   // if list is empty 
   if ( current == NULL ) {
      printf( "List is empty.\n" );
   } // end if 
   else { 
      printf( "The list is:\n" );

      // while not the end of the list 
      while ( current != NULL ) { 
         printf( "%d --> ", current->data );
         current = current->next;   
      } // end while 

      printf( "NULL\n" );
   } // end else 

} 