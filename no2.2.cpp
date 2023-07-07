#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert_Node(int n) {
        struct Node* new_node = new Node;
        new_node->num = n;
        new_node->next = head;
        head = new_node;
    }

    void delete_Node() {
        if (head == NULL) {
            cout << "\nLinked List is empty.";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "\nNode deleted.";
    }

    void display_all_nodes() {
        if (head == NULL) {
            cout << "\nLinked List is empty.";
            return;
        }

        cout << "\nThe list contains the data entered:\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->num << " ";
            temp = temp->next;
        }
    }
};

int main() {
    char choice;
    int item;
    LinkedList l;

    do {
        cout << "\nMENU";
        cout << "\n1. Add Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Display Nodes";
        cout << "\n4. Exit";
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "\nEnter item to add: ";
                cin >> item;
                l.insert_Node(item);
                break;
            case '2':
                l.delete_Node();
                break;
            case '3':
                l.display_all_nodes();
                break;
            case '4':
                cout << "\nExiting...";
                break;
            default:
                cout << "\nInvalid choice. Try again.";
        }
    } while (choice != '4');

    return 0;
}
