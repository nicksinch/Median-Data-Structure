# Median-Data-Structure
EDIT: The repo is a little bit large because of Google Test Framework.


IMPORTANT: To run the project, you should clone the repo and open the folder 'MedianDataStructure' without changing
this folder's name and open it with an IDE.


A class that represents a data structure MedianHeap which supports two operations:
Insert (in O(log(n)) time complexity.
GetMedian (in O(1)) time complexity.
To achieve this I have used the STL priority_queue which by default behaves like a max heap
and a modified priority_queue which behaves like a min heap. The benefit of this approach (using STL priority_queue)
is that it automatically heapify's it and we can't accidentally violate the heap invariant.

You can construct a MedianHeap in two ways:
1) Either by passing an already existing vector of ints with N random elements
   - this will invoke the constructor that takes const vector<int>&
2) Or you can construct it from scratch ( by inserting elements one by one )
   -this will invoke the default constructor

There are also some functions for testing all the possible cases that can occur and for this purpose
Google test framework is used.

To run them all by once, simply execute main.cpp
If you want to run separate test cases , go to Google_tests/test.cpp file and run whichever needed.

Everything tested on CLion and Visual Studio.
