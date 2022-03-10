#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//Defining a variable(struct) as node_struct
struct node_struct
{
    int data;
    struct node_struct *next;
    struct node_struct *prev;
};
//Type redefinition as node
typedef struct node_struct node;
//Assigning root pointer variable as node
node* root;
//Addition from beginnig of Normal linked kist
void add_left(int value);
//Addition from beginnig of Circular linked kist
node* add_Cleft(node* r,int value);
//Addition from beginnig of Doubly linked kist
node* add_Dleft(node* r,int value);
//Addition from end of Normal linked list
void add_end(node *r,int value);
//Addition from end of Circular linked list
node* add_Cend(node* r,int value);
//Addition from end of Doubly linked list
void add_Dend(node *r,int value);
//Addition sequentially
node* add_seq(node *r,int value);
//Addition sequentially in Circular Linked List
node* add_Cseq(node *r,int value);
//Addition sequentially in Doubly Linked List
node* add_Dseq(node *r,int value);
//Deleting a node from a Normal Linked List
node* delete(node* r,int value);
//Deletin a node from a Circular Linked List
node* delete_CL(node* r,int value);
//Deleting a node from a Doubly Linked List
node* delete_D(node* r,int value);
//Normal Linked list printer
void printList(node* current);
//Circular Linked List printer
void printCList(node* current);
//Doubly Linked list printer
void printDList(node* current,int control);
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
        //value = rand()%100; 
        //printf("%d\n",value);
        root = add_Dseq(root,i);
    }
    root = delete_D(root,0);
    printDList(root,1);
    root = delete_D(root,1);
    printDList(root,1);
    root = delete_D(root,2);
    printDList(root,1);
    root = delete_D(root,4-1);
    printDList(root,1);
    root = delete_D(root,4+1);
    printDList(root,1);

    return 0;
}

