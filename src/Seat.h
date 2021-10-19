#include <iostream>
#include <string>
using namespace std;

#ifndef SEAT_H
#define SEAT_H

class Seat {
  private:
    int seatNum;
    bool isReserved;
    string lastName, firstName, address, phoneNumber;
    
  public:
    //constructor
    Seat(int);
    //get
    int getseatNum();
    bool getIsReserved();
    string getLastName();
    string getFirstName();
    string getAddress();
    string getPhoneNumber();
    //set
    void setIsReserved(bool);
    void setLastName(string);
    void setFirstName(string);
    void setAddress(string);
    void setPhoneNumber(string);
};

#endif