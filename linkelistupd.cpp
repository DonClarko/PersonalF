#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addFirst(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Added " << value << " to the beginning of the list." << endl;
    }

    void addLast(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Added " << value << " to the end of the list." << endl;
    }

    void addAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1) {
            addFirst(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Added " << value << " at position " << position << " in the list." << endl;
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted element from the beginning of the list." << endl;
    }

    void deleteLast() {
        if (head == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == nullptr) {
            head = nullptr;
        } else {
            prev->next = nullptr;
        }

        delete temp;
        cout << "Deleted element from the end of the list." << endl;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1) {
            deleteFirst();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        int count = 1;

        while (temp != nullptr && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Invalid position." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Deleted element at position " << position << " in the list." << endl;
    }
    
 bool deleteSameValue(int value) {
    if (head == nullptr) {
        cout << "The list is already empty." << endl;
        return false;
    }

    Node* temp = head;
    Node* prev = nullptr;
    bool deleted = false;

    while (temp != nullptr) {
        if (temp->data == value) {
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
            deleted = true;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    if (deleted) {
        cout << "Deleted all occurrences of " << value << " from the list." << endl;
        return true;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
        return false;
    }
}



    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        cout << "Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    int choice;
    int value, position;

    while (true) {
        cout << "A. Add element" << endl;
        cout << "B. Delete an element" << endl;
        cout << "C. Display the list" << endl;
        cout << "D. Exit" << endl;
        cout << "Enter your choice: ";
        char choiceChar;
        cin >> choiceChar;

        switch (choiceChar) {
            case 'A':
            case 'a':
                cout << endl;
                cout << "A. Add at the beginning" << endl;
                cout << "B. Add at the end" << endl;
                cout << "C. Add at a specific position" << endl;
                cout << "Enter your choice: ";
                char subChoiceChar;
                cin >> subChoiceChar;

                switch (subChoiceChar) {
                    case 'A':
                    case 'a':
                        cout << "Enter the value to add: ";
                        cin >> value;
                        list.addFirst(value);
                        break;
                    case 'B':
                    case 'b':
                        cout << "Enter the value to add: ";
                        cin >> value;
                        list.addLast(value);
                        break;
                    case 'C':
                    case 'c':
                        cout << "Enter the value to add: ";
                        cin >> value;
                        cout << "Enter the position to add: ";
                        cin >> position;
                        list.addAtPosition(value, position);
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
                break;
            case 'B':
            case 'b':
                cout << endl;
                cout << "A. Delete from the beginning" << endl;
                cout << "B. Delete from the end" << endl;
                cout << "C. Delete from a specific position" << endl;
                cout << "D. Delete same value" << endl; 
                cout << "Enter your choice: ";
                cin >> subChoiceChar;

                switch (subChoiceChar) {
                     case 'A':
                     case 'a':
                         list.deleteFirst();
                         break;
                     case 'B':
                     case 'b':
                         list.deleteLast();
                         break;
                     case 'C':
                     case 'c':
                         cout << "Enter the position to delete: ";
                         cin >> position;
                         list.deleteAtPosition(position);
                        break;
                     case 'D': 
                     case 'd':
                         cout << "Enter the value to delete: ";
                         cin >> value;
                         list.deleteSameValue(value);
                         break;
                     default:
                         cout << "Invalid choice. Please try again." << endl;
                         break;
                 }
                 break;

            case 'C':
            case 'c':
                list.display();
                break;
            case 'D':
            case 'd':
                cout << "Exiting the program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }

    return 0;
}
