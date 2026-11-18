
#include <iostream>
using namespace std;

#define SIZE 100

int q1[SIZE], q2[SIZE];

int front1 = 0, rear1 = -1;
int front2 = 0, rear2 = -1;

// PUSH operation
void push(int x)
{
    if (rear1 == SIZE - 1)
    {
        cout << "Stack is full!" << endl;
        return;
    }

    // Insert new element into q2
    q2[++rear2] = x;

    // Move all elements from q1 to q2
    while (front1 <= rear1)
    {
        q2[++rear2] = q1[front1++];
    }

    // Copy q2 back to q1
    front1 = 0;
    rear1 = rear2;

    for (int i = 0; i <= rear2; i++)
    {
        q1[i] = q2[i];
    }

    rear2 = -1;
    front2 = 0;
    front1 = 0;

    cout << x << " pushed into stack." << endl;
}

// POP operation
void pop()
{
    if (front1 > rear1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Popped element: " << q1[front1] << endl;

    // Remove the top element
    for (int i = front1; i < rear1; i++)
    {
        q1[i] = q1[i + 1];
    }

    rear1--;
}

// DISPLAY operation
void display()
{
    if (front1 > rear1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }

    cout << "Stack elements (top to bottom): ";

    for (int i = front1; i <= rear1; i++)
    {
        cout << q1[i] << " ";
    }

    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n--- Stack Using Two Queues ---";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                push(value);
                break;

            case 2:
                pop();
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
