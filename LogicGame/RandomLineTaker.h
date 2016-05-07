#ifndef RANDOMLINETAKER_H
#define RANDOMLINETAKER_H

#include "../include.h"

class RandomLineTaker {
public:
    RandomLineTaker( string fileName );
    string getLine();
private:
    vector<string> lines;
    int index;
};

#endif /* RANDOMLINETAKER_H */

