#ifndef LOGICPLAYTHING_H
#define LOGICPLAYTHING_H

#include <queue>
#include "LogicalNodes.h"
#include "RandomLines.h"

class LogicPlaything {
    
public:
    LogicPlaything( short int difficulty );
    ~LogicPlaything();
    string toString();
    Trilean getAnswer();
    string getSolve();
    
private:
    void generatePlaything();
    ConjunctionNode* randomConjunction();
    SentenceNode*   randomSentence();
    short int difficulty;
    LogicalNode* root;
    
    
 
};

#endif /* LOGICPLAYTHING_H */

