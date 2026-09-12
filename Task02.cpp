#include <iostream>
using namespace std;
int main()
{
    float **jagged = new float *[5];
    int size[5], i, j, k;
    for (i = 0; i < 5; i++)
    {
        cout << "Enter courses of student " << i + 1 << " : ";
        cin >> size[i];
        jagged[i] = new float[size[i]];
        for (j = 0; j < size[i]; j++)
        {
            cout << "Enter CGPA of course " << j + 1 << " : ";
            cin >> jagged[i][j];
        }
    }
    // calculating gpa;
    float sum = 0;
    int ch;
    for (i = 0; i < 5; i++)
    {
        float sum = 0;
        int ch;
        for (j = 0; j < size[i]; j++)
        {
            jagged[i][j] = jagged[i][j] * 3;
            sum = sum + jagged[i][j];
        }
        ch = size[i] * 3;
        cout << "GPA of Student " << i + 1 << " : " << sum / ch << endl;
    }
}