#include "LogicPlaything.h"

LogicPlaything::LogicPlaything(short int difficulty)
: difficulty(difficulty) {
    generatePlaything();
}

LogicPlaything::~LogicPlaything() {
    delete root;
}

string LogicPlaything::toString() {
    int n = 0;
    string toReturn = root->orderedSentences(n) + "\n";
    n = 0;
    toReturn += root->senencesToNumbers(n) + " in trinary logic is:";
    return toReturn;
}

void LogicPlaything::generatePlaything() {
    queue<LogicalNode*> q;

    short int remaining = difficulty - 1;
    root = randomConjunction();
    q.push(root);

    LogicalNode* temp;

    // Proces all conjunction nodes
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        /* 
         * Chances are 50/50 for each node to be conjunction 
         */
        //left node
        if (remaining > 0 && Random::get() < 0.5) {
            temp->left = randomConjunction();
            q.push(temp->left);
            remaining--;
        }

        // right node
        if (remaining > 0 && Random::get() < 0.5) {
            temp->right = randomConjunction();
            q.push(temp->right);
            remaining--;
        }

        /*
         * If this was the last node to precess and we didn't add any conjunstions to it, while there are still conjunctions to make we have to add it anyway
         */
        if (q.empty() && remaining > 0) {
            // Neither left or right are conjunctions, if they were the queue woudn't be empty, let's prefer right child to add conjunction
            temp->right = randomConjunction();
            q.push(temp->right);
            remaining--;
        }

        /*
         * Any child being a null means we have to add sentence node
         */
        if (temp->right == nullptr) temp->right = randomSentence();
        if (temp->left == nullptr) temp->left = randomSentence();

    }
}

ConjunctionNode* LogicPlaything::randomConjunction() {
    double random = Random::get();

    if (random <= 1.0 / 3.0) {
        return new ConjunctionNode(LogicConjunction::AND);
    }
    else if (random <= 2.0 / 3.0) {
        return new ConjunctionNode(LogicConjunction::OR);
    }
    else {
        return new ConjunctionNode(LogicConjunction::IMPL);
    }
}

SentenceNode* LogicPlaything::randomSentence() {

    RandomLines randomLines = RandomLines::getInstance();

    double random = Random::get();

    if (random <= 1.0 / 3.0) {
        return new SentenceNode( randomLines.getTrue() );
    }
    else if (random <= 2.0 / 3.0) {
        return new SentenceNode( randomLines.getFalse() );
    }
    else {
        return new SentenceNode( randomLines.getUnknown() );
    }
}

Trilean LogicPlaything::getAnswer() {
    return root->getValue();
}

string LogicPlaything::getSolve() {
    string solve = "";
    
    while( !root->isSimplified() ) {
        solve += root->simplify() + "\n";
    }
    
    if( root->isNegated() )
        solve += root->simplify() + "\n";
    
    return solve;
}