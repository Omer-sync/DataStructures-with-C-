#include<stdio.h>
#include<stdlib.h>

int *queue = NULL;
int first = 0,last = 0, size =2;
void clear()
{
    int i;
    if (first ==0)
        return;
     
    for ( i = 0; i < last - first; i++) 
        queue[i] = queue[first+i];
    
    last -= first;
    first = 0;
}
int dequeue()
{
    if (first == last)
    {
        printf("It is empty!\n");
        return -1;
    }
    if (last - first < size/4)
    {
        size /= 2;
        queue = (int*)realloc(queue,sizeof(int)*size);
    }
    if (first > (last-first)/2)
        clear();
    
    return queue[first++];
}
void enqueue(int number)
{
    if (queue == NULL)
        queue = (int*)malloc(sizeof(int)*size);

    if (last >= size)
    {
        size *= 2;
        queue = (int*)realloc(queue,sizeof(int)*size);
    }
    if (size - last == 1 && first > 0)
        clear();
    
    queue[last++] = number;
} 

void print_queue()
{
    int i;
    if (last == first)
    {
        printf("Queue is empty!\n");
        return;
    }
    
    for ( i = first; i < last; i++)
    {
         printf("%d \n",queue[i]);
    }
}
int main()
{
    dequeue();
    print_queue();
    for (int i = 0; i < 10; i++)
    {
        enqueue(i*10);
	    printf(" durum: size : %d last %d first %d\n",size,last,first);
    }
    dequeue();
    printf(" durum: size : %d last %d first %d\n",size,last,first);
    dequeue();
    printf(" durum: size : %d last %d first %d\n",size,last,first);
    dequeue();
    printf(" durum: size : %d last %d first %dhopp\n",size,last,first);
    print_queue();
    enqueue(75);
    printf(" durum: size : %d last %d first %d\n",size,last,first);
    print_queue();
    enqueue(74);
    printf(" durum: size : %d last %d first %d\n",size,last,first);
    print_queue();
    enqueue(78);
    printf(" durum: size : %d last %d first %d\n",size,last,first);
    print_queue();
    enqueue(79);
    printf(" durum: size : %d last %d first %d\n",size,last,first);
    print_queue();
    enqueue(85);
    printf(" durum: size : %d last %d first %d\n",size,last,first);
    print_queue();
    enqueue(82);
    dequeue();
    printf(" durum: size : %d last %d first %d,%d\n",size,last,first,dequeue());
    dequeue();
    dequeue();
    dequeue();
    enqueue(121);
    enqueue(132);
    enqueue(159);


    print_queue();


    




    return 0;
}
