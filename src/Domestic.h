#include "Flight.h"

#ifndef DOMESTIC_H
#define DOMESTIC_H

class Domestic: public Flight {
  private:
    string country;

  public:
    //constructors + ro3
    Domestic(int, string, string, string, string);
    Domestic(const Domestic& d);
    Domestic& operator = (const Domestic& d);
    ~Domestic();
    //derived info
    void printFlightInfo();
    void printPassengerInfo();
    //derived get
    string getDepartureCountry();
    string getArrivalCountry();
    
};

#endif