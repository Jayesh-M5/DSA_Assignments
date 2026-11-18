
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char dq[100];

    int front = -1, rear = -1;

    string str;

    cout << "Enter a string: ";
    cin >> str;

    // Insert characters into deque
    for (int i = 0; i < str.length(); i++)
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }

        dq[rear] = str[i];
    }

    // Check palindrome
    while (front < rear)
    {
        if (dq[front] != dq[rear])
        {
            cout << "String is not Palindrome";
            return 0;
        }

        front++;
        rear--;
    }

    cout << "String is Palindrome";

    return 0;
}
