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
//Assigning bottom pointer variable as node # Define in main not in global
node* bottom;
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
    int choice, input;

	bottom = initialize(bottom);
	while(choice != 0) {
		printf("\n(1) Add an element");
		printf("\n(2) Delete top element of stack");
		printf("\n(3) Peek to top element of stack");
        printf("\n(4) Reset Stack");
		printf("\n(0) Exit\nChoice: ");
		scanf("%d", &choice);
        printf("\n");
		
		switch(choice) {
			case 1:
				printf("\nEnter an integer: ");
				scanf(" %d", &input);
				bottom = push(bottom,input);
                printList(bottom);
				break;
			
			case 2:
				value = pop(&bottom);
                value != -1 ? printf("Popped Value: %d\n",value):printf("\n");
                
                printList(bottom);
				break;

			case 3:
				peek(bottom);
                printList(bottom);
				break;		
            case 4:
				bottom = reset(&bottom);
                printList(bottom);
				break;	

		}
	}
    return 0;
}
//Stack Initializer as NULL
node* initialize(node* stack) {
	stack = NULL;
    return stack;
}
//Peeking to top of stack
void peek(node* stack) 
{
	if(stack == NULL) 
    {
		//printf("\nStack is empty\n");		
	}
	else 
    {
        while(stack->next != NULL){stack = stack->next;}
		printf("\nTop of Stack: %d\n", stack->data);
	}
}
//Deleting the last value and print to the screen if it is demanded
int pop(node** root)
{
    
    if (isEmpty((*root)))
    {
        //printf("It is empty:");
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
//Checking if stack is empty or not
int isEmpty(node* stack) 
{
	return stack==NULL;
}
//Reset stack
node* reset(node** stack)
{
    int value;
    do
    {
        value = pop(stack);
    } while (value != -1);

    return *stack;
}
//Normal Linked list printer
void printList(node* current)
{ 
    
   // if list is empty 
   if ( current == NULL ) {
      printf( "Stack is empty.\n" );
   } // end if 
   else { 
      printf( "The Stack is:\n" );

      // while not the end of the list 
      while ( current != NULL ) { 
         printf( "%d --> ", current->data );
         current = current->next;   
      } // end while 

      printf( "NULL\n" );
   } // end else 

}