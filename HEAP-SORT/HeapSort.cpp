#include "HeapSort.h"

#include <utility>

#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2

HeapSort::HeapSort()
{

}

void HeapSort::sort(int* array ,int n)
{
    for(int i= n/2-1; i>=0; --i)
        heapify(array, n, i);

    for(int i=n-1; i>0 ;--i)
    {
        std::swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void HeapSort::heapify(int *array, int n, int i)
{
    int largest = i;
    int l = LEFT(i);
    int r = RIGHT(i);

    if(l < n and array[l] > array[largest])
        largest = l;
    if(r < n and array[r] > array[largest])
        largest = r;

    if(largest != i){
        std::swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}
