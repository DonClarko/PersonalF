#include <iostream>
#define MAX_SIZE 5
using namespace std;

class Queue {
private:
    int myQueue[MAX_SIZE], front, rear;
public:
    Queue () {
        front = -1;
        rear = -1;
    }

    void qinsert(int item) {
        if (rear == MAX_SIZE-1) {
            cout<<"\nQUEUE OVERFLOW (" << item <<  ")";
        }
        else if (front==-1 && rear==-1) {
            front=rear=0;
            myQueue[rear]=item;
            cout<<"\nITEM ADDED: "<<item;
        } else {
            rear++;
            myQueue[rear]=item;
            cout<<"\nITEM ADDED: "<<item;
        }
    }

    void qdelete(){
        int item;
        if(rear==-1){
            cout<<"\nQUEUE UNDERFLOW";
        }
        else if(front==0 && rear==0){
            item = myQueue[front];
            front=rear=-1;
            cout<<"\n\nITEM DELETED: "<<item;
        } else {
            item=myQueue[front];
            front++;
            cout<<"\n\nITEM DELETED: "<<item;
        }
    }

    void qtraverse() {
        if(front==-1) {
            cout<<"\n\nQUEUE IS EMPTY\n";
        } else {
            cout<<"\n\nQUEUE ITEMS\n";
            for (int i=front;i<=rear;i++) {
            cout<< myQueue[i] <<" ";
        }
        cout<<endl;
        }
    }
};

int main() {
    char choice;
    int item;
    Queue myq;

    do {
        cout << "\nMENU";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "\nEnter item to enqueue: ";
                cin >> item;
                myq.qinsert(item);
                break;
            case '2':
                myq.qdelete();
                break;
            case '3':
                myq.qtraverse();
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