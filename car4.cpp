#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int PARKING_CAPACITY = 100;
const int PARKING_RATE = 5; // $5 per hour
int arrivalTime;

int main()
{
    queue<string> parkingLot;
    int totalCarsParked = 0;
    int totalParkingCharges = 0;
    string command;

    cout << "\t\t\t\t\t\t\t\t\tWelcome" << endl;

    while (true)
    {
        cout << endl;
        cout << "\t\t\t\tPlease enter  (arrive/depart/total/cost/exit): ";
        cin >> command;

        if (command == "arrive")
        {
            if (totalCarsParked >= PARKING_CAPACITY)
            {
                cout << "\t\t\t\tSorry, the parking lot is full." << endl;
            }
            else
            {
                string carNumber;

                cout << "\t\t\t\tEnter the car plate number: ";
                cin >> carNumber;
                cout << "\t\t\t\tEnter the arrival time (in hours): ";
                cin >> arrivalTime;
                parkingLot.push(carNumber);
                totalCarsParked++;
                cout << "\t\t\t\tCar " << carNumber << " parked at " << arrivalTime << " o'clock." << endl;
            }
        }
        else if (command == "depart")
        {
            string carNumber;
            int departureTime;
            cout << "\t\t\t\tEnter the car number: ";
            cin >> carNumber;
            cout << "\t\t\t\tEnter the departure time (in hours): ";
            cin >> departureTime;
            bool found = false;
            int parkingTime = 0;
            int parkingCost = 0;
            queue<string> temp;
            while (!parkingLot.empty())
            {
                string car = parkingLot.front();
                parkingLot.pop();
                if (car == carNumber)
                {
                    found = true;
                    parkingTime = departureTime - arrivalTime;
                    int p;
                    p=parkingTime%12;
                    parkingCost = p * PARKING_RATE;
                    totalCarsParked--;
                    totalParkingCharges += parkingCost;
                    cout << "\t\t\t\tCar" << carNumber << " departed at " << departureTime << " o'clock." << endl;
                    cout << "\t\t\t\tParking time: " << parkingTime << " hours." << endl;
                    cout << "\t\t\t\tParking charges: $" << parkingCost << "." << endl;
                    break;
                }
                else
                {
                    temp.push(car);
                }
            }
            while (!temp.empty())
            {
                string car = temp.front();
                temp.pop();
                parkingLot.push(car);
            }
            if (!found)
            {
                cout << "\t\t\t\tSorry, the car " << carNumber << " is not parked here." << endl;
            }
        }
        else if (command == "total")
        {
            cout << "\t\t\t\tTotal cars parked: " << totalCarsParked << "." << endl;
        }
        else if (command == "cost")
        {
            cout << "\t\t\t\tTotal parking charges: $" << totalParkingCharges << "." << endl;
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "\t\t\Invalid command. Please try again." <<endl <<endl;
        }
    }

    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\tThankyou" << endl;

    return 0;
}
