// Student Id    : 040190030
// Name & Surname: Ömer Bahadır Gökmen
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
//Assigning root pointer variable as node
node* root;

//Addition from beginnig of linked kist
void add_left(int value);
//Addition from end of linked list
void add_end(node *ptr,int value);
//Prints linked list as odd and even numbers parted
void printList_OE(int number_even,int number_odd);
void printList();

int main()
{   
    int i;              //Dummy counting variable
    int nodeNumber;     //Given by user value to create linked list
    int odd=0,even=0;   //Variables to count odd and even values 
    int value;          //Value has range 0 to 100
    root = NULL;        //Assiging as NULL at first
    srand(time(NULL));  //Using time function to create random values

    printf( "\nLINKED LIST PROGRAM\n\n" );

    printf("Enter total counts of nodes in Linked List: ");
    scanf("%d",&nodeNumber);

    for ( i = 0; i < nodeNumber  ; i++)
    {
        value = rand()%100; 
        //If value is even 
        if (value % 2 == 0)
        {
            add_end(root,value); //Add new data from end to the linked list
            even++;              //Counting even numbers
        }
        //If value is odd
        else
        {
            add_left(value);     //Add new data from begining to the linked list
            odd++;               //Counting odd numbers
        }
    }
    printf("\n\n");
    printf("Count of ODD numbers:%d\nCount of EVEN numbers:%d \n\n\n",odd,even);
    printList_OE(even,odd);
    printList();
   
    return 0;
}
//Addition from beginnig of linked kist
void add_left(int value)
{    

    node *new_node = (node*) malloc(sizeof(node)); //Allocating memory for a new node
    new_node->data = value;                        //Assigning entered value to new allocated node's data
    new_node->next = root;                         //Arranging root node as the next node of new node
    root = new_node;                               //Assigning (global)root node pointer as new node
}
//Addition from end of linked list
void add_end(node *ptr,int value)
{
    //If linked list has been started before,it functions in here
    if (ptr != NULL)
    {
        //Pointer goes to end of linked list
        while(ptr->next != NULL){ptr = ptr->next;}

        ptr->next = (node*)malloc(sizeof(node)); //Allocating memory for null space which comes after the last node of linked list
        ptr->next->data = value;                 //Assigning entered value to new allocated node's data
        ptr->next->next= NULL;                   //Arranging the space ,which comes after the last allocated node, as null
    }
    //If linked list has not been started before, it functions in here 
    else
    {
        node *new_node = (node*) malloc(sizeof(node));  //Allocating memory for new node
        new_node->data = value;                         //Assigning entered value to new allocated node's data
        new_node->next = NULL;                          //Arranging the space ,which comes after the last allocated node, as null
        root = new_node;                                //Assigning new node to root 
    }
}
//Prints linked list as odd and even numbers parted
void printList_OE(int number_even,int number_odd)
{ 
    node* current = root;
    printf("LINKED LIST:\n\n");
    printf("ODD PART:");
    while ( number_odd > 0 )
    { 
        printf( "%d  ", current->data );
        current = current->next;
        number_odd--;   
    } // end while 

    printf("   ");
    
    printf("EVEN PART:");
    
    while ( current != NULL )
    { 
        printf( "%d   ", current->data );
        current = current->next;   
    } // end while 

    // end else 
    printf("\n\n");
} // end function printList 
void printList()
{ 
    node* current = root;
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

} // end function printList 