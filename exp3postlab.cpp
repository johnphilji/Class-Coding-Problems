#include <iostream>
#define SIZE 100

using namespace std;

struct Queue {
    int data[SIZE];
    int f;
    int r;
};

struct Stack {
    int data[SIZE];
    int top;
};

void insert(Queue *q, int value) {
    if (q->r == SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (q->f == -1)
        q->f = 0;
    q->r++;
    q->data[q->r] = value;
}

int dequeue(Queue *q) {
    if (q->f == -1 || q->f > q->r) {
        cout << "Queue Underflow\n";
        return -1;
    }
    return q->data[q->f++];
}

void push(Stack *s, int value) {
    if (s->top == SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return s->data[s->top--];
}

void displayStack(Stack *s) {
    cout << "Stack (top to bottom): ";
    for (int i = s->top; i >= 0; i--) {
        cout << s->data[i] << " ";
    }
    cout << "\n";
}

int main() {
    Queue q;
    Stack s;
    q.f = q.r = -1;
    s.top = -1;

    int n, val;
    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(&q, val);
    }

    while (q.f <= q.r) {
        val = dequeue(&q);
        push(&s, val);
    }

    displayStack(&s);
    return 0;
}
