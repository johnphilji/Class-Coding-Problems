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

int precedance(char c)
{
    if (c=='^')
    return 6;
    else if (c=='*' || c=='/' || c=='%')
        return 5;
    else if (c=='+' || c=='-')
        return 4;
    else if (c=='(')
        return 0;
    else 
        return 6;
}

void infixpostfix(Stack *p1, char infix[], char postfix[])
{
    int j=0;

    for(int i=0; infix[i]!='\0'; i++)
    {
        if (infix[i]=='(')
            push(p1, infix[i]);
        else if (isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if (infix[i]==')')
        {
            while (stacktop(p1)!='(' && p1->top!=-1)
                    postfix[j++]=pop(p1);
            if (stacktop(p1)=='(')
                pop(p1);        
        }
        else
        {
            while (precedance(stacktop(p1))>=precedance(infix[i]) && p1->top!=-1)
                    postfix[j++]=pop(p1);
            push(p1, infix[i]);
        }   
    }
    while(p1->top!=-1)
        postfix[j++]=pop(p1);
    postfix[j]='\0';

    puts(postfix);
}

int main()
{
    Stack s;
    s.top=-1;
    char infix[99];
    char postfix[99];

    printf("Enter an equation: ");
    gets(infix);
    printf("Infix: ");
    puts(infix);
    printf("Postfix: ");

    infixpostfix(&s, infix, postfix);
}