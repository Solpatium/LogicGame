#include "TrinaryLogic.h"


TrinaryLogic::TrinaryLogic()
{
    // Default logic
    // Not
    Not[0][0] = T;
    Not[0][1] = F; 
    Not[0][2] = U;
    //Or
    Or[1][0] = Or[0][1] = Or[1][1] = Or[1][2] = Or[2][1] = T;
    Or[0][0] = F;
    Or[2][2] = Or[2][0] = Or[0][2] = U;
    //And
    And[1][1] = T;
    And[2][0] = And[0][2] = And[1][0] = And[0][1] = And[0][0] = F;
    And[2][2] = And[1][2] = And[2][1] = U;
    //Impl
    Impl[0][0] = Impl[0][1] = Impl[1][1] = Impl[0][2] = Impl[2][1] = T;
    Impl[1][0] = F;
    Impl[2][0] = Impl[2][2] = Impl[1][2] = U;
    
}

TrinaryLogic& TrinaryLogic::getInstance()
{
    static TrinaryLogic singleton;
    return singleton;
}

void TrinaryLogic::loadLogicFromFiles( string notFile, string andFile, string orFile, string implFile )
{
    loadLogicFromFile( notFile, Not, true );
    loadLogicFromFile( andFile, And );
    loadLogicFromFile( orFile, Or );
    loadLogicFromFile( implFile, Impl );
}

// Throws exception in case of bad arguments
void TrinaryLogic::loadLogicFromFile( string name, Trilean operand[][3], bool isNot )
{
    const short int offset = 48;
    
    // If the file hasn't be specified we ust standard logic
    if( name == "" ) return;
    
    // Arguments to be read
    char v[3];
    ifstream infile(name.c_str() );
    
    // Something went wrong with file opening
    if( !infile.good() )
        throw runtime_error( name + " could not be opened." );
    
    while( infile >> v[0] >> v[1] )
    {
        // If it is not negation operand we have to read 3 inputs, not just 2
        if( isNot ) { v[2] = v[1]; v[1] = v[0]; v[0] = 0; }
        else infile >> v[2]; 
        
        
        //Checking if arguements are right
        for( int i = 0; i<3; i++ )
        {
            // Change char to int
            if( v[i] == 'X' ) v[i] = 2;
            else if( !(isNot && i==0) ) v[i] -= offset;
            
            // Check if has an acceptable value
            if( !hasRightValue( v[i] ) )
               throw invalid_argument( name + " file contains unknown logic option: '" + to_string(v[i]) + "' only 1, 0 and X are allowed!" );
        }

        // Set new logic
        operand[v[0]][v[1]] = Trilean( (LogicValue)v[2] );

    }
    
    infile.close();
}

bool TrinaryLogic::hasRightValue( int a )
{
    return a == 0 || a == 1 || a == 2;
}

Trilean TrinaryLogic::lNot( Trilean t )
{
    return Not[0][ t.value ];
}

Trilean TrinaryLogic::lAnd( Trilean t1, Trilean t2 )
{
    return And[ t1.value ][ t2.value ];  
}

Trilean TrinaryLogic::lOr( Trilean t1, Trilean t2 )
{
    return Or[ t1.value ][ t2.value ];  
}

Trilean TrinaryLogic::lImpl( Trilean t1, Trilean t2 )
{
    return Impl[ t1.value ][ t2.value ];  
}


/* Trilean */

Trilean::Trilean()
{
    value = U.value;
}

Trilean::Trilean( LogicValue val )
{
    value = val;
}

Trilean::Trilean( const Trilean& t )
{
    value = t.value;
}

Trilean Trilean::operator!() const
{
    return TrinaryLogic::getInstance().lNot( *this );
}

Trilean Trilean::operator&&( const Trilean& t ) const
{
    return TrinaryLogic::getInstance().lAnd( *this, t );
}

Trilean Trilean::operator||( const Trilean& t ) const
{
    return TrinaryLogic::getInstance().lOr( *this, t );
}

Trilean Trilean::operator>>( const Trilean& t ) const
{
    return TrinaryLogic::getInstance().lImpl( *this, t );
}

Trilean Trilean::operator=( const Trilean& t )
{
    value = t.value;
    return *this;
}

bool Trilean::operator==( const Trilean& t ) const
{
    return this->value == t.value;
}

string Trilean::toString() const {
    switch( value ) {
        case LogicValue::False:
            return "0";
        break;
        case LogicValue::True:
            return "1";
        break;
        case LogicValue::Unknown:
            return "x";
        break;
    }
}