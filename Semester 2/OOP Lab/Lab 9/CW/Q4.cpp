#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flight
{
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;
    vector<string> passengerIds;

public:
    Flight(string num, string dep, string arr, int cap)
        : flightNumber(num), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat(const string &passengerId)
    {
        if (bookedSeats >= capacity)
        {
            cout << "Flight " << flightNumber << " is fully booked.\n";
            return false;
        }
        passengerIds.push_back(passengerId);
        bookedSeats++;
        cout << "Seat booked for passenger " << passengerId << " on flight " << flightNumber << endl;
        return true;
    }

    bool cancelSeat(const string &passengerId)
    {
        for (auto it = passengerIds.begin(); it != passengerIds.end(); ++it)
        {
            if (*it == passengerId)
            {
                passengerIds.erase(it);
                bookedSeats--;
                cout << "Booking canceled for passenger " << passengerId << " on flight " << flightNumber << endl;
                return true;
            }
        }
        cout << "Passenger " << passengerId << " not found on flight " << flightNumber << endl;
        return false;
    }

    bool upgradeSeat(const string &passengerId)
    {
        for (auto &id : passengerIds)
        {
            if (id == passengerId)
            {
                cout << "Seat upgraded for passenger " << passengerId << " on flight " << flightNumber << endl;
                return true;
            }
        }
        cout << "Cannot upgrade - passenger " << passengerId << " not booked on flight " << flightNumber << endl;
        return false;
    }

    void displayDetails() const
    {
        cout << "Flight " << flightNumber << ": " << departure << " -> " << arrival
             << " (" << bookedSeats << "/" << capacity << " seats booked)\n";
    }

    string getFlightNumber() const { return flightNumber; }
};

class Passenger
{
private:
    string id;
    string name;

public:
    Passenger(string pid, string pname) : id(pid), name(pname) {}

    bool requestBooking(Flight &flight)
    {
        cout << name << " requesting booking on flight " << flight.getFlightNumber() << endl;
        return flight.bookSeat(id);
    }

    bool requestCancellation(Flight &flight)
    {
        cout << name << " requesting cancellation on flight " << flight.getFlightNumber() << endl;
        return flight.cancelSeat(id);
    }

    bool requestUpgrade(Flight &flight)
    {
        cout << name << " requesting upgrade on flight " << flight.getFlightNumber() << endl;
        return flight.upgradeSeat(id);
    }

    string getId() const { return id; }
    string getName() const { return name; }
};

int main()
{
    // Create flights
    Flight nycToLon("BA123", "New York", "London", 200);
    Flight parToTok("AF456", "Paris", "Tokyo", 150);

    // Create passengers
    Passenger john("P100", "John Smith");
    Passenger emma("P200", "Emma Johnson");

    // Demonstrate bookings
    john.requestBooking(nycToLon);
    emma.requestBooking(nycToLon);
    john.requestBooking(parToTok);

    // Try to upgrade
    john.requestUpgrade(nycToLon);
    emma.requestUpgrade(parToTok); // Should fail - not booked

    // Display flight status
    nycToLon.displayDetails();
    parToTok.displayDetails();

    // Demonstrate cancellations
    john.requestCancellation(nycToLon);
    emma.requestCancellation(parToTok); // Should fail - not booked
    return 0;
}