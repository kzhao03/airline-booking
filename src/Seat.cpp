#include "Seat.h"

//constructor
Seat::Seat(int n) {
  seatNum = n;
  isReserved = false;
  lastName = "";
  firstName = "";
  address = "";
  phoneNumber = "";
}

//get
int Seat::getseatNum() {
  return seatNum;
}
bool Seat::getIsReserved() {
  return isReserved;
}
string Seat::getLastName() {
  return lastName;
}
string Seat::getFirstName() {
  return firstName;
}
string Seat::getAddress() {
  return address;
}
string Seat::getPhoneNumber() {
  return phoneNumber;
}

//set
void Seat::setIsReserved(bool r) {
  isReserved = r;
}
void Seat::setLastName(string n) {
  lastName = n;
}
void Seat::setFirstName(string n) {
  firstName = n;
}
void Seat::setAddress(string a) {
  address = a;
}
void Seat::setPhoneNumber(string p) {
  phoneNumber = p;
}