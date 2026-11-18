
#include <iostream>
using namespace std;

#define SIZE 100

int s1[SIZE], s2[SIZE];

int top1 = -1, top2 = -1;

// ENQUEUE operation
void enqueue(int x)
{
    if (top1 == SIZE - 1)
    {
        cout << "Queue is full!" << endl;
        return;
    }

    s1[++top1] = x;

    cout << x << " inserted into queue." << endl;
}

// DEQUEUE operation
void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    if (top2 == -1)
    {
        while (top1 != -1)
        {
            s2[++top2] = s1[top1--];
        }
    }

    cout << "Deleted element: " << s2[top2--] << endl;
}

// DISPLAY operation
void display()
{
    if (top1 == -1 && top2 == -1)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements: ";

    for (int i = top2; i >= 0; i--)
    {
        cout << s2[i] << " ";
    }

    for (int i = 0; i <= top1; i++)
    {
        cout << s1[i] << " ";
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
