#include "Parser.h"

Parser::Parser(int n, const char* argv[] ) {
    Not = And = Or = Impl = "";

    // Parse arguments
    string option, *argument;
    for (int i = 0; i < n; i++) {
        
        option = argv[i];

        argument = whichOption(option);
        if (argument == nullptr)
            throw invalid_argument("Option " + option + " is unknown, you can only use options: --not, --and, --or, --impl for specyfing logic files");

        // Option is valid, check it's argument
        i++;
        if (i == n)
            throw invalid_argument("Option " + option + " has been given without logic file specified");

        // Option and argument are valid
        *argument = argv[i];
    }
}

string* Parser::whichOption(string arg) {
    if( arg == "--not" ) return &Not;
    if( arg == "--and" ) return &And;
    if( arg == "--or" ) return &Or;
    if( arg == "--impl" ) return &Impl;
    return nullptr;
}

string Parser::getNot() {
    return Not;
}

string Parser::getAnd() {
    return And;
}

string Parser::getOr() {
    return Or;
}

string Parser::getImpl() {
    return Impl;
}