#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* back;

public:
    Queue() : front(NULL), back(NULL) {}

    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        back = NULL;
    }

    void enqueue(int element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;

        if (isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }

        std::cout << "Element added successfully!" << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "The queue is empty. Cannot delete an element." << std::endl;
            return;
        }

        Node* temp = front;
        std::cout << "Deleted element: " << temp->data << std::endl;

        if (front == back) {
            front = back = NULL;
        } else {
            front = front->next;
        }

        delete temp;
    }

    int searchElement(int element) {
        if (isEmpty()) {
            std::cout << "The queue is empty. Cannot search for an element." << std::endl;
            return -1;
        }

        Node* current = front;
        int index = 0;
        while (current != NULL) {
            if (current->data == element) {
                return index;
            }
            current = current->next;
            index++;
        }

        return -1;
    }

    bool isEmpty() const {
        return front == NULL;
    }

    void displayElements() const {
        if (isEmpty()) {
            std::cout << "The queue is empty." << std::endl;
            return;
        }

        Node* current = front;
        std::cout << "Elements in the queue: ";
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int identifyLargestInteger() const {
        if (isEmpty()) {
            std::cout << "The queue is empty. Cannot identify the largest integer." << std::endl;
            return -1;
        }

        int largest = front->data;

        Node* current = front->next;
        while (current != NULL) {
            if (current->data > largest) {
                largest = current->data;
            }
            current = current->next;
        }

        return largest;
    }
};

int main() {
    Queue myQueue;
    char choice;

    do {
        std::cout << "QUEUE OPERATIONS" << std::endl;
        std::cout << "A. Add an element" << std::endl;
        std::cout << "B. Delete an element" << std::endl;
        std::cout << "C. Search for an element" << std::endl;
        std::cout << "D. Display the elements" << std::endl;
        std::cout << "E. Find the largest integer" << std::endl;
        std::cout << "F. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
            case 'A': {
                int element;
                std::cout << "Enter the element to add: ";
                std::cin >> element;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter an integer." << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    break;
                }

                myQueue.enqueue(element);
                break;
            }
            case 'b':
            case 'B':
                myQueue.dequeue();
                break;
            case 'c':
            case 'C': {
                int element;
                std::cout << "Enter the element to search: ";
                std::cin >> element;

                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter an integer." << std::endl;
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    break;
                }

                int index = myQueue.searchElement(element);
                if (index != -1) {
                    std::cout << "Element found at index: " << index << std::endl;
                } else {
                    std::cout << "Element not found in the queue." << std::endl;
                }
                break;
            }
            case 'd':
            case 'D':
                myQueue.displayElements();
                break;
            case 'e':
            case 'E': {
                int largest = myQueue.identifyLargestInteger();
                if (largest != -1) {
                    std::cout << "The largest integer in the queue is: " << largest << std::endl;
                }
                break;
            }
            case 'f':
            case 'F':
                std::cout << "Exiting the program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 'f');

    return 0;
}

