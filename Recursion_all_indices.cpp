// To Find index of required element in an array

#include <iostream>
using namespace std;

int count = -1;
int *Find(int arr[], int size, int n, int buff[])
{
    ++count;
    if (size == 1)
    {
        if (arr[size - 1] == n)
        {
            buff[count] = 1;
            return buff;
        }

        else
        {
            return buff;
        }
    }

    if (arr[0] == n)
    {
        buff[count] = 1;
        Find(arr + 1, size - 1, n, buff);
    }
    else
    {
        return Find(arr + 1, size - 1, n, buff);
    }
}

int main()
{
    int arr[1000];
    int size, n;

    cout << "Enter No. of elements: " << endl;
    cin >> size;
    int buff[size];
    for (int i = 0; i < size; i++)
    {
        buff[i] = -1;
    }

    cout << "Enter your elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number you want to find: " << endl;
    cin >> n;
    int *indices = Find(arr, size, n, buff);

    cout << "Element presence array:" << endl;
    for (int i = 0; i < size; i++)
    {
        if (indices[i] == 1)
        {
            cout << i << " ";
        }
    }
}