#include <iostream>

int MAX_SIZE = 100;

void displayArray(int arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertElement(int arr[], int& size, int element) {
    if (size == MAX_SIZE) {
        std::cout << "Array is full! Cannot insert element." << std::endl;
        return;
    }

    if (size == 15) {
        std::cout << "Maximum limit of 15 elements reached. Cannot insert more elements." << std::endl;
        return;
    }

    arr[size] = element;
    ++size;
}

void deleteElement(int arr[], int& size, int element) {
    bool found = false;
    int position = -1;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            found = true;
            position = i;
            break;
        }
    }

    if (found) {
        for (int i = position; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        --size;
        std::cout << "Element " << element << " deleted successfully." << std::endl;
    } else {
        std::cout << "Element " << element << " not found in the array." << std::endl;
    }
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int element;
    char choice;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> element;
        insertElement(arr, size, element);
    }

    do {
        displayArray(arr, size);
        std::cout << "Menu:\n";
        std::cout << "A. Insert\n";
        std::cout << "B. Delete\n";
        std::cout << "C. Search\n";
        std::cout << "D. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
            case 'A': {
                std::cout << "Enter element: ";
                std::cin >> element;
                insertElement(arr, size, element);
                break;
            }

            case 'b':
            case 'B': {
                std::cout << "Enter the element to delete: ";
                std::cin >> element;
                deleteElement(arr, size, element);
                break;
            }

            case 'c':
            case 'C':
                
                break;

            case 'd':
            case 'D':
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 'D' && choice != 'd');

    return 0;
}

