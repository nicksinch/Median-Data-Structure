#include "MedianHeap.h"
#include "EmptyMedianException.h"

MedianHeap::MedianHeap(const std::vector<int> &Sequence)
{
    unsigned int SequenceSize = Sequence.size();

    for(int i = 0; i < SequenceSize;++i)
        this->Insert(Sequence[i]);
}

MedianHeap::MedianHeap(){}

bool MedianHeap::IsEmpty() const
{
    return this->MaxHeap.empty() && this->MinHeap.empty();
}

double MedianHeap::GetMedian() const
{
    if(IsEmpty()) // No median to return in this case
    {
        throw EmptyMedianException(); // so indicating this with an exception
    }

    unsigned int CurrentMaxHeapSize = this->MaxHeap.size();
    unsigned int CurrentMinHeapSize = this->MinHeap.size();

    // The two middle elements are the roots of each heap ( even-sized sequence ), so we take the average
    if(CurrentMaxHeapSize == CurrentMinHeapSize)
        return (double)(this->MaxHeap.top() + this->MinHeap.top()) / 2;
    else if(CurrentMaxHeapSize > CurrentMinHeapSize) // Otherwise the larger heap's root has the median
        return MaxHeap.top();
    else return MinHeap.top();
}

void MedianHeap::Insert(int el)
{
    // The first element of the sequence is always pushed into the Max Heap
    if(IsEmpty())
    {
        this->MaxHeap.push(el);
        return;
    }
    else if(this->MinHeap.empty()) // this check is enough to insert the second element into the Min Heap
    {
        this->MinHeap.push(el);
        return;
    }

    double CurrentMedian = GetMedian(); // > 2 items in the sequence if we get to this line
    // By definition Max Heap has all the elements that are left from the median including the median
    if(el <= CurrentMedian)
        this->MaxHeap.push(el);
    else // And Min has all the elements right from the median
        this->MinHeap.push(el);

    int CurrentMaxHeapSize = this->MaxHeap.size();
    int CurrentMinHeapSize = this->MinHeap.size();

    /* Def: We will say that two trees are balanced to each other if the number of their elements differ at most by 1.
     * The reason we do the two if's below is that after insertion, we also want to guarantee that the
     * two trees (heaps) are balanced because we always want about one half of the sequence to be stored in each heap
     * so that we can always know where the middle (odd sequence) or two middle elements (even sequence) are. */

    if(CurrentMaxHeapSize - CurrentMinHeapSize > 1)
    {
        int ExtractMax = this->MaxHeap.top();
        this->MaxHeap.pop();
        this->MinHeap.push(ExtractMax);
    }
    else if(CurrentMinHeapSize - CurrentMaxHeapSize > 1)
    {
        int ExtractMin = this->MinHeap.top();
        this->MinHeap.pop();
        this->MaxHeap.push(ExtractMin);
    }
}