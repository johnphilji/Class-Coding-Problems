#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} node;

// Create Linked List
node* create_ll(node* head) {
    int n;
    cout << "Enter no. of nodes: -> ";
    cin >> n;

    node* new_node;
    node* temp;

    for (int i = 0; i < n; i++) {
        new_node = (node*)malloc(sizeof(node));
        cout << "Enter value for node " << (i + 1) << ": -> ";
        cin >> new_node->data;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    return head;
}

// Display Linked List
void display(node* head) {
    node* temp = head;

    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Split Linked List 
void split_ll(node* head, node** head1, node** head2) {
    if (head == NULL) {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }

    int count = 0;
    node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;

    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    *head1 = head;
    *head2 = temp->next;
    temp->next = NULL;
}

// Concatenate two Linked Lists
node* concatenate(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

// Copy Linked List
node* copy_ll(node* head) {
    if (head == NULL) return NULL;

    node* new_head = NULL, *new_tail = NULL;

    while (head != NULL) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = head->data;
        new_node->next = NULL;

        if (new_head == NULL) {
            new_head = new_node;
            new_tail = new_node;
        } else {
            new_tail->next = new_node;
            new_tail = new_node;
        }
        head = head->next;
    }
    return new_head;
}

// Reverse Linked List
node* reverse_ll(node* head) {
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; 
}

int main() {
    node* head = NULL;
    node* head1 = NULL;
    node* head2 = NULL;
    node* copied = NULL;
    int choice;

    while (true) {
        cout << "\n1. Create Linked List\n";
        cout << "2. Display\n";
        cout << "3. Split\n";
        cout << "4. Concatenate \n";
        cout << "5. Copy\n";
        cout << "6. Reverse\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                head = create_ll(head);
                break;
            case 2:
                cout << "Full Linked List: ";
                display(head);
                break;
            case 3:
                split_ll(head, &head1, &head2);
                cout << "First Half: ";
                display(head1);
                cout << "Second Half: ";
                display(head2);
                break;
            case 4:
                head = concatenate(head1, head2);
                cout << "After Concatenation: ";
                display(head);
                break;
            case 5:
                copied = copy_ll(head);
                cout << "Copied Linked List: ";
                display(copied);
                break;
            case 6: {
                cout<<"Before Reverse: ";
                display(head);

                node* reversed = copy_ll(head);
                reversed = reverse_ll(reversed);
                cout << "Reversed Linked List: ";
                display(reversed);
                break;
            }
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}
