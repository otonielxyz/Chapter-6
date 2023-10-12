#pragma once

#include <iostream>
#include <algorithm>

using namespace std;


char inputChar(string prompt, string options);
void mainMenu();
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);

template <typename T>
class MyBagTemplate;

template <>
class MyBagTemplate<double> {
private:
    double* data;      // Pointer to the dynamic array
    int size;          // Number of elements currently in the array
    int capacity;      // Current capacity of the array

public:
    MyBagTemplate() : data(nullptr), size(0), capacity(0) {}
    ~MyBagTemplate() { delete[] data; }

    // Functions to interact with the bag
    void add(double value);
    void clear();
    bool contains(double value) const;
    void ensureCapacity(int newCapacity);

    // submenu function
    void subMenu();
};

// Precondition: None
// Postcondition: Adds value to the bag
void MyBagTemplate<double>::add(double value) {
    if (size == capacity) {
        ensureCapacity((capacity == 0) ? 1 : capacity * 2);
    }
    data[size++] = value;
}

// Precondition: None
// Postcondition: Clears bag
void MyBagTemplate<double>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

// Precondition: newCapacity is a non-negative integer
// Postcondition: The bag has a capacity of at least newCapacity
void MyBagTemplate<double>::ensureCapacity(int newCapacity) {
    if (newCapacity > capacity) {
        double* newData = new double[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

// Precondition: None
// Postcondition: Returns true if the value is in the bag, false otherwise
bool MyBagTemplate<double>::contains(double value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

// Precondition: None
// Postcondition: Gives user a menu to interact with the bag
void MyBagTemplate<double>::subMenu()
{
    do
    {
        system("cls");
        cout << endl;
        cout << "\t1> Template MyBag of doubles" << endl;
        cout << "\t" << string(80, char(205)) << endl;
        cout << "\t\t1> clear" << endl;
        cout << "\t\t2> insert" << endl;
        cout << "\t\t3> search" << endl;
        cout << "\t\t4> remove" << endl;
        cout << "\t\t5> sort" << endl;
        cout << "\t\t6> display" << endl;
        cout << "\n\t" << string(80, char(169));
        cout << "\n\t0 > exit" << endl;
        cout << "\t" << string(80, char(205)) << endl;

        // get user input/option of main menu
        int option = inputInteger("\n\tOption: ", 0, 6);

        switch (option)
        {
        case 0: // Return to Main Menu
        {
            system("cls");
            mainMenu();
        } break;
        case 1: // Clear MyBag
        {
            clear();
            cout << "\nMy bag is cleared of all elements.\n\n";
        } break;
        case 2: // Insert a value to MyBag
        {
            double insertValue = static_cast<double>(inputInteger("\nEnter a value and insert into MyBag: "));
            add(insertValue);
            cout << "\nValue " << insertValue << " has been inserted into MyBag.\n\n";
        } break;
        case 3: // Search
        {
            double findValue = static_cast<double>(inputInteger("\nEnter a value to search from MyBag: "));
            bool found = contains(findValue);
            if (found) {
                cout << "\nValue " << findValue << " is in MyBag.\n\n";
            }
            else {
                cout << "\nValue " << findValue << " is not in MyBag.\n\n";
            }
        } break;
        case 4: // Remove an element at index
        {
            int index = inputInteger("\nEnter an index to be deleted: ", 0, size - 1);
            cout << endl;
            if (index < 0 || index >= size)
            {
                cout << "Invalid index or index out of range.\n\n";
            }
            else
            {
                double removedValue = data[index];
                for (int i = index; i < size - 1; i++) {
                    data[i] = data[i + 1];
                }
                size--;
                cout << "Value " << removedValue << " at subscript " << index << " has been deleted.\n\n";
            }
        } break;
        case 5: // Sort
        {
            sort(data, data + size);
            cout << "\nMyBag has been sorted.\n\n";
        } break;
        case 6: // Display
        {
            cout << "\nMyBag:\n ";
            for (int i = 0; i < size; i++)
            {
                cout << endl << "[" << i << "] - " << data[i] << " \n";
            }
            cout << endl << endl;
        } 
        break;
        default:
            cout << "Invalid option. Please enter a valid option.\n";
        }

        // Pause display after every case
        system("pause");

        // New line
        cout << "\n";

    } while (true);
}