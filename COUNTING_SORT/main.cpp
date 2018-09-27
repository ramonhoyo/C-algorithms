#include <QCoreApplication>
#include <vector>
#include <iostream>

std::vector<int> counting_sort(std::vector<int> &v)
{
    int key = std::max_element(v.begin(),v.end());
    std::vector<int> index(key+1,0);
    std::vector<int> result(v.size());
    for(int i=0; i<v.size(); ++i)
         index[v[i]]++;
    for(int i=1; i<index.size();++i)
        index[i] += index[i-1];
    for(int i=(int)v.size()-1; i>=0; --i)
        result[(index[v[i]]--)-1] = v[i];
    return result;
}

void printVec(std::vector<int>&v)
{
    for(auto &it : v)
    {
        std::cout<< it << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int myInts[] = {2,5,3,0,2,3,0,3,7,6,8,9,1,12};
    std::vector<int> v(myInts, myInts + sizeof(myInts)/sizeof(int) );

    std::vector<int> r = counting_sort(v);
    printVec(r);


    return a.exec();
}
