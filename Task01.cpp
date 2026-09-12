#include <iostream>
using namespace std;
class array2d
{
private:
    int row, col;
    int **arr;

public:
    array2d(int r, int c) : row(r), col(c)
    {
        arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }
    }
    void arrayinput()
    {
        cout << "Enter Elements in a Matrix : " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    void display()
    {
        cout << "Matrix is : " << endl;
        for (int i = 0; i < row; i++)
        {
            cout << "|";
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "|" << endl;
        }
    }
    void copy()
    {
        int *arr1 = new int[row * col];
        int index = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr1[index] = arr[j][i];
                index++;
            }
        }
        cout<<"Column Major : ";
        for(int i = 0; i < row * col; i++){
            cout<<arr1[i]<<" ";
        }
    }
    ~array2d()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
int main()
{
    int rows,cols;
    cout<<"Enter Number of rows : ";
    cin>>rows;
    cout<<"Enter number of Columns : ";
    cin>>cols;
    array2d a(rows,cols);
    a.arrayinput();
    a.display();
    a.copy();
}