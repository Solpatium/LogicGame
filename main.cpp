#include "include.h"
#include "TrinaryLogic.h"
#include "LogicalSentence.h"
#include "LogicGame/LogicPlaything.h"
#include "LogicGame/RandomLineTaker.h"
#include "LogicGame/RandomLines.h"
#include "LogicGame/LogicGame.h"
#include "Parser.h"

int main(int argc, const char** argv) {
    
    try {
        //Pass to parser only program arguments
        Parser parser(argc - 1, argv + 1);

        // Setting logic from files
        TrinaryLogic::getInstance().loadLogicFromFiles(parser.getNot(), parser.getAnd(), parser.getOr(), parser.getImpl());
    }    
    // Invalid arguments given to program or wrong option in file supplied
    catch (const runtime_error& re) {
        cerr << re.what() << endl;
        return -2;
    }
    // Invalid arguments given to program
    catch (const invalid_argument& ia) {
        cerr << ia.what() << endl;
        return -2;
    }    


    LogicGame game;
    game.play();

    return 0;
}

