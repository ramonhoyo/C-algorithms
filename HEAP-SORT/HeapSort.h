#ifndef HEAPSORT_H
#define HEAPSORT_H


class HeapSort
{
public:
    HeapSort();
    static void sort(int * array,int n);

private:
    static void heapify(int *array,int n, int i);
};

#endif // HEAPSORT_H
