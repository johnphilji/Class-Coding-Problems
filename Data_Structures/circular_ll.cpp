#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} node;

// Count nodes in circular list
int countNodes(node* head) {
    if (head == NULL) return 0;
    int count = 0;
    node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Insert at end
node* insert_end(node* head) {
    node* newnode = (node*)malloc(sizeof(node));
    cout << "Enter data: ";
    cin >> newnode->data;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        node* tmp = head;
        while (tmp->next != head) {
            tmp = tmp->next;
        }
        tmp->next = newnode;
        newnode->next = head;
    }
    return head;
}

// Insert at beginning
node* insert_begin(node* head) {
    node* newnode = (node*)malloc(sizeof(node));
    cout << "Enter data: ";
    cin >> newnode->data;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    return head;
}

// Insert at specific position
node* insert_pos(node* head, int pos) {
    int n = countNodes(head);
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position! Current size: " << n << endl;
        return head;
    }

    node* newnode = (node*)malloc(sizeof(node));
    cout << "Enter data: ";
    cin >> newnode->data;

    if (pos == 1) {
        return insert_begin(head);
    }
    node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

// Delete at beginning
node* delete_begin(node* head) {
    if (head == NULL) {
        cout << "List empty!\n";
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    node* temp = head;
    node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

// Delete at end
node* delete_end(node* head) {
    if (head == NULL) {
        cout << "List empty!\n";
        return head;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    node* temp = head;
    node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    return head;
}

// Delete at position
node* delete_pos(node* head, int pos) {
    int n = countNodes(head);
    if (pos < 1 || pos > n) {
        cout << "Invalid position! Current size: " << n << endl;
        return head;
    }

    if (pos == 1) {
        return delete_begin(head);
    }
    node* temp = head;
    node* prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

// Display circular list
void display(node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    node* head = NULL;
    int choice, pos;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display\n";
        cout << "8. Count Nodes\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: head = insert_end(head); break;
            case 2: head = insert_begin(head); break;
            case 3: 
                cout << "Enter position: ";
                cin >> pos;
                head = insert_pos(head, pos); 
                break;
            case 4: head = delete_begin(head); break;
            case 5: head = delete_end(head); break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                head = delete_pos(head, pos);
                break;
            case 7: display(head); break;
            case 8: cout << "Node count: " << countNodes(head) << endl; break;
            case 9: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}