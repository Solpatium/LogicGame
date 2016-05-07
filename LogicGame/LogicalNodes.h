#ifndef LOGICALNODES_H
#define LOGICALNODES_H

#include "../include.h"
#include "../TrinaryLogic.h"
#include "../LogicalSentence.h"


class LogicalNode {
    
public:
    LogicalNode();
    virtual ~LogicalNode();

    virtual Trilean getValue() = 0;
    
    virtual string senencesToNumbers( int& n ) = 0;
    
    virtual string orderedSentences( int& n ) = 0;
    
    virtual string simplify() = 0;
    
    bool isSimplified();
    
    bool isNegated();
    
    LogicalNode* left,
               * right;
    
protected:
    
    bool simplified;

    bool negated;
    
private:

    static const double negationChance;
    
};

class ConjunctionNode : public LogicalNode {
public:
    ConjunctionNode(LogicConjunction type);
    string senencesToNumbers( int& n );
    string orderedSentences( int& n );
    string simplify();
    Trilean getValue();
    ~ConjunctionNode();

private:
    LogicConjunction type;

};

class SentenceNode : public LogicalNode {
public:
    SentenceNode(LogicalSentence* sentence );
    string senencesToNumbers( int& n );
    string orderedSentences( int& n );
    string simplify();
    Trilean getValue();
    ~SentenceNode();

private:
    LogicalSentence* sentence;


};

#endif /* LOGICALNODES_H */

