#include "Level.h"

// Difficulty raises once every two levels

Level::Level(short int level)
: level(level), question(level / 3 + 1) {

}

bool Level::isRightAnswer(Trilean t)
{
    return t == question.getAnswer();
}

string Level::toString()
{
    string toReturn = "=========================================================================================\n";
    toReturn += "Level " + to_string(level) + ": answer correctly and you'll get " + getPrize() + "\n\n";
    
    toReturn += question.toString();
    
    return toReturn;
}

string Level::getPrize() {
    return to_string(level) + (level >= 2 ? " virtual teddybears!" : " virtual teddybear!");
}

string Level::getCorrectAnswer() {
    return question.getSolve();
}