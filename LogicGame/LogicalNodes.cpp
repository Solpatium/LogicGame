#include "LogicalNodes.h"

// 25% of being negated
const double LogicalNode::negationChance(0.25);

LogicalNode::LogicalNode(){
    negated = Random::get() < negationChance;
    left = right = nullptr;
    simplified = false;
}

LogicalNode::~LogicalNode(){
    delete left;
    delete right;
}

bool LogicalNode::isSimplified() {
    return simplified;
}

bool LogicalNode::isNegated() {
    return negated;
}


ConjunctionNode::ConjunctionNode( LogicConjunction type )
: LogicalNode(), type(type)
{}

ConjunctionNode::~ConjunctionNode() {
    // Empty
}

Trilean ConjunctionNode::getValue() {
    Trilean value = T;
    switch( type ) {
        case LogicConjunction::AND:
            value = left->getValue() && right->getValue();
        break;
        case LogicConjunction::OR:
            value = left->getValue() || right->getValue();
        break;
        case LogicConjunction::IMPL:
            value = left->getValue() >> right->getValue();
        break;
    }
   
    return negated ? !value : value;
}

string ConjunctionNode::senencesToNumbers( int& n ) {
    // Operator + first takes value of expression on the right, which hs to be processed later
    string to_return = left->senencesToNumbers( n );
    to_return = "( " +  to_return + " " + (char)type +  " " + right->senencesToNumbers(n) + " )";
    return negated ? "!" + to_return : to_return;
}

string ConjunctionNode::orderedSentences( int& n ) {
    // Operator + first takes value of expression on the right, which hs to be processed later
    string leftString = left->orderedSentences( n );
    return leftString + right->orderedSentences( n );
}

string ConjunctionNode::simplify() {
    
    if( isSimplified() ) {
        return getValue().toString();
    }
    
    if( left->isSimplified() && right->isSimplified() ) {
        simplified = true;
        if( negated ) {
            return "!" + (!getValue()).toString();
        } else {
            return getValue().toString();
        }
    }
    
    string to_return = "( " +  left->simplify() + " " + (char)type +  " " + right->simplify() + " )";
    return negated ? "!" + to_return : to_return;
    
}

SentenceNode::SentenceNode( LogicalSentence* sentence )
: LogicalNode(), sentence(sentence) {
    // Empty
}

SentenceNode::~SentenceNode() {
    delete sentence;
}

Trilean SentenceNode::getValue() {
    return negated ? !sentence->getValue() : sentence->getValue();
}

string SentenceNode::senencesToNumbers( int& n ) {
    n++;
    return negated ? "!" + to_string(n) : to_string(n);
}

string SentenceNode::orderedSentences( int& n ) {
    n++;
    return to_string( n ) + ": " + sentence->getSentence() + "\n";
}

string SentenceNode::simplify() {
    if( negated ) {
        if( !simplified ) {
            simplified = true;
            return "!" + sentence->getValue().toString();
        } else
        {
            return getValue().toString();
        }
    } else {
        simplified = true;
        return sentence->getValue().toString();
    }
}