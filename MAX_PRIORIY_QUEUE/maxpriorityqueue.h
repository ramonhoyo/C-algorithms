#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2
#define PARENT(i) i/2

#include <utility>
#include <vector>


void heapify(std::vector<int>& heap, int i);
int heapExtractMax(std::vector<int>& heap);
void heapIncreaseKey(std::vector<int>& heap,int i, int k);
void heapInsert(std::vector<int>& heap, int k);


int heapExtractMax(std::vector<int>& heap)
{
    if(heap.empty())
        throw "heap underflow";

    int max = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    heapify(heap,0);

    return max;
}

void heapIncreaseKey(std::vector<int>& heap,int i, int k){
    if(k < heap[i])
        throw "invalid new key assignation";
    heap[i] = k;
    while(i>0 and heap[PARENT(i)] < heap[i]){
        std::swap(heap[i], heap[PARENT(i)]);
        i = PARENT(i);
    }
}

void heapInsert(std::vector<int>& heap, int k){
    heap.push_back(-1000000);
    heapIncreaseKey(heap,heap.size()-1,k);
}

void heapify(std::vector<int>& heap, int i)
{
    int largest = i;
    int l = LEFT(i);
    int r = RIGHT(i);

    if(l < heap.size() and heap[l] > heap[largest])
        largest = l;
    if(r < heap.size() and heap[r] > heap[largest])
        largest = r;

    if(largest != i){
        std::swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}
