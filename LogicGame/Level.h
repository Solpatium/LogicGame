#ifndef LEVEL_H
#define LEVEL_H

#include "../include.h"
#include "LogicPlaything.h"

class Level {
public:
    Level(short int level);
    
    bool isRightAnswer( Trilean t );
    
    string getCorrectAnswer();
    
    string toString();
    
    string getPrize();
    
private:
    short int level;
    LogicPlaything question;
};

#endif /* LEVEL_H */