//Addition from beginnig of Normal linked kist
void add_left(int value)
{    

    node *new_node = (node*) malloc(sizeof(node)); //Allocating memory for a new node
    new_node->data = value;                        //Assigning entered value to new allocated node's data
    new_node->next = root;                         //Arranging root node as the next node of new node
    root = new_node;                               //Assigning (global)root node pointer as new node
}
//Addition from beginnig of Circular linked kist
node* add_Cleft(node* r,int value)
{
    node* iter = r;
    if (r != NULL)
    {
        while(iter->next != r){iter = iter->next;}
        node *new_node = (node*) malloc(sizeof(node)); //Allocating memory for a new node
        new_node->data = value;                        //Assigning entered value to new allocated node's data
        new_node->next = r;                         //Arranging root node as the next node of new node
        iter->next = new_node;                               //Assigning (global)root node pointer as new node
        return new_node;
    }
    else
    {
        node *new_node = (node*) malloc(sizeof(node)); //Allocating memory for a new node
        new_node->data = value;                        //Assigning entered value to new allocated node's data
        new_node->next = new_node;                         //Arranging root node as the next node of new node
        return new_node;
    }
}
//Addition from beginnig of Doubly linked kist
node* add_Dleft(node* r,int value)
{
    node* iter = r;
    if (r != NULL)
    {
        node *new_node = (node*) malloc(sizeof(node)); //Allocating memory for a new node
        new_node->data = value;                        //Assigning entered value to new allocated node's data
        new_node->next = r;                         //Arranging root node as the next node of new node
        r->prev = new_node;
        r->prev->prev = NULL;
        return new_node;
    }
    else
    {
        node *new_node = (node*) malloc(sizeof(node)); //Allocating memory for a new node
        new_node->data = value;                        //Assigning entered value to new allocated node's data
        new_node->next = NULL;
        
        new_node->prev = NULL;
        return new_node;
    }
}
//Addition from end of Normal linked list
void add_end(node *r,int value)
{
    //If linked list has been started before,it functions in here
    if (r != NULL)
    {
        //Pointer goes to end of linked list
        while(r->next != NULL){r = r->next;}

        r->next = (node*)malloc(sizeof(node)); //Allocating memory for null space which comes after the last node of linked list
        r->next->data = value;                 //Assigning entered value to new allocated node's data
        r->next->next= NULL;                   //Arranging the space ,which comes after the last allocated node, as null
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
//Addition from end of Circular linked list
node* add_Cend(node *r,int value)
{
    node* iter = r;
    //If linked list has been started before,it functions in here
    if (r != NULL)
    {
        //Pointer goes to end of linked list
        while(iter->next != r){iter = iter->next;}

        iter->next = (node*)malloc(sizeof(node)); //Allocating memory for null space which comes after the last node of linked list
        iter->next->data = value;                 //Assigning entered value to new allocated node's data
        iter->next->next= r;                   //Arranging the space ,which comes after the last allocated node, as null
        return r;
    }
    //If linked list has not been started before, it functions in here 
    else
    {
        node *new_node = (node*) malloc(sizeof(node));  //Allocating memory for new node
        new_node->data = value;                         //Assigning entered value to new allocated node's data
        new_node->next = new_node;                          //Arranging the space ,which comes after the last allocated node, as null
        return new_node;                                            
    }
}
//Addition from end of Doubly linked list
void add_Dend(node *r,int value)
{
    //If linked list has been started before,it functions in here
    if (r != NULL)
    {
        //Pointer goes to end of linked list
        while(r->next != NULL){r = r->next;}

        r->next = (node*)malloc(sizeof(node)); //Allocating memory for null space which comes after the last node of linked list
        r->next->data = value;                 //Assigning entered value to new allocated node's data
        r->next->prev = r;
        r->next->next= NULL;                   //Arranging the space ,which comes after the last allocated node, as null
    }
    //If linked list has not been started before, it functions in here 
    else
    {
        node *new_node = (node*) malloc(sizeof(node));  //Allocating memory for new node
        new_node->data = value;                         //Assigning entered value to new allocated node's data
        new_node->next = NULL;                          //Arranging the space ,which comes after the last allocated node, as null
        new_node->prev = NULL;
        root = new_node;                                //Assigning new node to root 
    }
}
//Addition sequentially in Normal Linked List
node* add_seq(node *r,int value)
{
    //If linked list is empty
    if (r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r->next= NULL;
        r->data = value;
        return r;
    }
    //If 'value' is less than first value
    if (r->data > value)
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->next = r;
        return temp;
    }
    node* iter= r;
    while(iter->next != NULL && iter->next->data < value){ iter = iter->next; }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->data = value;
    return r;
} 
//Addition sequentially in Circular Linked List
node* add_Cseq(node *r,int value)
{
    //If linked list is empty
    if (r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r->next= r;
        r->data = value;
        return r;
    }
    //If 'value' is less than first value
    if (r->data > value)
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->next = r;
        node* iter = r;
        while(iter->next != r){iter = iter->next;}
        iter->next = temp;
        return temp;
    }
    node* iter = r;
    while(iter->next != r && iter->next->data < value){ iter = iter->next; }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->data = value;
    return r;
} 
//Addition sequentially in Doubly Linked List
node* add_Dseq(node *r,int value)
{
    //If linked list is empty
    if (r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r->next = NULL;
        r->prev = NULL;
        r->data = value;
        return r;
    }
    //If 'value' is less than first value
    if (r->data > value)
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->next = r;
        r->prev = temp;
        temp->prev = NULL;
        return temp;
    }
    node* iter= r;
    while(iter->next != NULL && iter->next->data < value){ iter = iter->next; }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->data = value;
    temp->prev = iter;
    if (temp->next != NULL){ temp->next->prev = temp; }
    return r;
} 
//Deleting a node from a Normal Linked List
node* delete(node* r,int value)
{
    node* temp;
    node* iter = r;
    if (r->data == value)
    {
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while (iter->next != NULL && iter->next->data != value)
    {
        iter = iter->next;
    }
    if (iter->next == NULL)
    {
        printf("Couldn't find the value!");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}
//Deletin a node from a Circular Linked List
node* delete_CL(node* r,int value)
{
    node* temp;
    node* iter = r;
    if (r->data == value)
    {
        while (iter->next != r){ iter = iter->next; }
        iter->next = r->next;
        free(r);
        return iter->next;
    }
    while (iter->next != r && iter->next->data != value)
    {
        iter = iter->next;
    }
    if (iter->next == r)
    {
        printf("Couldn't find the value!");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}
//Deleting a node from a Doubly Linked List
node* delete_D(node* r,int value)
{
    node* temp;
    node* iter = r;
    if (r->data == value)
    {
        temp = r;
        r = r->next;
        
        free(temp);
        r->prev = NULL;
        return r;
    }
    while (iter->next != NULL && iter->next->data != value){ iter = iter->next; }
    if (iter->next == NULL)
    {
        printf("Couldn't find the value!\n");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    if (temp->next != NULL){ temp->next->prev = iter; }
    free(temp);
    return r;
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
//Circular Linked List printer
void printCList(node* current)
{
    node* iter = current;
    
    // if list is empty 
    if ( current == NULL ) {
      printf( "List is empty.\n" );
    } // end if 
    else { 
        printf( "The list is:\n" );

    printf( "%d --> ", iter->data );
    iter = iter->next;   
    // while not the end of the list 
    while ( iter != current ) { 
        printf( "%d --> ", iter->data );
        iter = iter->next;   
        } // end while 

        printf( "NULL\n" );
    } // end else 
}
//Doubly Linked list printer
void printDList(node* current,int control)
{ 
    node* iter = current;
    while(iter->next != NULL){iter = iter->next;}
   // if list is empty 
   if ( current == NULL ) {
      printf( "List is empty.\n" );
   } // end if 
   else { 
      printf( "The list is:\n" );
    if (control)
    {
        // while not the end of the list 
      while ( current != NULL ) { 
         printf( "%d --> ", current->data );
         current = current->next;   
      } // end while 

      printf( "NULL\n" );
    }
    else
    {
        while (iter != NULL)
        {
            printf( "%d --> ", iter->data );
            iter = iter->prev;   
        }
        printf( "NULL\n" );
    }
    
   } // end else 

} 