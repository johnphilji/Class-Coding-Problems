#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int data;
    struct Node* next;
} node;

// Insert at end
node* insert_end(node* head) {
    node* new_node;
    node* temp;

    new_node = (node*)malloc(sizeof(node));
    cout << "Enter data: ";
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
    return head;
}

// Display / Traverse
void display(node* head) {
    node* temp = head;

    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Linked list elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Insert at beginning
node* insert_begin(node* head) {
    node* new_node;

    new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        cout << "Memory allocation failed" << endl;
        return head;
    }

    cout << "Enter data: ";
    cin >> new_node->data;

    new_node->next = head;
    head = new_node;

    return head;
}

// Insert at specific position
node* insert_at_position(node* head) {
    int pos, i;
    cout << "Enter position to insert: ";
    cin >> pos;

    node* new_node = (node*)malloc(sizeof(node));
    cout << "Enter data: ";
    cin >> new_node->data;
    new_node->next = NULL;

    if (pos <= 1 || head == NULL) {
        new_node->next = head;
        head = new_node;
        return head;
    }

    node* temp = head;
    for (i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}

// Delete at beginning
node* delete_begin(node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return head;
    }

    node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Delete at end
node* delete_end(node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node* temp = head;
    node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    return head;
}

// Delete at specific position
node* delete_at_position(node* head) {
    int pos, i;
    cout << "Enter position to delete: ";
    cin >> pos;

    if (head == NULL) {
        cout << "List is empty." << endl;
        return head;
    }

    if (pos <= 1) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* temp = head;
    node* prev = NULL;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range." << endl;
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

// Remove Duplicates 
node* remove_duplicates(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* temp = (node*)malloc(sizeof(node));
    temp->next = head;
    node* current = head;

    while (current != NULL) {
        int duplicate = 0;
        node* runner = current->next;

        while (runner != NULL) {
            if (runner->data == current->data) {
                duplicate = 1;
                break;
            }
            runner = runner->next;
        }

        if (duplicate) {
            int val = current->data;
            node* tempPrev = temp;
            node* p = temp->next;

            while (p != NULL) {
                if (p->data == val) {
                    tempPrev->next = p->next;
                    free(p);
                    p = tempPrev->next;
                } else {
                    tempPrev = p;
                    p = p->next;
                }
            }
            current = temp->next;
        } else {
            current = current->next;
        }
    }

    head = temp->next;
    free(temp);
    return head;
}

int main() {
    int choice;
    node* head = NULL;

    while (1) {
        cout << "\nMenu:\n";
        cout << "1) Insert at beginning\n";
        cout << "2) Insert at end\n";
        cout << "3) Insert at specific position\n";
        cout << "4) Delete at beginning\n";
        cout << "5) Delete at end\n";
        cout << "6) Delete at specific position\n";
        cout << "7) Display\n";
        cout << "8) Exit\n";
        cout << "9) Remove all duplicates\n";  
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                head = insert_begin(head);
                break;
            case 2:
                head = insert_end(head);
                break;
            case 3:
                head = insert_at_position(head);
                break;
            case 4:
                head = delete_begin(head);
                break;
            case 5:
                head = delete_end(head);
                break;
            case 6:
                head = delete_at_position(head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                return 0;
            case 9:
                head = remove_duplicates(head);
                cout << "All duplicates removed.\n";
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
