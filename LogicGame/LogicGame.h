#ifndef LOGICGAME_H
#define LOGICGAME_H

#include "../include.h"
#include "Level.h"
#include <unistd.h>   //_getch
#include <termios.h>  //_getch

class LogicGame {
public:
    LogicGame();
    
    void play();
    
    void print();
    
    Trilean getAnswer();

private:
    
    void printGreetingMessage();
    
    char getch();
    
    bool isRightInput( char a );
    
    // Current level
    Level* level;
    
    // Winning level
    static const unsigned short int last_level = 10;
    
    void printBears(int n );
     

};

#endif /* LOGICGAME_H */

