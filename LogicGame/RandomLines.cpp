#include "RandomLines.h"

RandomLines::RandomLines() {
    trueLines = new RandomLineTaker("true.txt");
    falseLines = new RandomLineTaker("false.txt");
    unknownLines = new RandomLineTaker("unknown.txt");
}

RandomLines& RandomLines::getInstance() {
    static RandomLines singleton;
    return singleton;
}

LogicalSentence* RandomLines::getTrue() {
    return new LogicalSentence(trueLines->getLine(), T);
}

LogicalSentence* RandomLines::getFalse() {
    return new LogicalSentence(falseLines->getLine(), F);
}

LogicalSentence* RandomLines::getUnknown() {
    return new LogicalSentence(unknownLines->getLine(), U);
}
