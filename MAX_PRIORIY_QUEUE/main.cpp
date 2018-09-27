#include <QCoreApplication>
#include <iostream>
#include <vector>

#include "maxpriorityqueue.h"

void printVec(std::vector<int>& v)
{
    for(const auto& it: v )
        std::cout<< it << " ";
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int> h;
    h.push_back(15);
    h.push_back(13);
    h.push_back(9);
    h.push_back(5);
    h.push_back(12);
    h.push_back(8);
    h.push_back(7);
    h.push_back(4);
    h.push_back(0);
    h.push_back(6);
    h.push_back(2);
    h.push_back(1);

    printVec(h);

    std::make_heap(h.begin(),h.end());

    printVec(h);
    std::cout<< heapExtractMax(h) << std::endl;
    printVec(h);    
    std::cout<< heapExtractMax(h) << std::endl;
    printVec(h);

    std::cout<<"Increase key"<<std::endl;
    heapIncreaseKey(h,3,20);

    printVec(h);
    std::cout<<"Increase key"<<std::endl;
    heapIncreaseKey(h,3,21);

    printVec(h);

    std::cout<< "insert key \n";
    heapInsert(h,30);
    printVec(h);
    heapInsert(h,7);
    printVec(h);

    std::make_heap(h.begin(),h.end());
    printVec(h);

    return a.exec();
}
