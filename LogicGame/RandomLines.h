#ifndef RANDOMLINES_H
#define RANDOMLINES_H

#include "../include.h"
#include "../LogicalSentence.h"
#include "RandomLineTaker.h"

class RandomLines {
public:
    
    static RandomLines& getInstance();

    LogicalSentence* getTrue();

    LogicalSentence* getFalse();

    LogicalSentence* getUnknown();

private:

    RandomLines();
    
    RandomLineTaker* trueLines,
                   * falseLines,
                   * unknownLines;


};

#endif /* RANDOMLINES_H */

