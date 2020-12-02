/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/


#include <iostream>
#include <string>
#include "Address.h"

using namespace std;

Address::Address(){}

Address::Address(string house, string street, string city):house_num(house), street_name(street), city_name(city){}
    
string Address::getHouse_num()
{
    return this->house_num;
}

string Address::getStreet_name()
{
    return this->street_name;
}

string Address::getCity_name()
{
    return this->city_name;
}

// Change Address
void Address::setAddress(string house, string street, string city)
{
    this->setHouse_num(house);
    this->setStreet_name(street);
    this->setCity_name(city);
}

void Address::setHouse_num(string house)
{
    this->house_num = house;
}

void Address::setStreet_name(string street)
{
    this->street_name = street;
}

void Address::setCity_name(string city)
{
    this->city_name = city;
}

Address::~Address(){}