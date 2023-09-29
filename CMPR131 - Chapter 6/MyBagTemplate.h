#pragma once

// still buggy

#include <iostream>
#include <vector>
#include "input.h"
#include <algorithm>

using namespace std;

char inputChar(string prompt, string options);
void mainMenu();
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);

template<typename T>
class MyBagTemplate;

template<>
class MyBagTemplate<double>
{
private:
    vector<double> data;

public:
    MyBagTemplate() {} // default constructor
    ~MyBagTemplate() {}  // destructor

    // Functions to interact with the bag
    void add(double value) {
        data.push_back(value);
    }  // add a value to the bag

    bool remove(double value);  // remove a value from the bag
    bool isEmpty() const { return data.empty(); }  // check if the bag is empty
    int getCurrentSize() const { return data.size(); }  // get the current size of the bag
    void clear() { data.clear(); }  // clear the bag
    int getFrequencyOf(double value) const;  // get the frequency of a value in the bag
    bool contains(double value) const;  // check if a value is in the bag
    void display() const;  // display the contents of the bag

    // submenu function
    void subMenu();
};


void MyBagTemplate<double>::subMenu()
{
    do
    {
        system("cls");
        cout << endl;
        cout << "\t1> Template MyBag" << endl;
        cout << "\t" << std::string(80, char(205)) << endl;
        cout << "\t\tA> clear" << endl;
        cout << "\t\tB> insert" << endl;
        cout << "\t\tC> search" << endl;
        cout << "\t\tD> remove" << endl;
        cout << "\t\tE> sort" << endl;
        cout << "\t\tF> display" << endl;
        cout << "\n\t" << string(80, char(169));
        cout << "\n\t0 > exit" << endl;
        cout << "\t" << string(80, char(205)) << endl;

        // get user input/option of main menu
        char option = inputChar("\n\tOption: ", "0ABCDEF");

        switch (option)
        {
        case '0':
            system("cls");
            mainMenu();
            break;
        case 'A':
            clear();
            cout << "\nMy bag is cleared of all elements.\n";
            cout << endl << "The size of the bag is: " << data.size() << endl << endl;
            system("pause"); system("cls");
            break;
        case 'B':
        {
            double insertValue = static_cast<double>(inputInteger("\nEnter a value and insert into MyBag: "));
            add(insertValue);
        }
        break;
        case 'C':
        {
            cout << endl << "The size of the bag is: " << data.size() << endl << endl;
            double findValue = static_cast<double>(inputInteger("\nEnter a value to search from MyBag: "));
            bool found = false;
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i] == findValue)
                {
                    found = true;
                    cout << "\n" << findValue << " is at index: " << i << endl;
                }
            }
            if (!found)
            {
                cout << "\nThe number you entered is not in the bag.\n";
            }
            system("pause"); system("cls");
        }
        break;
        case 'D':
        {
            int index = inputInteger("\nEnter an index to erase: ", 0, 100);
            cout << endl;
            if (index < 0 || index >= data.size())
            {
                cout << "Invalid index or index out of range.\n";
            }
            else
            {
                data.erase(data.begin() + index);
            }
            system("pause"); system("cls");
        }
        break;
        case 'E':
        {
            // sort the vector
            sort(data.begin(), data.end());
            system("pause");
        }
        break;
        case 'F':
        {
            // Print the sorted vector
            cout << "\nSorted Vector: ";
            for (double item : data) {
                cout << item << " ";
            }
            cout << std::endl << std::endl;

            cout << endl << "The size of the bag is: " << data.size() << endl << endl;
            system("pause");
        }
        system("pause");
        break;
        default:
            cout << "Invalid option. Please enter a valid option.\n";
        }

        // new line
        cout << "\n";

    } while (true);
}