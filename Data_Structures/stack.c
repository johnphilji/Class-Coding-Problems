#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int top;
    int size;
    int A[100];
} Stack;

void initialize(Stack *p1, int a)
{  
    p1->size=a;
    p1->top=-1;
}

void push(Stack *p1, int ele)
{
    if (p1->top==(p1->size)-1)
        printf("\nStack Overflown. Unable to add element. \n");
    else
    {
        p1->top++;
        p1->A[p1->top] = ele;
    }
}

void display(Stack *p1)
{
    if (p1->top==-1)
        printf("\nStack Underflown. No elements to be displayed. \n");

    else
    {
        for (int b=p1->top; b>=0; b--)
            printf("%d ", p1->A[b]);
        printf("\n");
    }
}

void pop(Stack *p1)
{
    if (p1->top==-1)
    {
        printf("\nStack Underflown. No elements to be displayed. \n");
    }

    else
    {
        printf("%d", p1->A[p1->top]);
        p1->top--;
        printf("\n");
    }
}

void stacktop(Stack *p1)
{
    if (p1->top==-1)
        printf("\nStack Underflown. No elements to be displayed. \n");
    
    else
        printf("%d", p1->A[p1->top]);
        printf("\n");
}

void isfull(Stack *p1)
{
    if(p1->top==(p1->size)-1)
        printf("\nYes. \n");
    else 
        printf("\nNo. \n");
}

void isempty(Stack *p1)
{
    if(p1->top==-1)
        printf("\nYes. \n");
    else   
        printf("\nNo. \n");
}

int main()
{
    Stack s;

    int x;
    printf("\n Enter the size of Stack: \n->");
    while (1)
    {
        scanf("%d", &x);

        if (x>100)
            printf("\nSize should be less than 100. \n->");
        else if (x<1)
            printf("\nSize should not be 0 or negative. \n->");
        else
            break;
    }

    initialize(&s, x);

    while(1)
    {
        int y;
        printf("\nEnter your choice: \n1. Push \n2. Pop \n3. Display \n4. StackTop \n5. isFull \n6. isEmpty \n7. Exit \n-> ");
        scanf("%d", &y);
        
        switch (y)
        {
            case 1:
                int z;
                printf("Enter element to push: ");
                scanf("%d", &z);
                push(&s, z);
            break;

            case 2:
                pop(&s);
            break;

            case 3:
                display(&s);
            break;

            case 4:
                stacktop(&s);
            break;
            
            case 5:
                isfull(&s);
            break;

            case 6:
                isempty(&s);
            break;

            case 7:
                return 0;
            break;

            default:
                printf("\n Invalid. Enter a number between 1 and 7.\n->");
        }
    }
}