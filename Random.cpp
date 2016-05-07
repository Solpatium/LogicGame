#include "Random.h"

Random::Random() {
    srand( time(nullptr) );
}

double Random::get() {
    static Random initializeOnce;
    return (double)rand()/(double)MAX;
}


