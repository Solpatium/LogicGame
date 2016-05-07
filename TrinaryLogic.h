#ifndef TRINARYLOGIC_H
#define TRINARYLOGIC_H

#include "include.h"

using namespace std;

// Singleton class used for handling trinary logic
class TrinaryLogic
{
    public:
        
        enum LogicConjunction {
            AND = '^',
            OR = 'v',
            IMPL = '>'
        };

        enum LogicValue
        {
            False = 0,
            True = 1,
            Unknown = 2
        };

        // Class used for storing logical value
        class Trilean
        {

            public:

                // Constructors
                Trilean();
                Trilean( LogicValue val );
                Trilean( const Trilean& t );

                // Not operator
                Trilean operator!() const;

                // And operator
                Trilean operator&&( const Trilean& t ) const;

                // Or operator
                Trilean operator||( const Trilean& t ) const;

                // Implication operator
                Trilean operator>>( const Trilean& t ) const;

                // Assigment operator
                Trilean operator=( const Trilean& t );
                
                // Comparison operator
                bool operator==( const Trilean& t ) const;
                
                string toString() const;

                // Value
                LogicValue value;
        };
        

        // Getter for instance
        static TrinaryLogic& getInstance();

        Trilean lNot( Trilean t );

        Trilean lAnd( Trilean t1, Trilean t2 );

        Trilean lOr( Trilean t1, Trilean t2 );

        Trilean lImpl( Trilean t1, Trilean t2 );

        void loadLogicFromFiles( string notFile, string andFile, string orFile, string implFile );

    private:
        
        bool hasRightValue( int a );
        
        void loadLogicFromFile( string name, Trilean operand[][3], bool isNot = false );

        // Logic values for logical operands
        Trilean Not[3][3];
        Trilean And[3][3];
        Trilean Or[3][3];
        Trilean Impl[3][3];

        // Private constructor
        TrinaryLogic();
};

/* Typedefs */
typedef TrinaryLogic::Trilean Trilean;
typedef TrinaryLogic::LogicValue LogicValue;
typedef TrinaryLogic::LogicConjunction LogicConjunction;

/* Constants */
const Trilean T = Trilean( LogicValue::True );
const Trilean F = Trilean( LogicValue::False );
const Trilean U = Trilean( LogicValue::Unknown );


#endif /* TRINARYLOGIC_H */

