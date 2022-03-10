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
node* queue1_first,*queue1_last;
void enqueue(node** queue_first,node** queue_last,int number)
{
	node* newNode = (node*)malloc(sizeof(node));
    if (newNode != NULL)
	{
		newNode->data = number;
		newNode->next = NULL;
		if(*queue_first==NULL)
			(*queue_first) = newNode;
		else
		{
			(*queue_last) ->next = newNode;
		}
		(*queue_last) = newNode;
	}
	
}
int dequeue(node** queue_first,node** queue_last)
{
	if((*queue_first)==NULL){
		//printf("Queue is empty!");
		return -1;
	}
	int rvalue = (*queue_first)->data;
	node *temp =(*queue_first);
	(*queue_first) = (*queue_first)->next;	
	free(temp);
	return rvalue;
}
//Peeking to first element of queue
void peek(node* queue_first,node* queue_last) 
{
	if(queue_first == NULL) 
    {
		//printf("\nQueue is empty\n");		
	}
	else 
    {
		printf("\nFirst element of Queue: %d\n", queue_first->data);
	}
}
//Queue Initializer as NULL
void initialize(node** queue_first,node** queue_last) {
	*queue_first = NULL;
    *queue_last = NULL;
}
//Reset Queue
void reset(node** queue_first,node** queue_last)
{
    int value;
    do
    {
        value = dequeue(queue_first,queue_last);
    } while (value != -1);

}
//Normal Linked list printer
void printList(node* current)
{ 
    
   // if list is empty 
   if ( current == NULL ) {
      printf( "Queue is empty.\n" );
   } // end if 
   else { 
      printf( "The Queue is:\n" );

      // while not the end of the list 
      while ( current != NULL ) { 
         printf( "%d --> ", current->data );
         current = current->next;   
      } // end while 

      printf( "NULL\n" );
   } // end else 

}
int main()
{
    int value;
    int choice, input;

	initialize(&queue1_first,&queue1_last);
	while(choice != 0) {
		printf("\n(1) Add an element");
		printf("\n(2) Delete first element of queue");
		printf("\n(3) Peek to first element of queue");
        printf("\n(4) Reset Queue");
		printf("\n(0) Exit\nChoice: ");
		scanf("%d", &choice);
        printf("\n");
		
		switch(choice) {
			case 1:
				printf("\nEnter an integer: ");
				scanf(" %d", &input);
				enqueue(&queue1_first,&queue1_last,input);
                printList(queue1_first);
				break;
			
			case 2:
				value = dequeue(&queue1_first,&queue1_last);
                value != -1 ? printf("Popped Value: %d\n",value):printf("\n");
                
                printList(queue1_first);
				break;

			case 3:
				peek(queue1_first,queue1_last);
                printList(queue1_first);
				break;		
            case 4:
				reset(&queue1_first,&queue1_last);
                printList(queue1_first);
				break;	

		}
	}
    return 0;
}