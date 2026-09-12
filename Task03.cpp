#include <iostream>
using namespace std;

class MedianFinder
{
private:
    int *arr;
    int size;     // how many elements are currently stored
    int capacity; // how much space is currently allocated

    // Doubles the array size when full
    void resize()
    {
        capacity = capacity * 2;
        int *newArr = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

public:
    // Constructor
    MedianFinder()
    {
        capacity = 4; // start with small capacity
        size = 0;
        arr = new int[capacity];
    }

    void addNum(int num)
    {
        // Step 1: resize if full
        if (size == capacity)
        {
            resize();
        }

        // Step 2: find correct sorted position (linear search from the end)
        int i = size - 1;
        while (i >= 0 && arr[i] > num)
        {
            arr[i + 1] = arr[i]; // shift element right
            i--;
        }
        arr[i + 1] = num; // place num in its correct sorted spot

        size++;
    }

    double findMedian()
    {
        if (size % 2 == 1)
        {
            return arr[size / 2];
        }
        else
        {
            return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        }
    }

    // Destructor — cleanup
    ~MedianFinder()
    {
        delete[] arr;
    }
};

int main()
{
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // 1.5

    mf.addNum(3);
    cout << mf.findMedian() << endl; // 2.0

    return 0;
}