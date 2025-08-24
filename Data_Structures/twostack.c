#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int top;
    int size;
    int A[100];
} Stack;

void initialize(Stack *p1, int a, Stack *p2)
{  
    p1->size=a;
    p1->top=-1;
    p2->top=a;
}

void push(Stack *p1, Stack *p2, int ele)
{
    int c;
    printf("\nChoose what stack to push in: \n1. Stack 1\n2. Stack 2\n->");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
            if (p2->top==(p1->top)+1)
                printf("\nStack Overflown. Unable to add element. \n");
            else
            {
                p1->top++;
                p1->A[p1->top]=ele;
            }
        break;

        case 2:
        {
            if (p2->top==(p1->top)+1)
                printf("\nStack Overflown. Unable to add element. \n");
            else
            {
                p2->top--;
                p2->A[p2->top]=ele;
            }
        }   
        break;
    }
}

void pop(Stack *p1, Stack *p2, int x)
{
    int c;
    printf("\nChoose what stack to pop from: \n1. Stack 1\n2. Stack 2\n->");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
            if (p1->top==-1)
                printf("\nStack Underflown. No elements to be displayed. \n");
            else
            {
                printf("%d", p1->A[p1->top]);
                p1->top--;
                printf("\n");
            }
        break;

        case 2:
            if (p2->top==x)
                printf("\nStack Underflown. No elements to be displayed. \n");
            else
            {
                printf("%d", p2->A[p2->top]);
                p2->top++;
                printf("\n");
            }
        break;
    }
}

void display(Stack *p1, Stack *p2, int x)
{
    int c;
    printf("\nChoose what stack to display: \n1. Stack 1\n2. Stack 2\n->");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
            if (p1->top==-1)
                printf("\nStack Underflown. No elements to be displayed. \n");
            else
            {
                for (int b=p1->top; b>=0; b--)
                    printf("%d ", p1->A[b]);
                printf("\n");
            }
        break;

        case 2:
            if (p2->top==x)
                printf("\nStack Underflown. No elements to be displayed. \n");
            else
            {
                for (int c=p2->top; c<=x-1; c++) //c++
                    printf("%d ", p2->A[c]);
                printf("\n");
            }
        break;
    }
}

void stacktop(Stack *p1, Stack *p2, int x)
{
    int c;
    printf("\nChoose what stack to peek: \n1. Stack 1\n2. Stack 2\n->");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
            if (p1->top==-1)
                printf("\nStack Underflown. No elements to be displayed. \n");
            else
            {
                printf("%d", p1->A[p1->top]);
                printf("\n");
            }
        break;

        case 2:
            if (p2->top==x)
                printf("\nStack Underflown. No elements to be displayed. \n");
            else
            {
                printf("%d", p2->A[p2->top]);
                printf("\n");
            }
        break;
    }
}

void isfull(Stack *p1, Stack *p2)
{
    if (p2->top==(p1->top)+1)
        printf("\nYes. \n");
    else 
        printf("\nNo. \n");
}

void isempty(Stack *p1, Stack *p2, int x)
{
    if (p1->top==-1 && p2->top==x)
        printf("\nYes. \n");
    else 
        printf("\nNo. \n");
}

int main()
{
    Stack s1;
    Stack s2;

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

    initialize(&s1, x, &s2);

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
                push(&s1, &s2, z);
            break;

            case 2:
                pop(&s1, &s2, x);
            break;

            case 3:
                display(&s1, &s2, x);
            break;

            case 4:
                stacktop(&s1, &s2, x);
            break;
            
            case 5:
                isfull(&s1, &s2);
            break;

            case 6:
                isempty(&s1, &s2, x);
            break;

            case 7:
                return 0;
            break;

            default:
                printf("\n Invalid. Enter a number between 1 and 7.\n->");
        }
    }
}