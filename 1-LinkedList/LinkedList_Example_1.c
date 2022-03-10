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
//Linked list maker function
void linkedlistmaker(int value);
//Normal Linked list printer
void printList(node* current);
//Deleting a node from beginning of a Normal Linked List and adding to the end of a Normal Linked List
node* delete_And_add(node* r);


int main()
{
    int i;              //Dummy counting variable
    int value;          //Value has range 0 to 100
    int nodeNumber;     //Given by user value to create linked list
    start = NULL;        //Assiging as NULL at first
    srand(time(NULL));  //Using time function to create random values

    printf( "\nLINKED LIST PROGRAM\n\n" );

    printf("Enter total counts of nodes in Linked List: ");
    scanf("%d",&nodeNumber);

    for ( i = 0; i < nodeNumber  ; i++)
    {
        value = rand()%25; 
        
        linkedlistmaker(value);
    }
    printf("Before deleting and adding operation:\n");
    printList(start);

    start = delete_And_add(start);
    printf("After deleting and adding operation:\n");
    printList(start);

    return 0;
}


//Deleting a node from a Normal Linked List
node* delete_And_add(node* r)
{
    node* temp;
    node* iter = r;
    if (r->next != NULL)
    {
        temp = r;
        r = r->next;
        while (iter->next != NULL )
        {
        iter = iter->next;
        }
    
        iter->next = (node*)malloc(sizeof(node)); //Allocating memory for null space which comes after the last node of linked list
        iter->next = temp;                 //Assigning entered value to new allocated node's data
        iter->next->next= NULL;                   //Arranging the space ,which comes after the last allocated node, as null
        return r;
        
    }
    else
    {
        return r;
    }
    
}

//Addition from beginnig of Normal linked kist
void linkedlistmaker(int value)
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