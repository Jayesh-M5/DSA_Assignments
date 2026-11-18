
#include <iostream>
#include <string>
using namespace std;

// Sentinel Search
int sentinelSearch(string names[], int n, string key)
{
    names[n] = key;    // Set sentinel

    int i = 0;

    while (names[i] != key)
    {
        i++;
    }

    if (i < n)
        return i;
    else
        return -1;
}

// Insert friend in sorted order
void insertFriend(string names[], string mobile[], int &n)
{
    string name, number;

    cout << "\nEnter friend name: ";
    cin >> name;

    // Check if friend already exists
    int index = sentinelSearch(names, n, name);

    if (index != -1)
    {
        cout << "Friend already exists in phone book.\n";
        return;
    }

    cout << "Enter mobile number: ";
    cin >> number;

    // Find correct position
    int pos = 0;

    while (pos < n && names[pos] < name)
    {
        pos++;
    }

    // Shift elements
    for (int i = n; i > pos; i--)
    {
        names[i] = names[i - 1];
        mobile[i] = mobile[i - 1];
    }

    // Insert new friend
    names[pos] = name;
    mobile[pos] = number;

    n++;

    cout << "Friend added successfully.\n";
}

// Search friend
void searchFriend(string names[], string mobile[], int n)
{
    string name;

    cout << "\nEnter friend name to search: ";
    cin >> name;

    int index = sentinelSearch(names, n, name);

    if (index != -1)
    {
        cout << "\nFriend Found!\n";
        cout << "Name : " << names[index] << endl;
        cout << "Mobile : " << mobile[index] << endl;
    }
    else
    {
        cout << "Friend not found.\n";
    }
}

// Display phone book
void display(string names[], string mobile[], int n)
{
    if (n == 0)
    {
        cout << "\nPhone book is empty.\n";
        return;
    }

    cout << "\n------- PHONE BOOK -------\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". "
             << names[i] << " - "
             << mobile[i] << endl;
    }
}

int main()
{
    string names[101];
    string mobile[101];

    int n = 0;
    int choice;

    do
    {
        cout << "\n\n===== PHONE BOOK MENU =====";
        cout << "\n1. Insert Friend";
        cout << "\n2. Search Friend";
        cout << "\n3. Display Phone Book";
        cout << "\n4. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertFriend(names, mobile, n);
                break;

            case 2:
                searchFriend(names, mobile, n);
                break;

            case 3:
                display(names, mobile, n);
                break;

            case 4:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 4);

    return 0;
}
