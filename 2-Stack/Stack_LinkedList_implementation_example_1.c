#include <stdio.h>
#include<stdlib.h>
//Defining a variable(struct) as node_struct
struct node_struct
{
    int data;
    struct node_struct *next;
};
//Type redefinition as node
typedef struct node_struct node;


//Stack Initializer as NULL
node* initialize(node* stack);  // bottom = initialize(bottom);
//Peeking to top of stack
void peek(node* stack);         // peek(bottom);
//Deleting the last value and print to the screen if it is demanded  
int pop(node** root);           // value = pop(&bottom);
//Pushing number to the stack
node* push(node* root,int number); // bottom = push(bottom,number);
//Checking if stack is empty or not
int isEmpty(node* stack);           // isEmpty(bottom);
//Reset stack
node* reset(node** stack);          // bottom = reset(&bottom);
//Normal Linked list printer
void printList(node* current);      // printList(bottom);



int main()
{

    int value;
    node* bottom;   //Assigning root pointer variable as node
    bottom = initialize(bottom);
    bottom = push(bottom,5);
    printList(bottom);
    value = pop(&bottom);
    printf("%d\n",value);
    printList(bottom);
    
    bottom = push(bottom,6);
    printList(bottom);
    bottom = push(bottom,7);
    printList(bottom);
    bottom = push(bottom,8);
    bottom = reset(&bottom);
    printList(bottom);
    peek(bottom);
    value = pop(&bottom);
    printf("%d\n",value);
    printList(bottom);
    value = pop(&bottom);
    printf("%d\n",value);
    printList(bottom);
    value = pop(&bottom);
    printf("%d\n",value);
    printList(bottom);
    value = pop(&bottom);
    printf("%d\n",value);
    bottom = push(bottom,75);
    peek(bottom);
    printList(bottom);
    value = pop(&bottom);
    printf("%d\n",value);
    printList(bottom);
    value = pop(&bottom);
    printf("%d\n",value);
    printList(bottom);



    return 0;
}
//Deleting the last value and print to the screen if it is demanded
int pop(node** root)
{
    
    if (isEmpty((*root)))
    {
        printf("It is empty:");
        return -1;
    }
    if (isEmpty((*root)->next))
    {
        int value = (*root) ->data;
        *root = NULL;
        return value;
    }
    node* iter = (*root);
    while(iter->next->next != NULL){iter = iter->next;}
    node* temp = iter -> next;
    int value = temp -> data;
    iter -> next = NULL; 
    free(temp);
    return value;
}
node* initialize(node* stack) {
	stack = NULL;
    return stack;
}
void peek(node* stack) {
	if(stack == NULL) 
    {
		printf("\nStack is empty\n");		
	}
	else 
    {
        while(stack->next != NULL){stack = stack->next;}
		printf("\nTop of Stack: %d\n", stack->data);
	}
}
int isEmpty(node* stack) 
{
	return stack==NULL;
}
node* reset(node** stack)
{
    int value;
    do
    {
        value = pop(stack);
    } while (value != -1);
    
    printf("\nIt is reset\n");
    return *stack;
    
}

//Pushing number to the stack
node* push(node* root,int number)
{
    if (root == NULL)
    {
        root = (node*) malloc(sizeof(node));
        root -> data = number;
        root -> next = NULL;
        return root;
    }
    node* iter = root;
    while(iter->next != NULL){iter = iter->next;}
    node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = number;
    new_node -> next = NULL;
    iter -> next = new_node;
    return root; 
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