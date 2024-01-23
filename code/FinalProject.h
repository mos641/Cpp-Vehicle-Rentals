// FinalProject.h : Include file for standard system include files,
// or project specific include files.

// Mostapha A
// CST8219 C++ Programming

#pragma once

#include "FinalProject.h"

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <ranges>

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/combox.hpp>

#include <nana/gui/widgets/checkbox.hpp>
using namespace std;
using namespace nana;

// a customer class for managing out customers
class Customer {
public:
    string name;
    string address;
    int age;
    int rentals;
    bool preferred;
    double amountOwing;
    double multiplier;

    // constructor
public: Customer(string n, string ad, int a, bool pref)
{
    // set the name, age and preffered status
    name = n;
    address = ad;
    age = a;
    preferred = pref;
    // set other variables to default values
    amountOwing = 0;
    rentals = 0;

    // set the multiplier based on age/prefferred status
    if (age <= 25) {
        multiplier = 1.2;
    }
    else if (preferred == true) {
        multiplier = 0.8;
    }
    else {
        multiplier = 1;
    }
}
      string toString() {
          return(" " + name + " Address: " + address);
      }
      string toStringDetailed() {
          return(" " + name + " Address: " + address + ", Age: " + to_string(age) + " years old, owes " + to_string(amountOwing) + " dollars");
      }
};

// a location calss for managing our locations
class Location {
public:
    // variables needed
    string name;
    string address;
    int cars;

    Location(string n, string a) {
        name = n;
        address = a;
        cars = 0;
    }

    string toString() {
        return(" " + name + " " + address);
    }

    string toStringDetailed() {
        return(" " + name + " located at " + address + ", there are " + to_string(cars) + " vehicles here");
    }
};

// a vehicle class for managing our vehicles
class Vehicle {
public:
    // variables needed
    string name;
    string location;
    string customer;
    int start;
    int end;
    bool cleaning;

public:
    // constructor
    Vehicle(string n, string loc) {
        // set the name and location
        name = n;
        location = loc;
        // set other variables to default values
        customer = "N/A";
        start = -1;
        end = -1;
        cleaning = false;
    }
    string toString() {
        string info = name;

        if (location != "N/A") {
            // if there is a location return the info
            if (cleaning == true) {
                info += " being cleaned at" + location;
            }
            else {
                info += " available at" + location;
            }
        }else if (customer != "N/A") {
            // if a customer is renting return the info
            info += " rented by " + customer + " from day " + to_string(start) + " to day " + to_string(end);
        }
        else {
            // if no location/customer not for rent
            info += " not available for rent";
        }

        return (" " + info);
    }
};
