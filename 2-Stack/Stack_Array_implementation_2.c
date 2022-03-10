#include<stdio.h>
#include<stdlib.h>
#include<string.h>


float* stack ;      //Pointer for stack array
int top = 0;        //Initilazing top index
int dimension = 2;  //Initilazing dimension
//Pushing number to the stack
void push(float number);
//Deleting the last value and print to the screen if it is demanded
float pop();
//Print all stack
void print_Stack();
//Calculating given values by postfix arithmetic calculation 
void postfix_arithmetic(char tokens[5]);
//Checking if it is a number
int isNumber(char value);


int main()
{
    stack = (float*)malloc(sizeof(float)*dimension);    //Memory allocation
    char tokens[5];                                     //User input
    int control = 1;                                    //For exiting loop
    float result = 0;
    
    printf("\nTo finish, enter the word 'end'.\n\n");
    do
    {
        printf("Enter a token: ");                 
        scanf("%s",tokens);
        
        if (strcmp(tokens,"end") == 0)
        {
            control = 0;
            result = pop();
            printf("\nResult is: %.2f\n\n",result);
        }
        else
            postfix_arithmetic(tokens);
        
    } while (control);
    
    return 0;
}
//Pushing number to the stack
void push(float number)
{
    //If top index is passing array dimension
    if (top >= dimension)
    {
        dimension *= 2;                                         // Multiplication dimension by 2 to accept more number to array
        stack = (float*)realloc(stack,sizeof(float)*dimension); // Memory extending
        stack[top++] = number;                                  // Adding number to top index 
    }
    else
        stack[top++] = number;
}
//Deleting the last value and print to the screen if it is demanded
float pop()
{
    //If top index value is below of dimesion/4 value
    if (top <= dimension/4)
    {
        dimension /= 2;                                         //Dividing dimension by 2 to gain more memory
        stack = (float*)realloc(stack,sizeof(float)*dimension); //Memory shrinking
    }
    return stack[--top];
}
//Calculating given values by postfix arithmetic calculation 
void postfix_arithmetic(char tokens[5])
{
     
    float number, val1, val2;
    // If tokens is a number , it is pushed to stack
    if (isNumber(tokens[0]))
    {
        number = atof(tokens);
        push(number);
    }
    else
    {
        val2 = pop();
        val1 = pop();
        switch (tokens[0])
        {
        case '+': 
            push(val1 + val2); 
            break;
        case '-' :
            push(val1-val2);
            break;
        case '/':
            push( val1 / val2);
            break;
        case '*':
            push(val1 * val2);
            break;
        }
    }
}
//Checking if it is a number
int isNumber(char value)
{
    if(value <= '9' && value >= '0')
        return 1;
    return 0;
}
void print_Stack()
{
    int i;
    for ( i = 0; i < top; i++)
    {
         printf("%.2f \n",stack[i]);
    }
}