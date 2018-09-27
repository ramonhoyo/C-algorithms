#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <vector>

std::vector<int> counting_sort(std::vector<int> v,int key)
{
    std::vector<int> index(key,0);
    std::vector<int> result(v.size());
    for(int i=0; i<v.size(); ++i)
         index[v[i]]++;
    for(int i=1; i<index.size();++i)
        index[i] += index[i-1];
    for(int i=v.size()-1; i>=0; --i)
        result[index[v[i]]--] = v[i];
}


#endif // COUNTINGSORT_H
