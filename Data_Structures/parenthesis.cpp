#include<iostream>
using namespace std;

#define SIZE 10

typedef struct stack{
    int top;
    char arr[SIZE];
}stack;

void push(stack *p, char e){
    if (p->top == SIZE-1){
        cout<<"Stack Overflow\n";
        return;
    }else{
        p->top++;
        p->arr[p->top] = e;
        cout<<e;
    }
}

void pop(stack *p){
    if (p->top == -1){
        cout<<"Stack Underflow\n";
        return;
    }else{
        cout<<p->arr[p->top]<<" ";
        p->top--;
    }
}

void display(stack *p){
    if (p->top == -1){
        cout<<"Stack is empty\n";
        return;
    }else{
        cout<<"Stack elements: ";
        for (int i = 0; i <= p->top; i++){
            cout<<p->arr[i]<<" ";
        }
        cout<<endl;
    }
}

void checkValidity(stack *p, char input[]){
    
}