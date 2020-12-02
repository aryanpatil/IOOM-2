/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "Address.h"

using namespace std;

class Array
{
    friend ostream &operator<<( ostream &, const Array & );
    friend istream &operator>>( istream &, Array & ); 
    
    private:

    Address *addresses;    // pointer to address objects
    int size;           // pointer-based array size

    public:
    
    Array( int = 3 ); // default constructor
    Array( const Array & ); // copy constructor
    
    ~Array(); // destructor 
    
    int getSize() const; // return size
    
    const Array &operator=( const Array & ); // assignment operator
    
    bool operator==( const Array & ) const; // equality operator 
    
    // inequality operator; returns opposite of == operator 
    bool operator!=( const Array &right ) const; 
    
    // subscript operator for non-const objects returns modifiable lvalue
    Address &operator[]( int ); 
    
    // subscript operator for const objects returns rvalue
    Address operator[]( int ) const; 
    
    
}; 

#endif