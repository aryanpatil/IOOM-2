/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include "Array.h" // Array class definition
#include "Address.h" // Address class definition

using namespace std;

// default constructor for class Array (default size 10)
Array::Array( int arraySize )
{
    size = ( arraySize > 0 ? arraySize : 3 ); // validate arraySize
    addresses = new Address[ size ]; // create space for pointer-based array
    for ( int i = 0; i < size; i++ )
    {
        addresses[i] = Address("house", "street", "city");  // Initializing the addresses
    }
    //ptr[ i ] = 0; // set pointer-based array element
} // end Array default constructor


// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
Array::Array( const Array &arrayToCopy ): size( arrayToCopy.size )
{
    addresses = new Address[ size ]; // create space for pointer-based array
    for ( int i = 0; i < size; i++ )
    {
        addresses[ i ].setHouse_num(arrayToCopy.addresses[ i ].getHouse_num()); // copy into object
        addresses[ i ].setStreet_name(arrayToCopy.addresses[ i ].getStreet_name());
        addresses[ i ].setCity_name(arrayToCopy.addresses[ i ].getCity_name());
    }
} // end Array copy constructor


// destructor for class Array
Array::~Array()
{
    delete [] addresses; // release pointer-based array space
} // end destructor


// return number of elements of Array
int Array::getSize() const
{
    return size; // number of elements in Array
} // end function getSize


// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=( const Array &right )
{
    if ( &right != this ) // avoid self-assignment
    {
        // for Arrays of different sizes, deallocate original
        // left-side array, then allocate new left-side array
        if ( size != right.size )
        {
            delete [] addresses; // release space
            size = right.size; // resize this object
            addresses = new Address[ size ]; // create space for array copy
        } // end inner if
        for ( int i = 0; i < size; i++ )
        {
            addresses[ i ].setHouse_num(right.addresses[ i ].getHouse_num()); // copy into object
            addresses[ i ].setStreet_name(right.addresses[ i ].getStreet_name());
            addresses[ i ].setCity_name(right.addresses[ i ].getCity_name());
        }
    } // end outer if
    return *this; // enables x = y = z, for example
} // end function operator=


// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==( const Array &right ) const
{
    if ( size != right.size )
        return false; // arrays of different number of elements
    for ( int i = 0; i < size; i++ )
        if ( addresses[i].getHouse_num().compare(right.addresses[i].getHouse_num())!=0 ||
             addresses[i].getCity_name().compare(right.addresses[i].getCity_name())!=0 ||
             addresses[i].getStreet_name().compare(right.addresses[i].getStreet_name())!=0)
        return false; // Array contents are not equal
    return true; // Arrays are equal
} // end function operator==


// inequality operator; returns opposite of == operator 
bool Array::operator!=( const Array &right ) const 
{ 
    return ! ( *this == right ); // invokes Array::operator==
} // end function operator!= 

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
Address &Array::operator[]( int subscript )
{
// check for subscript out-of-range error
    if ( subscript < 0 || subscript >= size )
    {
        cerr << "Error: Subscript " << subscript << " out of range" << endl;
        exit( 1 ); // terminate program; subscript out of range
    } // end if
    return addresses[ subscript ]; // reference return
} // end function operator[]


// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
Address Array::operator[]( int subscript ) const
{
    // check for subscript out-of-range error
    if ( subscript < 0 || subscript >= size )
    {
        cerr << "Error: Subscript " << subscript << " out of range" << endl;
        exit( 1 ); // terminate program; subscript out of range
    } // end if
    return addresses[ subscript ]; // returns copy of this element
} // end function operator[]


// overloaded input operator for class Array;
// inputs values for entire Array
istream &operator>>( istream &input, Array &a )
{
    string city, street, house;
    for ( int i = 0; i < a.size; i++ )
    {
        input >> house >> street >> city;
        a.addresses[i].setAddress(house, street, city);
    }
    return input; // enables cin >> x >> y;
} // end function


// overloaded output operator for class Array
ostream &operator<<( ostream &output, const Array &a )
{
    int i;
    // output private ptr-based array
    for ( i = 0; i < a.size; i++ )
    {
        output << setw( 12 ) << a.addresses[i].getHouse_num() << a.addresses[i].getStreet_name() << a.addresses[i].getCity_name();
        if ( ( i + 1 ) % 4 == 0 ) // 4 numbers per row of output
            output << endl;
    } // end for
    if ( i % 4 != 0 ) // end last line of output
        output << endl;
    
    return output; // enables cout << x << y;
} // end function operator<<