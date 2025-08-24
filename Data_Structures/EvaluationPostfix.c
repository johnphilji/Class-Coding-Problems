#include<stdio.h>
#include<ctype.h>
#include<math.h>

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

void evaluatedpostfix(Stack *p1, char postfix[])
{
    int result=0;

    for (int i=0; postfix[i]!='\0'; i++)
    {
        if (postfix[i]=='^' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='%' || postfix[i]=='+' || postfix[i]=='-')
        {
            int operand2=pop(p1);
            int operand1=pop(p1);

            switch(postfix[i])
            {
                case '^':
                result=pow(operand1, operand2);
                break;

                case '*':
                result=operand1*operand2;
                break;

                case '/':
                result=operand1/operand2;
                break;

                case '%':
                result=operand1%operand2;
                break;

                case '+':
                result=operand1+operand2;
                break;

                case '-':
                result=operand1-operand2;
                break;
            }
            
            push(p1, result);
        }

        else
            push(p1, (postfix[i]-'0'));

    }

    printf("%d", result);
}

int main()
{
    Stack s;
    s.top=-1;
    char postfix[99];

    printf("Enter a postfix equation: ");
    gets(postfix);
    printf("Evaluated Postfix: ");
    evaluatedpostfix(&s, postfix);
}