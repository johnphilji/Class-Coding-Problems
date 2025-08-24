#include<stdio.h>
#include<ctype.h>

typedef struct Stack{
    int top;
    char A[100];
} Stack;

char push(Stack *p1, char ele)
{
    if (p1->top==99)
    return '\0';
    else
    {
        p1->top++;
        p1->A[p1->top]=ele;
    }
}

char pop(Stack *p1)
{
    if (p1->top==-1)
    return '\0';
    else
        return(p1->A[p1->top--]);
}

char stacktop(Stack *p1)
{
    if (p1->top==-1)
        return '\0';
    
    else
        return(p1->A[p1->top]);
}

void checkvalidity(Stack *p1, char input[])
{
    int j=0;

    for (int i=0; input[i]!='\0'; i++)
    {
        if (input[i]=='(' || input[i]=='{' || input[i]=='[')
            push(p1, input[i]);
        else if (input[i]==')')
        {
            if (stacktop(p1)=='(')
                pop(p1);
            else
            {
                printf("Invalid Equation. ");
                return;
            }
        }
        else if (input[i]=='}')
        {
            if (stacktop(p1)=='{')
                pop(p1);
            else
            {
                printf("Invalid Equation. ");
                return;
            }
        }
        else if (input[i]==']')
        {
            if (stacktop(p1)=='[')
                pop(p1);
            else
            {
                printf("Invalid Equation. ");
                return;
            }
        }
    }
    
    if (p1->top!=-1)
        printf("Invalid Equation. ");
    else
        printf("Valid Equation. ");
}

int main()
{
    Stack s;
    s.top=-1;
    char equation[99];

    printf("Enter an equation: ");
    gets(equation);
    checkvalidity(&s, equation);
}