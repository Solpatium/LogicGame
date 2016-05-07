#ifndef LOGICALSENTENCE_H
#define LOGICALSENTENCE_H

#include "include.h"
#include "TrinaryLogic.h"

class LogicalSentence
{
    public:

        LogicalSentence( string sentence, TrinaryLogic::Trilean logicalValue );

        friend ostream&  operator<< ( ostream &output, LogicalSentence& logicalSentence );

        Trilean getValue();
        
        string getSentence();

    protected:

        string sentence;

        Trilean logicalValue;
};

#endif /* LOGICALSENTENCE_H */

