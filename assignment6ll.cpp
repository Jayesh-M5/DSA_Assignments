
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// ENQUEUE operation
void enqueue(int x)
{
    Node* newNode = new Node;

    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << x << " inserted into queue." << endl;
}

// DEQUEUE operation
void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node* temp = front;

    cout << "Deleted element: " << front->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

// DISPLAY operation
void display()
{
    if (front == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node* temp = front;

    cout << "Queue elements: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// MAIN FUNCTION
int main()
{
    int choice, value;

    do
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
