#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int a[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(a[mid] == key)
            return mid;

        if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int a[100], n, key, choice, result;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in sorted order: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> key;

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\nEnter choice: ";
    cin >> choice;

    if(choice == 1)
        result = linearSearch(a, n, key);
    else if(choice == 2)
        result = binarySearch(a, n, key);
    else
    {
        cout << "Wrong choice!";
        return 0;
    }

    if(result != -1)
        cout << "Element found at position: " << result + 1;
    else
        cout << "Element not found";

    return 0;
}
