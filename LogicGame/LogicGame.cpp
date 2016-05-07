#include "LogicGame.h"

LogicGame::LogicGame()
: level(nullptr) {
    
};

void LogicGame::play() {
    
    // Rules
    printGreetingMessage();
    
    int lvl = 1;
    do {
        delete level;
        level = new Level(lvl);
        print();
        if (level->isRightAnswer(getAnswer())) {
            cout << "Congratulations! Your answer is correct.\n\n";
            lvl++;
        } else {
            cout << "Sorry, this is not a correct answer!\n" << endl
                 << "This is a solution:" << endl << level->getCorrectAnswer();
            
            break;
        }
    } while (lvl <= last_level);
    
    cout << endl;
    if( lvl == 1 ) {
        cout << "Well... You are not good at logic, are you?\n";
    } else
    if( lvl == 11 ) {
        cout << "WOOOOOOOOOOW, YOU WON THE GAME, RESPECT! This is your reward: \n";
    } else {
        cout << "That result is not bad, here is your prize: \n";
    }
    
    printBears( lvl-1 );
}

void LogicGame::printGreetingMessage() {
    cout << "Welcome to \"Logic Millionaires, but with virtual teddybears instead of money\" game! Answer logic questions with 1, 0 or x sign. Press ctrl+c to quit.\nThere are 10 questions waiting for you, have fun!\n";
}

void LogicGame::print() {
    cout << level->toString() << endl;
}

Trilean LogicGame::getAnswer() {
    char answer = getch();

    if (!isRightInput(answer))
        cout << "Wrong answer, use only 0 as false, 1 as true and x as unknown: ";

    while (!isRightInput(answer)) {
        answer = getch();
    }
    switch (answer) {
        case '1':
            return T;
            break;
        case '0':
            return F;
            break;
        case 'x':
            return U;
            break;
    }
}

char LogicGame::getch() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    if (isRightInput(buf))
        printf("%c\n", buf);
    return buf;
}

bool LogicGame::isRightInput(char a) {
    return a == '1' || a == '0' || a == 'x';
}

void LogicGame::printBears(int n) {
    
    if( n==0 ) return;
    
    char bear[10][16] = {
        "   _     _   ",
        "  (o\\---/o)  ",
        "   ( . . )   ",
        "  _( (T) )_  ",
        " / /     \\ \\ ",
        "/ /       \\ \\",
        "\\_)       (_/",
        "  \\   _   /  ",
        "  _)  |  (_  ",
        " (___,'.___) "
    };
    for( int j=0; j<10; j++) {
        for( int i=0; i<n; i++ ) 
            cout << bear[j];
        cout << endl;
    }
}