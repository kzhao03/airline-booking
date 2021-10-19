#include "International.h"

//constructors + ro3
International::International(int n, string dCode, string aCode, string dTime, string dCountry, string aCountry): Flight(n, dCode, aCode, dTime) {
  departureCountry = dCountry;
  arrivalCountry = aCountry;
}
International::International(const International& i): Flight(i) {
  departureCountry = i.departureCountry;
  arrivalCountry = i.arrivalCountry;
}
International& International::operator = (const International& i) {
  if(this != &i) {
    Flight::operator = (i);
    departureCountry = i.departureCountry;
    arrivalCountry = i.arrivalCountry;
  }
  return(*this);
}
International::~International() {
  //automatically calls base destructor
}

//derived info
void International::printFlightInfo() {
  cout << "Fly-By-Night Airlines Flight " << to_string(flightNumber) << " " << departureCode << " to " << arrivalCode << endl;
  cout << "International - " << departureCountry << " to " << arrivalCountry << endl;
  cout << "Departure Time: " << departureTime << endl << endl;
}
void International::printPassengerInfo() {
  cout << "Fly-By-Night Airlines Flight " << to_string(flightNumber) << " " << departureCode << " to " << arrivalCode << endl;
  cout << "International - " << departureCountry << " to " << arrivalCountry << endl;
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

//derived get
string International::getDepartureCountry() {
  return departureCountry;
}
string International::getArrivalCountry() {
  return arrivalCountry;
}
