//
// Created by nicks on 6/13/2020.
//

#ifndef MEDIANDATASTRUCTURE_EMPTYMEDIANEXCEPTION_H
#define MEDIANDATASTRUCTURE_EMPTYMEDIANEXCEPTION_H

#include "MedianHeap.h"

class EmptyMedianException: public std::exception {
    virtual const char* what() const throw()
    {
        return "Empty Median!";
    }
};


#endif //MEDIANDATASTRUCTURE_EMPTYMEDIANEXCEPTION_H
