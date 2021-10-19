#include "Flight.h"

//constructor, ro3
Flight::Flight(int n, string dCode, string aCode, string dTime) {
  flightNumber = n;
  departureCode = dCode;
  arrivalCode = aCode;
  departureTime = dTime;
  for(int i = 0; i < 10; i++) {
    seats[i] = new Seat(i + 1);
    availableSeats[i] = true;
  }
  Flight::numOfFlights++;
}
Flight::Flight(const Flight& f) {
  flightNumber = f.flightNumber;
  departureCode = f.departureCode;
  arrivalCode = f.arrivalCode;
  departureTime = f.departureTime;
  for(int i = 0; i < 10; i++) {
    seats[i] = f.seats[i];
    availableSeats[i] = true;
  }
  Flight::numOfFlights++;
}
Flight& Flight::operator = (const Flight& f) {
  if(this != &f) {
    flightNumber = f.flightNumber;
    departureCode = f.departureCode;
    arrivalCode = f.arrivalCode;
    departureTime = f.departureTime;
    for(int i = 0; i < 10; i++) {
      delete seats[i];
      seats[i] = f.seats[i];
      availableSeats[i] = true;
    }
  }
  return(*this);
}
Flight::~Flight() {
  for(int i = 0; i < 10; i++) {
    delete seats[i];
  }
  Flight::numOfFlights--;
}

//get
int Flight::getFlightNumber() {
  return flightNumber;
}
string Flight::getDepartureCode() {
  return departureCode;
}
string Flight::getArrivalCode() {
  return arrivalCode;
}
string Flight::getDepartureTime() {
  return departureTime;
}
int Flight::getNumOfFlights() {
  return numOfFlights;
}

//goes thru all seats, prints the available ones
void Flight::getAvailability() {
  cout << "The following seats are available:" << endl;
  for(int i = 0; i < 10; i++) {
    if(availableSeats[i]) {
      cout << (i + 1) << " ";
    }
  }
  cout << endl;
}

//these gets are helpers for main methods
bool Flight::getSeatAvailability(int i) {
  return availableSeats[i];
}
string Flight::getPhoneNumber(int i) {
  return seats[i]->getPhoneNumber();
}

//modules for main program
void Flight::reserveSeat(int seatNum) {
  string l, f, a, p;
  //if valid seat choice, fills out the parameters, availabilty to false
  if(seatNum >= 1 && seatNum <= 10 && availableSeats[seatNum - 1]) {
    availableSeats[seatNum - 1] = false;
    seats[seatNum - 1]->setIsReserved(true);
    cout << "Enter last name : ";
    cin.ignore();
    getline(cin, l);
    seats[seatNum - 1]->setLastName(l);
    cout << "Enter first name : ";
    getline(cin, f);
    seats[seatNum - 1]->setFirstName(f);
    cout << "Enter address : ";
    getline(cin, a);
    seats[seatNum - 1]->setAddress(a);
    cout << "Enter phone number : ";
    getline(cin, p);
    seats[seatNum - 1]->setPhoneNumber(p);
    cout << endl << "Successfully reserved" << endl << endl;
  } else {
    cout << "Invalid seat number" << endl << endl;
  }
}
void Flight::cancelSeat(int seatNum) {
  string temp;
  //if valid, sets parameters to blank again, availabilty to true
  if(seatNum >= 1 && seatNum <= 10 && !availableSeats[seatNum - 1]) {
    cout << "Are you sure you want to cancel? (Type Y to confirm): ";
    cin.ignore();
    getline(cin, temp);
    if(temp == "Y") {
      availableSeats[seatNum - 1] = true;
      seats[seatNum - 1]->setIsReserved(false);
      seats[seatNum - 1]->setLastName("");
      seats[seatNum - 1]->setFirstName("");
      seats[seatNum - 1]->setAddress("");
      seats[seatNum - 1]->setPhoneNumber("");
      cout << endl << "Successfully cancelled" << endl << endl;
    } else {
      cout << endl;
      return;
    }    
  } else {
    cout << "Invalid seat number" << endl << endl;
  }
}

