#ifndef MEDIANDATASTRUCTURE_MEDIANHEAP_H
#define MEDIANDATASTRUCTURE_MEDIANHEAP_H

#include <vector>
#include <queue>
#include <iostream>


class MedianHeap{
private:
    std::priority_queue<int> MaxHeap;
    std::priority_queue<int,std::priority_queue<int>::container_type, std::greater<int>>MinHeap;
public:
    MedianHeap(const std::vector<int> &); // Constructor to make a structure by an existing vector
    MedianHeap(); // Constructor to make a structure from scratch
    void Insert(int);
    double GetMedian() const;
    bool IsEmpty() const;
};


#endif //MEDIANDATASTRUCTURE_MEDIANHEAP_H
