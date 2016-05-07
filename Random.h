#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>
#include <ctime>

class Random {
public:
    
    static double get();
    
    static const int MAX = RAND_MAX;

private:
    
    Random();

};

#endif /* RANDOM_H */

