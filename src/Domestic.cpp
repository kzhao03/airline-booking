#include "Domestic.h"

//constructors + ro3
Domestic::Domestic(int n, string dCode, string aCode, string dTime, string c): Flight(n, dCode, aCode, dTime) {
  country = c;
}
Domestic::Domestic(const Domestic& d): Flight(d) {
  country = d.country;
}
Domestic& Domestic::operator = (const Domestic& d) {
  if(this != &d) {
    Flight::operator = (d);
    country = d.country;
  }
  return(*this);
}
Domestic::~Domestic() {
  //automatically calls base destructor
}

//derived info
void Domestic::printFlightInfo() {
  cout << "Fly-By-Night Airlines Flight " << to_string(flightNumber) << " " << departureCode << " to " << arrivalCode << endl;
  cout << "Domestic - " << country << endl;
  cout << "Departure Time: " << departureTime << endl << endl;
}
void Domestic::printPassengerInfo() {
  cout << "Fly-By-Night Airlines Flight " << to_string(flightNumber) << " " << departureCode << " to " << arrivalCode << endl;
  cout << "Domestic - " << country << endl;
  cout << "Departure Time: " << departureTime << endl << endl;
  for(int i = 0; i < 10; i++) {
    cout << "Seat " << to_string(i + 1) << endl;
    if(seats[i]->getIsReserved()) {
      cout << seats[i]->getLastName() << ", " << seats[i]->getFirstName() << endl;
      cout << seats[i]->getAddress() << endl;
      cout << seats[i]->getPhoneNumber() << endl << endl;
    } else {
      cout << "Available" << endl << endl;
    }
  }
}

//get
string Domestic::getDepartureCountry() {
  return country;
}
string Domestic::getArrivalCountry() {
  return country;
}