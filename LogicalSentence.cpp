#include "LogicalSentence.h"

LogicalSentence::LogicalSentence( std::string sentence, TrinaryLogic::Trilean logicalValue )
{
    this->sentence = sentence;
    this->logicalValue = logicalValue;
}

Trilean LogicalSentence::getValue()
{
    return logicalValue;
}

string LogicalSentence::getSentence() {
    return sentence;
}

ostream& operator<< ( ostream &output, LogicalSentence& logicalSentence )
{
    return output << logicalSentence.sentence;
}
