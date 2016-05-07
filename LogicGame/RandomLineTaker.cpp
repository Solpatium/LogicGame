#include "RandomLineTaker.h"

RandomLineTaker::RandomLineTaker( string name ) {
    
    index = 0;
    
    ifstream infile( name.c_str() );
    
    // Something went wrong with file opening
    if( !infile.good() )
        throw runtime_error( name + " could not be opened." );
    
    string temp;
    while( getline( infile, temp )  )
        lines.push_back( temp );
    
    // Randomly shuffle our array
    random_shuffle( lines.begin(), lines.end() );

}

string RandomLineTaker::getLine() {
    if( index+1 >= lines.size() )
        index = 0;
    
    return lines[index++];
}