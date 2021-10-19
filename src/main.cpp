#include "Domestic.h"
#include "International.h"

//helper methods
void removeEmpty(Flight** d);
void sortDatabase(Flight** d);
int searchDatabase(Flight** d, int num);

//module methods
void displayFlightInfo(Flight** d); // 1
void displayPassengerInfo(Flight** d, int i); // 2
void cancelFlight(Flight ** d, int n); // 5
void departFlight(Flight** d, int i); // 6
bool confirmExit(); // 7

//set initial number of flights to 0
int Flight::numOfFlights = 0;

//main
int main() {
  bool done;
  int choice, temp, index;

  //initial database; all elements set to null
  Flight* database[50] = {nullptr};
  //create some flights
  database[0] = new Domestic(556, "YOW", "YYZ", "June 19 2021, 10:00", "Canada");
  database[1] = new Domestic(323, "YYZ", "YVR", "June 19 2021, 13:30", "Canada");
  database[2] = new Domestic(634, "YVR", "YOW", "June 19 2021, 14:00", "Canada");
  database[3] = new Domestic(789, "JFK", "LAX", "June 19 2021, 11:00", "United States");
  database[4] = new International(417, "LAX", "YYZ", "June 19 2021, 12:30", "United States", "Canada");
  database[5] = new International(817, "YOW", "JFK", "June 19 2021, 15:00", "Canada", "United States");

  //call the sort
  sortDatabase(database);

  //start of menu
  done = false;
  cout << "Fly-By-Night Airlines Menu" << endl << endl;
  //do while loop for menu
  do {
    cout << "Please Select a Module (1-7):" << endl;
    cout << "1. Flight Information\n2. Passenger Information\n3. Reserve a Seat\n4. Cancel a Reservation\n5. Cancel a Flight\n6. Flighttime Passenger Manifest\n7. Exit Menu" << endl << "Enter Number: ";
    cin >> choice;
    //first module displays info of all flights in database
    if(choice == 1) {
      cout << endl;
      displayFlightInfo(database);
    }
    //second module displays info of a specific flight
    else if(choice == 2) {
      cout << "Enter flight number you would like to look up: ";
      cin >> temp;
      //searches for valid flight
      index = searchDatabase(database, temp);
      if(index < 50) {
        cout << endl;
        displayPassengerInfo(database, index);
      } else {
        cout << "Invalid flight number" << endl << endl;
      }
    }
    //third module reserves a seat
    else if(choice == 3) {
      cout << "Enter flight number customer would like a seat for: ";
      cin >> temp;
      //search
      index = searchDatabase(database, temp);
      if(index < 50) {
        cout << endl;
        //displays availability
        database[index]->getAvailability();
        cout << "Which seat would customer like: ";
        cin >> temp;
        database[index]->reserveSeat(temp);
      } else {
        cout << "Invalid flight number" << endl << endl;
      }
    }
    //fourth module cancels a seat
    else if(choice == 4) {
      cout << "Enter flight number customer would like to cancel for: ";
      cin >> temp;
      //search
      index = searchDatabase(database, temp);
      if(index < 50) {
        cout << "Which seat would customer like to cancel: ";
        cin >> temp;
        database[index]->cancelSeat(temp);
      } else {
        cout << "Invalid flight number" << endl << endl;
      }
    } else if(choice == 5) {
      cout << "Enter flight number of cancelled flight: ";
      cin >> temp;
      //search
      index = searchDatabase(database, temp);
      if(index < 50) {
        cout << endl;
        cancelFlight(database, index);
        //bc removed, a sort is performed
        sortDatabase(database);
      } else {
        cout << "Invalid flight number" << endl << endl;
      }
    } else if(choice == 6) {
      cout << "Enter flight number of departing flight: ";
      cin >> temp;
      //search
      index = searchDatabase(database, temp);
      if(index < 50) {
        cout << endl;
        departFlight(database, index);
        //bc removed, sort is performed
        sortDatabase(database);
      } else {
        cout << "Invalid flight number" << endl << endl;
      }
    } else if(choice == 7) {
      //confirm choice of exiting
      done = confirmExit();
    } else {
      cout << "Invalid selection" << endl << endl;
    }
  } while(!done);

  //deletes allocated memory
  for(int i = 0; i < Flight::getNumOfFlights(); i++) {
    delete database[i];
  }
}

//recursive helper function that removes empty elements in database
void removeEmpty(Flight** d) {
  bool allFill = true;
  int index;
  for(int i = 0; i < Flight::getNumOfFlights(); i++) {
    if(d[i] == nullptr) {
      allFill = false;
      index = i;
      break;
    }
  }
  if(allFill) {
    return;
  } else {
    for(int i = index; i < 49; i++) {
      d[i] = d[i + 1];
    }
    d[49] = nullptr;
    removeEmpty(d);
  }
}
//insertion sort helper function that sorts the flights by numbers
void sortDatabase(Flight** d) {
  int i, j;
  Flight* temp;
  //removes empty elements such that the database only contains flight within elements 0 and numOfFlights - 1
  removeEmpty(d);
  //insertion sort
  i = 1;
  while(i < Flight::getNumOfFlights()) {
    j = i;
    while(j > 0 && d[j - 1]->getFlightNumber() > d[j]->getFlightNumber()) {
      temp = d[j];
      d[j] = d[j - 1];
      d[j - 1] = temp;
      j--;
    }
    i++;
  }
}
//binary search for flight number
int searchDatabase(Flight** d, int num) {
  int l = 0;
  int r = Flight::getNumOfFlights() - 1;
  int m;
  while(l <= r) {
    m = (l + r) / 2;
    if(d[m]->getFlightNumber() < num) {
      l = m + 1;
    } else if(d[m]->getFlightNumber() > num) {
      r = m - 1;
    } else {
      return m;
    }
  }
  return 50;
}

//prints the info of all flights
void displayFlightInfo(Flight** d) {
  for(int i = 0; i < Flight::getNumOfFlights(); i++) {
    d[i]->printFlightInfo();
  }
}
//prints info of passengers on one flight
void displayPassengerInfo(Flight **d, int i) {
  d[i]->printPassengerInfo();
}
//confirms a cancellation, then prints availability
void cancelFlight(Flight** d, int n) {
  string temp;
  cout << "Are you sure you want to cancel? (Type Y to confirm): ";
  cin >> temp;
  if(temp == "Y") {
    cout << "Here is a list of the contact information of passengers who reserved seats:" << endl;
    for(int i = 0; i < 10; i++) {
      if(!d[n]->getSeatAvailability(i)) {
        cout << d[n]->getPhoneNumber(i) << endl;
      }
    }
    //deletes flight and replaces with nullptr
    cout << endl;
    delete d[n];
    d[n] = nullptr;
  } else {
    cout << endl;
    return;
  }
}
//confirms a departure, prints manifest
void departFlight(Flight ** d, int i) {
  string temp;
  cout << "Confirm Departure (Type Y to confirm): ";
  cin >> temp;
  if(temp == "Y") {
    cout << endl << "Here is a manifest of the flight: " << endl;
    displayPassengerInfo(d, i);
    //deletes flight and replaces with nullptr
    delete d[i];
    d[i] = nullptr;
  } else {
    cout << endl;
    return;
  }
}
//confirms exit
bool confirmExit() {
  string temp;
  cout << "Are you sure you want to exit? (Type Y to confirm): ";
  cin >> temp;
  if(temp == "Y") {
    return true;
  } else {
    cout << endl;
    return false;
  }
}