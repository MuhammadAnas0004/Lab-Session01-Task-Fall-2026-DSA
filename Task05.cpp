#include <iostream>
using namespace std;
class array2d
{
private:
    int m, n; // m is number of ms and n is number of numns
    int **arr;

public:
    array2d(int r, int c) : m(r), n(c)
    {
        arr = new int *[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = new int[n];
        }
    }
    void arrayinput()
    {
        cout << "Enter Elements in a Matrix : " << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    void display()
    {
        cout << "Matrix is : " << endl;
        for (int i = 0; i < m; i++)
        {
            cout << "|";
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "|" << endl;
        }
    }
    bool binarysearch(int target)
    {
        int l = 0;
        int h = (m * n) - 1; // 9 -1 = 8 so 0 to 8 means 9 elements
        int mid, row, col;
        while (l <= h)
        {
            mid = (l + h) / 2; // flattened array assummed
            row = mid / n;     // evaluates how many rows does the mid crossed
            col = mid % n;     // evaluates how many elements in the existing row does the mid crossed
            if (target == arr[row][col])
            {
                return true;
            }
            else if (arr[row][col] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return false;
    }
    ~array2d()
    {
        for (int i = 0; i < m; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
int main()
{
    array2d a1(3, 4);
    a1.arrayinput();
    a1.display();
    bool result = a1.binarysearch(3);
    if (result)
    {
        cout << "found!" << endl;
    }
    else
    {
        cout << "not 1found!" << endl;
    }
}