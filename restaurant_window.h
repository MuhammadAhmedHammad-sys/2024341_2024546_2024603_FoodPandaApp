#ifndef RWINDOW_H
#define RWINDOW_H

#include <iostream>
#include <string>
using namespace std;

#include "restaurant.h"
#include "menu.h"

class RestaurantWindow
{
private:
    Restaurants *r_arr;
    Menus *current_menu;
    Res_Node *current;

public:
    RestaurantWindow(Restaurants *r) : r_arr(r) {};

    bool login(int ID)
    {
        current = new Res_Node;
        Res_Node* temp = r_arr->getResByID(ID);

        current->id = temp->id;
        current->name = temp->name;
        current->loc_id = temp->loc_id;
        current->rating = temp->rating;

        if (!current)
        {
            cout << "Login failed! Incorrect Restaurant ID.\n";
            return false;
        }

        current_menu = new Menus(current->name);
        return true;
    }

    bool signup(int ID, string username, int location_code, float rating)
    {
        current = new Res_Node{ID, username, rating, location_code};
        r_arr->add_res(*current);
        current_menu = new Menus(username);
        return true;
    }

    void menu()
    {
        bool verified = false;

        cout << "\n===== Restaurant Manager Menu =====\n";
        do
        {
            cout << "1. Login\n";
            cout << "2. Signup\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            cout << endl;
            switch (choice)
            {
            case 1:
            {
                int res_id;
                cout << "Enter Restaurant ID: ";
                cin >> res_id;
                verified = login(res_id);
                if (verified)
                {
                    cout << "\nLogin successful!\n";
                }
                break;
            }
            case 2:
            {
                string res_name;
                int res_id;
                int loc_code;
                float rating;
                cout << "Enter Restaurant ID: ";
                cin >> res_id;
                cout << "Enter Restaurant Name: ";
                cin.ignore();
                getline(cin, res_name);
                cout << "Enter Location Code: ";
                cin >> loc_code;
                cout << "Enter Rating: ";
                cin >> rating;
                verified = signup(res_id, res_name, loc_code, rating);
                if (verified)
                {
                    cout << "\nSignup successful! You are now logged in.\n";
                }
            }
            break;
            default:
                cout << "Invalid choice!\n";
            }

            if (!verified)
            {
                cout << "Please try again.\n";
            }

        } while (!verified);

        while (true)
        {
            cout << "\n===== " << current->name << " =====\n";
            cout << "1. View Menu\n";
            cout << "2. Add Menu Item\n";
            cout << "3. Logout\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            cout << "\n";
            switch (choice)
            {
            case 1:
            {
                cout << "Displaying menu for " << current->name << "\n";
                current_menu->displayItems();
                break;
            }
            case 2:
            {
                Item_Node new_item;
                cout << "Enter Item Serial Number: ";
                cin >> new_item.sr_no;
                cout << "Enter Item Name: ";
                cin >> new_item.name;
                cout << "Enter Item Price: ";
                cin >> new_item.price;
                current_menu->insertItem(new_item);
                cout << "Item added successfully!\n";
                break;
            }
            case 3:
                cout << "Logging out...\n";
                return;
            default:
                cout << "Invalid choice!\n";
            }
        }
    }

    ~RestaurantWindow()
    {
        delete current_menu;
        delete current;
    }
};

#endif