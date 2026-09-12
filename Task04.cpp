#include <iostream>
using namespace std;
int main()
{
    int n, i, j, target, temp;
    cout << "Enter the size of array : ";
    cin >> n;
    int *arr = new int[n];
    // int arr[n];
    cout << "Enter elements in the array : ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Sorting in Ascending Order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"Sorted Array : ";
    for(i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Searching
    int l = 0;     // first index
    int h = n - 1; // last index
    int mid;       // (l + h)/ 2 return the index of the middle value
    bool found = false;
    cout << "Enter number to search : ";
    cin >> target;
    while (l <= h)
    {
        mid = (l + h) / 2;
        {
            if (target == arr[mid])
            {
                cout << "Element Found at : " << mid << endl;
                found = true;
                break;
            }
            else if (target < arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    if (!found)
    {
        cout << "Target not Found" << endl;
    }
    delete []arr;
    return 0;
}