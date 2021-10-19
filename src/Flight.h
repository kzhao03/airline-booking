#include "Seat.h"

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight {
  protected:
    int flightNumber;
    string departureCode, arrivalCode, departureTime;
    Seat* seats[10];
    bool availableSeats[10];
    static int numOfFlights;

  public:
    //constructors + ro3
    Flight(int, string, string, string);
    Flight(const Flight& f);
    Flight& operator = (const Flight& f);
    virtual ~Flight();
    //get
    int getFlightNumber();
    string getDepartureCode();
    string getArrivalCode();
    string getDepartureTime();
    static int getNumOfFlights();
    void getAvailability();
    bool getSeatAvailability(int);
    string getPhoneNumber(int);
    //module
    void reserveSeat(int);
    void cancelSeat(int);
    //virtual info
    virtual void printFlightInfo() = 0;
    virtual void printPassengerInfo() = 0;
    //virtual gets
    virtual string getDepartureCountry() = 0;
    virtual string getArrivalCountry() = 0;
};

#endif