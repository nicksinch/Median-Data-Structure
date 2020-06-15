#include <iostream>
#include "../EmptyMedianException.h"
#include "../MedianHeap.h"
#include "gtest/gtest.h"

TEST(ConstructorSuite, ConstructFromExistingVector){
    std::vector<int> v;
    for(int i = 0; i < 30; ++i)
        v.push_back(i);
    MedianHeap existingHeap(v);
    EXPECT_EQ(existingHeap.GetMedian(), 14.5);
}

TEST(TrickySequenceSuite, AlotOfNumbers){
    std::vector<int> v;
    for(int i = 0; i < 300; ++i)
        v.push_back(i);
    MedianHeap existingHeap(v);
    EXPECT_EQ(existingHeap.GetMedian(), 149.5);
}

TEST(TrickySequenceSuite, EmptySequence){
    MedianHeap even;
    ASSERT_THROW(even.GetMedian(), EmptyMedianException);
}

TEST(TrickySequenceSuite, HasOnlyOneElement){
    MedianHeap even;
    even.Insert(5);
    EXPECT_EQ(even.GetMedian(), 5);
}

TEST(TrickySequenceSuite, HasTwoElements){
    MedianHeap even;
    even.Insert(1);
    even.Insert(6);
    EXPECT_EQ(even.GetMedian(), 3.5);
}

TEST(EvenSequenceSuite, PositiveNotSorted){
    MedianHeap even;
    even.Insert(5);
    even.Insert(6);
    even.Insert(8);
    even.Insert(1);
    even.Insert(24);
    even.Insert(15);
    EXPECT_EQ(even.GetMedian(), 7);
}

TEST(EvenSequenceSuite, HasNegativeNotSorted){
    MedianHeap even;
    even.Insert(5);
    even.Insert(6);
    even.Insert(-8);
    even.Insert(1);
    even.Insert(-24);
    even.Insert(15);
    EXPECT_EQ(even.GetMedian(), 3);
}

TEST(OddSequenceSuite, PositiveNotSorted){
    MedianHeap odd;
    odd.Insert(5);
    odd.Insert(6);
    odd.Insert(8);
    odd.Insert(1);
    odd.Insert(24);
    EXPECT_EQ(odd.GetMedian(), 6);
}

TEST(OddSequenceSuite, OddDuplicates){
    MedianHeap odd;
    odd.Insert(2);
    odd.Insert(2);
    odd.Insert(2);
    odd.Insert(2);
    odd.Insert(2);
    EXPECT_EQ(odd.GetMedian(), 2);
}

TEST(EvenSequenceSuite, EvenDuplicates){
    MedianHeap even;
    even.Insert(2);
    even.Insert(2);
    even.Insert(2);
    even.Insert(2);
    EXPECT_EQ(even.GetMedian(), 2);
}

