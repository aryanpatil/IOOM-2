/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/

#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    Array addressArray1( 2 ); // 2-element Array 
    Array addressArray2; // 3-element Array by default
    
    // print addressArray1 size and contents
    cout << "\nSize of Array addressArray1 is "<< addressArray1.getSize()<< "\nArray after initialization:" << addressArray1;
    
    // print addressArray2 size and contents
    cout << "\nSize of Array addressArray2 is "<< addressArray2.getSize()<< "\nArray after initialization:" << addressArray2;
    
    // input and print addressArray1 and addressArray2
    cout << "Enter 5 addresses (house<ENTER>street<ENTER>city<ENTER>):" << endl;
    
    cin >> addressArray1 >> addressArray2;
    
    cout << "After input, the Arrays contain:"<< "\naddressArray1:\n" << addressArray1<< "\naddressArray2:\n" << addressArray2;
    
    // use overloaded inequality (!=) operator
    cout << "Evaluating: addressArray1 != addressArray2" << endl;
    if ( addressArray1 != addressArray2 )
        cout << "addressArray1 and addressArray2 are not equal\n" << endl;
    
    // create Array addressArray3 using addressArray1 as an 
    // initializer; print size and contents 
    Array addressArray3( addressArray1 ); // invokes copy constructor
    cout << "Size of Array addressArray3 is "<< addressArray3.getSize()<< "\nArray after initialization:" << addressArray3;
    
    // use overloaded assignment (=) operator
    cout << "\nAssigning addressArray2 to addressArray1:\n" << endl;
    addressArray1 = addressArray2; // note target Array is smaller
    cout << "addressArray1:" << addressArray1<< "addressArray2:" << addressArray2;
    
    // use overloaded equality (==) operator
    cout << "Evaluating: addressArray1 == addressArray2\n" << endl;
    if ( addressArray1 == addressArray2 )
        cout << "\naddressArray1 and addressArray2 are equal\n" << endl;
    
    // use overloaded subscript operator to create rvalue
    cout << "addressArray1[1] is " << addressArray1[1].getHouse_num() << addressArray1[1].getStreet_name() << addressArray1[1].getCity_name();
    
    // use overloaded subscript operator to create lvalue
    cout << "\nAssigning (aaa, bbb, ccc )to addressArray1[1]" << endl;
    addressArray1[ 1 ] = Address("aaa", "bbb", "ccc");
    cout << "addressArray1:" << addressArray1;
    
    // attempt to use out-of-range subscript
    cout << "Attempt to assign (aaa, bbb, ccc) to addressArray1[15]" << endl;
    addressArray1[ 15 ] = Address("aaa", "bbb", "ccc");; // ERROR: out of range
    
    return 0;
} // end main