/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/



#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class Address
{
private:
    string house_num;
    string street_name;
    string city_name;
public:
    Address();  // Non parameterised constructor
    Address(string, string, string);    // Parameterised constructor
    
    string getHouse_num();
    string getStreet_name();
    string getCity_name();
    
    void setAddress(string, string, string);
    void setHouse_num(string);
    void setStreet_name(string);
    void setCity_name(string);
    
    ~Address();
};



#endif
