#ifndef PARSER_H
#define PARSER_H

#include "include.h"

class Parser {
public:
    Parser(int n, const char* argv[]);

    string getNot();
    string getAnd();
    string getOr();
    string getImpl();

private:

    string Not,
           And,
           Or,
           Impl;

    string* whichOption(string arg);

};

#endif /* PARSER_H */

