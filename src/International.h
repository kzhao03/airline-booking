#include "Flight.h"

#ifndef INTERNATIONAL_H
#define INTERNATIONAL_H

class International: public Flight {
  private:
    string departureCountry;
    string arrivalCountry;

  public:
    //constructors
    International(int, string, string, string, string, string);
    International(const International& i);
    International& operator = (const International& i);
    ~International();

    //get
    string getDepartureCountry();
    string getArrivalCountry();

    void printFlightInfo();
    void printPassengerInfo();
};

#endif