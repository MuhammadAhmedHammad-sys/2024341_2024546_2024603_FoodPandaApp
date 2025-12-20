#include <iostream>
using namespace std;

#include "customer.h"
#include "Locations.h"
#include "restaurant.h"

#include "customer_window.h"
#include "restaurant_window.h"

int main()
{

    cout << "\n================================ FoodPanda App ================================\n\n";
    cout << "Initialising....\n";

    Restaurants *rests = new Restaurants();
    CustomerHashTable *customers = new CustomerHashTable();

    while (true)
    {
        cout << "\n======== Menu ========\n";
        cout << "1. Restaurant Portal\n";
        cout << "2. Customer Portal\n";
        cout << "3. Exit Application\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            RestaurantWindow rWindow(rests);
            rWindow.menu();
            break;
        }
        case 2:
        {
            CustomerWindow cWindow(customers, rests);
            cWindow.menu();
            break;
        }
        case 3:
            cout << "Exiting application. Goodbye!\n";
            delete rests;
            delete customers;

            return 0;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }
}