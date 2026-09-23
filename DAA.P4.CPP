#include <iostream>
using namespace std;

// Recursive Method
int factorialRecursive(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

// Iterative Method
int factorialIterative(int n)
{
    int fact = 1;

    for(int i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial using Iterative Method = "
         << factorialIterative(n) << endl;

    cout << "Factorial using Recursive Method = "
         << factorialRecursive(n) << endl;

    return 0;
}
