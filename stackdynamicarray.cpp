#include <iostream>
#include <stdexcept>

class Stack {
private:
    int size;
    int capacity;
    int* arr;
    int top;

public:
    Stack() {
        size = 0;
        capacity = 2;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* old_arr = arr;
            arr = new int[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = old_arr[i];
            }
            delete[] old_arr;
        }
        top++;
        size++;
        arr[top] = value;
    }
    
    int pop() {
        if (top == -1) {
            throw std::runtime_error("Cannot pop from an empty stack.");
        }
        int top_element = arr[top];
        top--;
        size--;
        return top_element;
    }

    int peek() {
        if (top == -1) {
            throw std::runtime_error("Cannot peek from an empty stack.");
        }
        return arr[top];
    }

    int get_index(int value) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void print() {
        std::cout << "[";
        if (top != -1) {
            std::cout << arr[0];
        }
        for (int i = 1; i <= top; i++) {
            std::cout << " " << arr[i];
        }
        std::cout << "]" << std::endl;
    }

    int getLargest() {
        if (top == -1) {
            throw std::runtime_error("Stack is empty.");
        }
        int largest = arr[0];
        for (int i = 1; i <= top; i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }
        return largest;
    }
};

int main() {
    Stack s;

    int choice;
    int value;

    do {
        std::cout << "Stack Menu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Display\n";
        std::cout << "4. Find Largest\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the value to push: ";
                std::cin >> value;
                s.push(value);
                std::cout << "Current contents of the stack: ";
                s.print();
                break;
            case 2:
                try {
                    std::cout << "Popped: " << s.pop() << std::endl;
                    std::cout << "Current contents of the stack: ";
                    s.print();
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case 3:
                std::cout << "Current contents of the stack: ";
                s.print();
                break;
            case 4:
                try {
                    int largest = s.getLargest();
                    std::cout << "Largest integer in the stack: " << largest << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        std::cout << std::endl;

    } while (choice != 5);

    return 0;
}

