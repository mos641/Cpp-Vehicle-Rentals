// Mostapha A
// CST8219 C++ Programming

#include "FinalProject.h"

int main()
{
    // integer to keep track of the date
    int currentDay = 0;
    // renting cost
    double cost = 30;

    // array for vehicles, customers and locations
    vector<Vehicle> vehicles;
    vector<Customer> customers;
    vector<Location> locations;

    // create the information to be shown at start of program
    string information = "";
    for (Vehicle vehicle : vehicles) {
        information += vehicle.toString() + "\n";
    }

    if (information == "") {
        information = " There are no vehicles";
    }

    // create a form/window
    form window(rectangle(50,50, 1200, 600));
    window.caption("Mostapha's Rentals");
    window.bgcolor(color_rgb(0xE5E5E5));

    // create a label
    label header{window};
    header.format(true);
    header.bgcolor(color_rgb(0xF3F3F3));
    header.fgcolor(color_rgb(0x000000));
    header.caption("Mostapha's Rentals\nDay: "+to_string(currentDay));
    //paint::font defFont = paint::font("", 14, true);
    //defFont.weight();
    //detail::font_style::font_style(weight = 500);
    header.typeface(paint::font("", 14, true));

    // create a textbox
    label text{ window };
    text.format(true);
    text.bgcolor(color_rgb(0xFFFFFF));
    text.typeface(paint::font("", 14, true));
    text.caption(information);

    // create top (menu) buttons
    button veh{ window, "Vehicles" };
    button cust{ window, "Customers" };
    button loc{ window, "Locations" };
    button day{ window, "Next Day" };
    veh.bgcolor(color_rgb(0xFFFFFF));
    cust.bgcolor(color_rgb(0xD6E6EA));
    loc.bgcolor(color_rgb(0xD6E6EA));
    day.bgcolor(color_rgb(0xD6E6EA));

    // create section specific buttons
#pragma region
    // vehicle section
    button allVeh{ window, "View All Vehicles" };
    button rentedVeh{ window, "View Rented Vehicles" };
    button lateVeh{ window, "View Late Vehicles" };
    button addVeh{ window, "Add a Vehicle" };
    button removeVeh{ window, "Remove a Vehicle" };
    button rentVeh{ window, "Rent a Vehicle" };
    button returnVeh{ window, "Return a Vehicle" };
    allVeh.bgcolor(color_rgb(0xFFFFFF));
    rentedVeh.bgcolor(color_rgb(0xFFFFFF));
    lateVeh.bgcolor(color_rgb(0xFFFFFF));
    addVeh.bgcolor(color_rgb(0xFFFFFF));
    removeVeh.bgcolor(color_rgb(0xFFFFFF));
    rentVeh.bgcolor(color_rgb(0xFFFFFF));
    returnVeh.bgcolor(color_rgb(0xFFFFFF));

    // customer section
    button allCust{ window, "View All Customers" };
    button rentCust{ window, "View Customers with Rentals" };
    button addCust{ window, "Add a Customer" };
    button removeCust{ window, "Remove a Customer" };
    allCust.bgcolor(color_rgb(0xFFFFFF));
    rentCust.bgcolor(color_rgb(0xFFFFFF));
    addCust.bgcolor(color_rgb(0xFFFFFF));
    removeCust.bgcolor(color_rgb(0xFFFFFF));

    // location section
    button allLoc{ window, "View All Locations" };
    button addLoc{ window, "Add a Location" };
    button removeLoc{ window, "Remove a Location" };
    allLoc.bgcolor(color_rgb(0xFFFFFF));
    addLoc.bgcolor(color_rgb(0xFFFFFF));
    removeLoc.bgcolor(color_rgb(0xFFFFFF));
#pragma endregion buttons creation

    // define the window layout
#pragma region
    window.div("vert  < <HEAD weight = 15%> <VEH> <CUST> <LOC> <DAY>  weight = 12%>  < < vert <ALLVEH><RENTEDVEH><LATEVEH><><RENTVEH><RETURNVEH><><ADDVEH><REMOVEVEH><> weight = 15%> <INFO> >");

    // specify layout components
    window["HEAD"] << header;
    window["VEH"] << veh;
    window["CUST"] << cust;
    window["LOC"] << loc;
    window["DAY"] << day;
    window["INFO"] << text;

    window["RENTVEH"] << rentVeh;
    window["RETURNVEH"] << returnVeh;
    window["ALLVEH"] << allVeh;
    window["RENTEDVEH"] << rentedVeh;
    window["LATEVEH"] << lateVeh;
    window["ADDVEH"] << addVeh;
    window["REMOVEVEH"] << removeVeh;

    window["ALLCUST"] << allCust;
    window["RENTCUST"] << rentCust;
    window["ADDCUST"] << addCust;
    window["REMOVECUST"] << removeCust;

    window["ALLLOC"] << allLoc;
    window["ADDLOC"] << addLoc;
    window["REMOVELOC"] << removeLoc;

    window.collocate();
#pragma endregion Layout creation and assignments

    // define button functionalities
    // viewing the vehicles
    veh.events().click([&] {
        // update the window's layout
        window.div("vert  < <HEAD weight = 15%> <VEH> <CUST> <LOC> <DAY>  weight = 12%>  < < vert <ALLVEH><RENTEDVEH><LATEVEH><><RENTVEH><RETURNVEH><><ADDVEH><REMOVEVEH><> weight = 15%> <INFO> >");
        window.collocate();

        // set button colours
        veh.bgcolor(color_rgb(0xFFFFFF));
        cust.bgcolor(color_rgb(0xD6E6EA));
        loc.bgcolor(color_rgb(0xD6E6EA));

        // update the information box
        information = "";
        
        for (Vehicle vehicle : vehicles) {
            information += vehicle.toString() + "\n";
        }

        if (information == "") {
            information = " There are no vehicles";
        }

        text.caption(information);
        });

    // viewing the customers
    cust.events().click([&] {
        // update the window's layout
        window.div("vert  < <HEAD weight = 15%> <VEH> <CUST> <LOC> <DAY>  weight = 12%>  < < vert <ALLCUST><RENTCUST><><ADDCUST><REMOVECUST><><><><><> weight = 15%> <INFO> >");
        window.collocate();

        // set button colours
        veh.bgcolor(color_rgb(0xD6E6EA));
        cust.bgcolor(color_rgb(0xFFFFFF));
        loc.bgcolor(color_rgb(0xD6E6EA));

        // update the information box
        information = "";

        for (Customer customer : customers) {
            information += customer.toStringDetailed() + "\n";
        }

        if (information == "") {
            information = " There are no Customers";
        }

        text.caption(information);
        });

    // viewing the locations
    loc.events().click([&] {
        // update the window's layout
        window.div("vert  < <HEAD weight = 15%> <VEH> <CUST> <LOC> <DAY>  weight = 12%>  < < vert <ALLLOC><><ADDLOC><REMOVELOC><><><><><><> weight = 15%> <INFO> >");
        window.collocate();

        // set button colours
        veh.bgcolor(color_rgb(0xD6E6EA));
        cust.bgcolor(color_rgb(0xD6E6EA));
        loc.bgcolor(color_rgb(0xFFFFFF));

        // update the information box
        information = "";

        for (Location location : locations) {
            information += location.toStringDetailed() + "\n";
        }

        if (information == "") {
            information = " There are no Locations";
        }

        text.caption(information);
        });

    // increasing the day
    day.events().click([&] {
        // increment day and update header
        currentDay++;
        header.caption("Mostapha's Rentals\nDay: " + to_string(currentDay));

        // update amount owing and cleaning status
        int i = 0;
        for (Vehicle vehicle : vehicles) {
            // update cleaning status
            if (vehicle.cleaning == true) {
                vehicles[i].cleaning = false;
                i++;
            }
            // update amount owing
            if (vehicle.customer != "N/A" && vehicle.start < currentDay) {
                int i = 0;
                // find the customer
                for (Customer customer : customers) {
                    if (customer.toString() == vehicle.customer) {
                        // check if its overdue
                        if (vehicle.end < currentDay) {
                            customers[i].amountOwing += 2 * cost * customers[i].multiplier;
                        }
                        else {
                            customers[i].amountOwing += cost * customers[i].multiplier;
                        }
                        break;
                    }
                    i++;
                }
            }
        }

        text.caption(" Simulated another day passing to day " + to_string(currentDay));
        });

    // define vehicle specific buttons
    // rent a vehicle button
    rentVeh.events().click([&] {
        // create a vector for available vehicles
        vector<int> availableVeh;

        // create a pop up window
        form newRentalWindow(window, rectangle(50, 50, 550, 320));
        // create boxes for input
        combox customerInput{ newRentalWindow };
        combox locationInput{ newRentalWindow };
        combox vehicleInput{ newRentalWindow };
        //inputbox::integer start("Start Day:", 0, 0, 0, 0);
        textbox start{ newRentalWindow };
        textbox end{ newRentalWindow };
        // button to confirm changes
        button Rent{ newRentalWindow, "Rent" };
        Rent.bgcolor(color_rgb(0x7FEA78));
        // labels for input
        label custLabel{ newRentalWindow, "Choose Customer:" };
        label locLabel{ newRentalWindow, "Choose Location:" };
        label vehLabel{ newRentalWindow, "Choose Vehicle:" };
        label startLabel{ newRentalWindow, " Start Date:" };
        label endLabel{ newRentalWindow, " End Date:" };
        label message{ newRentalWindow, "" };

        // create layout and set components
        newRentalWindow.div("vert <CUSTLABEL weight = 10%><CUST><LOCLABEL weight = 10%><LOC><VEHLABEL weight = 10%><VEH>< weight = 5%>< <STARTLABEL weight = 12%> <START> <ENDLABEL weight = 12%> <END> ><MESSAGE weight = 10%><RENT>");
        newRentalWindow["CUSTLABEL"] << custLabel;
        newRentalWindow["CUST"] << customerInput;
        newRentalWindow["LOCLABEL"] << locLabel;
        newRentalWindow["LOC"] << locationInput;
        newRentalWindow["VEHLABEL"] << vehLabel;
        newRentalWindow["VEH"] << vehicleInput;
        newRentalWindow["STARTLABEL"] << startLabel;
        newRentalWindow["START"] << start;
        newRentalWindow["ENDLABEL"] << endLabel;
        newRentalWindow["END"] << end;
        newRentalWindow["MESSAGE"] << message;
        newRentalWindow["RENT"] << Rent;
        newRentalWindow.collocate();

        // populate customers and locations combox
        for (Customer customer : customers) {
            customerInput.push_back(customer.toString());
        }
        for (Location location : locations) {
            locationInput.push_back(location.toString());
        }

        // populate vehicles depending on location
        locationInput.events().selected([&] {
            // clear the combox
            vehicleInput.clear();
            
            // check location
            int option = locationInput.option();

            // add vehicles at that location, keep track of the vehicle selected
            int i = 0;
            for (Vehicle vehicle : vehicles) {
                if (vehicle.location == locations[option].toString() && vehicle.cleaning == false) {
                    vehicleInput.push_back(vehicle.toString());
                    availableVeh.push_back(i);
                }
            }

            API::modal_window(newRentalWindow);
            });

        // button after confirming
        Rent.events().click([&] {
            // store start and end date
            string startDate; 
            start.getline(0, startDate);
            string endDate;
            end.getline(0, endDate);
            bool digit = true;

            // confirm dates are digits
            if (!startDate.empty() && !endDate.empty()) {
                for (char character : startDate) {
                    if (!isdigit(character)) {
                        digit = false;
                    }
                }
                if (digit == true) {
                    for (char character : endDate) {
                        if (!isdigit(character)) {
                            digit = false;
                        }
                    }
                }
            }
            else {
                digit = false;
            }
            

            // check if all selections are made and valid
            if (digit == false) {
                message.caption("Dates must be integers!");
            } else if (vehicleInput.option() == -1) {
                message.caption("Make a selection!");
            }
            else if (stoi(startDate) < currentDay) {
                message.caption("Start date must be current day or in the future!");
            }
            else if (stoi(endDate) <= stoi(startDate)) {
                message.caption("End date must be after start day!");
            }
            else {
                // change vehicle status
                vehicles[availableVeh[vehicleInput.option()]].location = "N/A";
                vehicles[availableVeh[vehicleInput.option()]].customer = customers[customerInput.option()].toString();
                vehicles[availableVeh[vehicleInput.option()]].start = stoi(startDate);
                vehicles[availableVeh[vehicleInput.option()]].end = stoi(endDate);
                customers[customerInput.option()].rentals++;
                locations[locationInput.option()].cars--;

                // print the vehicle
                text.caption(" " + vehicles[availableVeh[vehicleInput.option()]].toString());
                // close window
                newRentalWindow.close();
            }
            });
        API::modal_window(newRentalWindow);
        });

    // return a vehicle button
    returnVeh.events().click([&] {
        // create a vector for available vehicles
        vector<int> availableVeh;

        // create a pop up window
        form newRentalWindow(window, rectangle(50, 50, 550, 290));
        // , rectangle(50, 50, 550, 220)
        
        // create boxes for input
        combox customerInput{ newRentalWindow };
        combox vehicleInput{ newRentalWindow };
        combox locationInput{ newRentalWindow };
        // button to confirm changes
        button Return{ newRentalWindow, "Return" };
        Return.bgcolor(color_rgb(0x7FEA78));
        // labels for input
        label custLabel{ newRentalWindow, "Choose Customer:" };
        label vehLabel{ newRentalWindow, "Choose Vehicle:" };
        label locLabel{ newRentalWindow, "Return Vehicle to Location:" };
        label message{ newRentalWindow, "" };

        // create layout and set components
        newRentalWindow.div("vert <CUSTLABEL weight = 10%><CUST><VEHLABEL weight = 10%><VEH><LOCLABEL weight = 10%><LOC><MESSAGE weight = 10%><RETURN>");
        newRentalWindow["CUSTLABEL"] << custLabel;
        newRentalWindow["CUST"] << customerInput;
        newRentalWindow["VEHLABEL"] << vehLabel;
        newRentalWindow["VEH"] << vehicleInput;
        newRentalWindow["LOCLABEL"] << locLabel;
        newRentalWindow["LOC"] << locationInput;
        newRentalWindow["MESSAGE"] << message;
        newRentalWindow["RETURN"] << Return;
        newRentalWindow.collocate();

        // populate customers and lcoations combox
        for (Customer customer : customers) {
            customerInput.push_back(customer.toString());
        }
        for (Location location : locations) {
            locationInput.push_back(location.toString());
        }

        // populate vehicles depending on customer
        customerInput.events().selected([&] {
            // clear the combox
            vehicleInput.clear();

            // check location
            int option = customerInput.option();

            // add vehicles with that customer, keep track of the vehicle selected
            int i = 0;
            for (Vehicle vehicle : vehicles) {
                if (vehicle.customer == customers[option].toString()) {
                    int days;
                    int fee;
                    if (currentDay > vehicle.start) {
                        days = currentDay - vehicle.start;
                        // calculate cost
                        if (vehicle.end >= currentDay) {
                            fee = days * customers[option].multiplier * cost;
                        }
                        else {
                            int regular;
                            int late;

                            regular = (vehicle.end - vehicle.start) * customers[option].multiplier * cost;
                            late = (currentDay - vehicle.end) * customers[option].multiplier * cost * 2;

                            fee = regular + late;
                        }
                    }
                    else {
                        days = 0;
                        fee = 0;
                    }

                    // print vehicle info
                    vehicleInput.push_back(vehicle.toString() + " rented for " + to_string(days) + " days, owing $" + to_string(fee));
                    availableVeh.push_back(i);
                }
            }

            API::modal_window(newRentalWindow);
            });

        // button after confirming
        Return.events().click([&] {
            // confirm a selection has been made
            if (vehicleInput.option() == -1) {
                message.caption("Make a selection!");
            }
            else {
                // change vehicle status
                vehicles[availableVeh[vehicleInput.option()]].location = locations[locationInput.option()].toString();
                vehicles[availableVeh[vehicleInput.option()]].customer = "N/A";
                vehicles[availableVeh[vehicleInput.option()]].cleaning = true;
                customers[customerInput.option()].rentals--;
                locations[locationInput.option()].cars++;

                // print the vehicle
                text.caption(" Returned" + vehicles[availableVeh[vehicleInput.option()]].toString());
                // close window
                newRentalWindow.close();
            }
            
            });
        API::modal_window(newRentalWindow);
        });

    // view all vehicles button
    allVeh.events().click([&] {
        // update the information box
        information = "";

        for (Vehicle vehicle : vehicles) {
            information += vehicle.toString() + "\n";
        }

        if (information == "") {
            information = " There are no vehicles";
        }

        text.caption(information);
        });

    // view rented vehicles button
    rentedVeh.events().click([&] {
        // update the information box
        information = "";

        for (Vehicle vehicle : vehicles) {
            if (vehicle.customer != "N/A") {
                information += vehicle.toString() + "\n";
            }
        }

        if (information == "") {
            information = " There are no vehicles being rented";
        }

        text.caption(information);
        });

    // view late rentals button
    lateVeh.events().click([&] {
        // update the information box
        information = "";

        for (Vehicle vehicle : vehicles) {
            if (vehicle.end != -1 && vehicle.end < currentDay) {
                information += vehicle.toString() + "\n";
            }
        }

        if (information == "") {
            information = " There are no late vehicles";
        }

        text.caption(information);
        });

    // add a vehicle button
    addVeh.events().click([&] {
        // create a pop up window
        form newVehicleWindow(window, rectangle(50, 50, 550, 220));
        // create text boxes for input
        textbox nameInput{ newVehicleWindow };
        combox locInput{ newVehicleWindow };

        // push the combox options
        for (Location loc : locations) {
            locInput.push_back(loc.toString());
        }
        locInput.push_back(" NONE");

        // button to confirm changes
        button add{ newVehicleWindow, "Add" };
        add.bgcolor(color_rgb(0x7FEA78));
        // labels for input
        label nameLabel{ newVehicleWindow, "Enter vehicle name:" };
        label locLabel{ newVehicleWindow, "Enter vehicle location:" };
        label message{ newVehicleWindow, "" };

        // create layout and set components
        newVehicleWindow.div("vert <NAMELABEL weight = 10%><NAME><LOCLABEL weight = 10%><LOCATION><MESSAGE weight = 10%><ADD>");
        newVehicleWindow["NAMELABEL"] << nameLabel;
        newVehicleWindow["NAME"] << nameInput;
        newVehicleWindow["LOCLABEL"] << locLabel;
        newVehicleWindow["LOCATION"] << locInput;
        newVehicleWindow["MESSAGE"] << message;
        newVehicleWindow["ADD"] << add;
        newVehicleWindow.collocate();

        // button after confirming
        add.events().click([&] {
            string name;
            string location;
            int option;

            // store the input
            nameInput.getline(0, name);
            option = locInput.option();

            // confirm all values were filled
            if (name.empty() || locInput.option() == -1) {
                message.caption("Enter all the information!");
            }
            else {
                if (option == locations.size()) {
                    location = "not availabe for rent";
                    // create and add vehicle to vector
                    vehicles.push_back(Vehicle(name, "N/A"));
                }
                else {
                    location = locations[option].toString();
                    locations[option].cars++;
                    // create and add vehicle to vector
                    vehicles.push_back(Vehicle(name, location));
                }

                // print the added vehicle
                text.caption(" Added " + name + " - " + location);
                // close window
                newVehicleWindow.close();
            }
            });
        API::modal_window(newVehicleWindow);
        });

    // remove a vehicle button
    removeVeh.events().click([&] {
        // create a pop up window
        form removeVehicleWindow(window, rectangle(0, 0, 500, 120));
        // create comox box for input
        combox vehChoice{ removeVehicleWindow };

        // push the combox options
        for (Vehicle veh : vehicles) {
            vehChoice.push_back(veh.toString());
        }

        // button to confirm changes
        button remove{ removeVehicleWindow, "Remove" };
        remove.bgcolor(color_rgb(0xEA7878));

        // labels for input
        label vehLabel{ removeVehicleWindow, "Choose which Vehicle to remove:" };
        label message{ removeVehicleWindow, "" };

        // create layout and set components
        removeVehicleWindow.div("vert <VEHLABEL weight = 15%><VEHCHOICE><MESSAGE weight = 10%><REMOVE>");
        removeVehicleWindow["VEHLABEL"] << vehLabel;
        removeVehicleWindow["VEHCHOICE"] << vehChoice;
        removeVehicleWindow["MESSAGE"] << message;
        removeVehicleWindow["REMOVE"] << remove;
        removeVehicleWindow.collocate();

        // button after confirming
        remove.events().click([&] {
            string name;
            int option;

            // store the input
            option = vehChoice.option();
            name = vehicles[option].toString();

            // confirm selection has been made
            if (option == -1) {
                message.caption("Make a selection!");
            }
            else if (vehicles[option].customer != "N/A") {
                text.caption(" Can not delete a rented vehicle, " + name);
            }
            else {
                // remove from location count
                for (Location location : locations) {
                    if (vehicles[option].location == location.toString()) {
                        location.cars--;
                        break;
                    }
                }

                // delete the vehicle
                vehicles.erase(vehicles.begin() + option);

                // print the removed vehicle
                text.caption(" Removed " + name);
            }
            // close window
            removeVehicleWindow.close();
            });
        API::modal_window(removeVehicleWindow);
        });

    // define customer specific buttons
    // view all customers button
    allCust.events().click([&] {
        // update the information box
        information = "";

        for (Customer customer : customers) {
            information += customer.toStringDetailed() + "\n";
        }

        if (information == "") {
            information = " There are no Customers";
        }

        text.caption(information);
        });

    // view customers with rentals button
    rentCust.events().click([&] {
        // update the information box
        information = "";

        for (Vehicle vehicle : vehicles) {
            if (vehicle.customer != "N/A") {
                // find customer
                for (Customer cust : customers) {
                    string custString = cust.toStringDetailed();
                    if (custString == vehicle.customer) {
                        information += custString + "\n";
                    }
                }
            }
        }

        if (information == "") {
            information = " There are no Customers with Rentals";
        }

        text.caption(information);
        });

    // add a customer button
    addCust.events().click([&] {
        // create a pop up window
        form newCustomerWindow(window, rectangle(50, 50, 550, 320));
        // create text boxes for input
        textbox nameInput{ newCustomerWindow };
        textbox ageInput{ newCustomerWindow };
        textbox addressInput{ newCustomerWindow };
        checkbox prefCbox{ newCustomerWindow };
        prefCbox.caption("Preferred");
        // button to confirm changes
        button add{ newCustomerWindow, "Add" };
        add.bgcolor(color_rgb(0x7FEA78));
        // labels for input
        label nameLabel{ newCustomerWindow, "Enter customer name:" };
        label ageLabel{ newCustomerWindow, "Enter customer age:" };
        label addressLabel{ newCustomerWindow, "Enter customer address:" };
        label preferredLabel{ newCustomerWindow, "Enter customer status:" };
        label message{ newCustomerWindow, "" };

        // create layout and set components
        newCustomerWindow.div("vert <NAMELABEL weight = 10%><NAME><AGELABEL weight = 10%><AGE><ADDRESSLABEL weight = 10%><ADDRESS><PREFLABEL weight = 10%><PREF><MESSAGE weight = 10%><ADD>");
        newCustomerWindow["NAMELABEL"] << nameLabel;
        newCustomerWindow["NAME"] << nameInput;
        newCustomerWindow["AGELABEL"] << ageLabel;
        newCustomerWindow["AGE"] << ageInput;
        newCustomerWindow["ADDRESSLABEL"] << addressLabel;
        newCustomerWindow["ADDRESS"] << addressInput;
        newCustomerWindow["PREFLABEL"] << preferredLabel;
        newCustomerWindow["PREF"] << prefCbox;
        newCustomerWindow["MESSAGE"] << message;
        newCustomerWindow["ADD"] << add;
        newCustomerWindow.collocate();

        // ensure preferred status cannot be checked if under 26
        prefCbox.events().click([&] {
            string age;
            int ageNum;
            try {
                if (ageInput.getline(0, age))
                    ageInput.getline(0, age);
                ageNum = stoi(age);
                if (age != "" && ageNum <= 25)
                    prefCbox.check(false);
            }
            catch (exception& ex) {
                int i = 0;
                prefCbox.check(false);
            }
            });
        ageInput.events().key_release([&] {
            string age;
            int ageNum;
            try {
                if (ageInput.getline(0, age))
                    ageInput.getline(0, age);
                ageNum = stoi(age);
                if (age != "" && ageNum <= 25)
                    prefCbox.check(false);
            }
            catch (exception& ex) {
                prefCbox.check(false);
            }});
        
        // button after confirming
        add.events().click([&] {
            string name;
            string age;
            string address;
            bool preferred = false;
            bool digit = true;

            // store the input
            nameInput.getline(0, name);
            ageInput.getline(0, age);
            addressInput.getline(0, address);
            // check preferred status
            if (prefCbox.checked() == true) {
                preferred = true;
            }

            // confirm age is an int
            if (age.empty()) {
                digit = false;
            }
            else {
                for (char character : age) {
                    if (!isdigit(character)) {
                        digit = false;
                        break;
                    }
                }
            }

            // confirm all information has been inputted and correct
            if (digit == false) {
                message.caption("Age must be an integer!");
            }
            else if (stoi(age) <= 16) {
                message.caption("Customers must be atleast 16 years of age!");
            }
            else if (name.empty() || address.empty()) {
                message.caption("Fill in all the information!");
            } else{
                // create and add customer to vector
                customers.push_back(Customer(name, address, stoi(age), preferred));

                // print the added customer
                text.caption(" Added " + customers.back().toString());
                // close window
                newCustomerWindow.close();
            }
            });
        API::modal_window(newCustomerWindow);
        });

    // remove a customer button
    removeCust.events().click([&] {
        // create a pop up window
        form removeCustomerWindow(window, rectangle(0, 0, 500, 120));
        // create comox box for input
        combox custChoice{ removeCustomerWindow };

        // push the combox options
        for (Customer cust : customers) {
            custChoice.push_back(cust.toString());
        }

        // button to confirm changes
        button remove{ removeCustomerWindow, "Remove" };
        remove.bgcolor(color_rgb(0xEA7878));

        // labels for input
        label custLabel{ removeCustomerWindow, "Choose which Customer to remove:" };
        label message{ removeCustomerWindow, "" };

        // create layout and set components
        removeCustomerWindow.div("vert <CUSTLABEL weight = 15%><CUSTCHOICE><MESSAGE weight = 10%><REMOVE>");
        removeCustomerWindow["CUSTLABEL"] << custLabel;
        removeCustomerWindow["CUSTCHOICE"] << custChoice;
        removeCustomerWindow["MESSAGE"] << message;
        removeCustomerWindow["REMOVE"] << remove;
        removeCustomerWindow.collocate();

        // button after confirming
        remove.events().click([&] {
            string name;
            int option;

            // store the input
            option = custChoice.option();

            // confirm a selection has been made
            if (option == -1) {
                message.caption("Make a selection!");
            }
            else {
                name = customers[option].toString();

                // check if they are currently renting
                if (customers[option].rentals > 0) {
                    text.caption(" Cannot remove customers currently renting, " + name);
                }
                else {
                    // delete the customer
                    customers.erase(customers.begin() + option);

                    // print the removed customer
                    text.caption(" Removed " + name);
                }
                // close window
                removeCustomerWindow.close();
            }
            });
        API::modal_window(removeCustomerWindow);
        });

    // define location specific buttons
    // view all locations
    allLoc.events().click([&] {
        // update the information box
        information = "";

        for (Location location : locations) {
            information += location.toStringDetailed() + "\n";
        }

        if (information == "") {
            information = " There are no Locations";
        }

        text.caption(information);
        });

    // add a location
    addLoc.events().click([&] {
        // create a pop up window
        form newLocationWindow(window, rectangle(50, 50, 550, 220));
        // create text boxes for input
        textbox nameInput{ newLocationWindow };
        textbox addressInput{ newLocationWindow };
        // button to confirm changes
        button add{ newLocationWindow, "Add" };
        add.bgcolor(color_rgb(0x7FEA78));
        // labels for input
        label nameLabel{ newLocationWindow, "Enter location name:" };
        label adressLabel{ newLocationWindow, "Enter location address:" };
        label message{ newLocationWindow, "" };

        // create layout and set components
        newLocationWindow.div("vert <NAMELABEL weight = 10%><NAME><ADRESSLABEL weight = 10%><ADDRESS><MESSAGE weight = 10%><ADD>");
        newLocationWindow["NAMELABEL"] << nameLabel;
        newLocationWindow["NAME"] << nameInput;
        newLocationWindow["ADRESSLABEL"] << adressLabel;
        newLocationWindow["ADDRESS"] << addressInput;
        newLocationWindow["MESSAGE"] << message;
        newLocationWindow["ADD"] << add;
        newLocationWindow.collocate();

        // button after confirming
        add.events().click([&] {
            string name;
            string address;
            // store the input
            nameInput.getline(0, name);
            addressInput.getline(0, address);

            // confirm input is not empty
            if (name.empty() || address.empty()) {
                message.caption("Enter all requested information!");
            }
            else {
                // create and add customer to vector
                locations.push_back(Location(name, address));

                // print the added customer
                text.caption(" Added " + locations.back().toString());
                // close window
                newLocationWindow.close();
            }
            });
        API::modal_window(newLocationWindow);
        });

    // remove a location
    removeLoc.events().click([&] {
        // create a pop up window
        form removeLocationWindow(window, rectangle(0, 0, 500, 120));
        // create comox box for input
        combox locChoice{ removeLocationWindow };

        // push the combox options
        for (Location loc : locations) {
            locChoice.push_back(loc.toString());
        }

        // button to confirm changes
        button remove{ removeLocationWindow, "Remove" };
        remove.bgcolor(color_rgb(0xEA7878));

        // labels for input
        label locLabel{ removeLocationWindow, "Choose which Location to remove:" };
        label message{ removeLocationWindow, "" };

        // create layout and set components
        removeLocationWindow.div("vert <LOCLABEL weight = 15%><LOCCHOICE><MESSAGE weight = 10%><REMOVE>");
        removeLocationWindow["LOCLABEL"] << locLabel;
        removeLocationWindow["LOCCHOICE"] << locChoice;
        removeLocationWindow["MESSAGE"] << message;
        removeLocationWindow["REMOVE"] << remove;
        removeLocationWindow.collocate();

        // button after confirming
        remove.events().click([&] {
            string name;
            int option;

            // store the input
            option = locChoice.option();

            // confirm a location has been selected
            if (option == -1) {
                message.caption("Make a selection!");
            }
            else {
                name = locations[option].toString();
                if (locations[option].cars > 0) {
                    text.caption(" Cannot remove a location with vehicles, " + name);
                }
                else {
                    // delete the location
                    locations.erase(locations.begin() + option);

                    // print the removed location
                    text.caption(" Removed " + name);
                }
                // close window
                removeLocationWindow.close();
            }
            });
        API::modal_window(removeLocationWindow);
        });

    // show the window
    window.show();

    // event loop until window is closed
    exec();
}
