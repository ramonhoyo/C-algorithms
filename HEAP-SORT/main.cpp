#include <QCoreApplication>
#include <iostream>

#include "HeapSort.h"

void printArray(int *array,int n)
{
    for(int i=0; i<n; ++i)
        std::cout<< array[i] << " ";
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int arr[10] = {10,2,4,5,39,1,100,43,21,9};

    printArray(arr,10);

    HeapSort::sort(arr,10);

    printArray(arr,10);

    return a.exec();
}
