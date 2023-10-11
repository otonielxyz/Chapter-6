#include "MyBag.h"

// Credit: Erik Santana

//Pre-Condition: No parameters.
//Post-Condition: No return. Initializer Constructor
MyBag::MyBag()
{
    size = 0;
    capacity = 0;
}

//Pre-Condition: Parameters - int newSize, int newCapacity
//Post-Condition: No return. Argument Constructor.
MyBag::MyBag(int newSize, int newCapacity)
{
    size = newSize;
    capacity = newCapacity;
}

//Pre-Condition: Parameter - int newSize
//Post-Condition: No return. Setter mutates *size.
void MyBag::setSize(int newSize)
{
    size = newSize;
}

//Pre-Condition: No parameters.
//Post-Condition: Returns *size. Getter only accesses *size.
int MyBag::getSize() const
{
    return size;
}

//Pre-Condition: Parameter - int newCapacity
//Post-Condition: No return. Setter mutates *capacity.
void MyBag::setCapacity(int newCapacity)
{
    capacity = newCapacity;
}

//Pre-Condition: No parameters.
//Post-Condition: Returns *capacity. Getter only accesses *capacity.
int MyBag::getCapacity() const
{
    return capacity;
}

//Pre-Condition: No paremters.
//Post-Condition: No return. Destructor.
MyBag::~MyBag()
{
    newValue = nullptr;
    delete[] newValue;
}

//Pre-Condition: No parameters.
//Post-Condition: No return. Logic and main MyBag function with a menu.
void MyBag::subMenu()
{
    do
    {
        system("cls");
        cout << endl;
        cout << "\t1> Non-template MyBag of integers" << endl;
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
        }break;
        case 1: // Clear MyBag
        {
            myBag.clear();
            cout << "\nMy bag is cleared of all elements.\n\n";

        }break;
        case 2: // Insert a value to MyBag
        {
            *newValue = inputInteger("\nEnter a value and insert into MyBag: ");
            myBag.push_back(*newValue);

            cout << endl << *newValue << " has been inserted into MyBag.\n\n";
        }break;
        case 3: // Search
        {
            int findValue = inputInteger("\nEnter a value to search from MyBag: ");
            bool found = false;

            for (int i = 0; i < myBag.size(); i++)
            {
                if (myBag.at(i) == findValue)
                {
                    found = true;
                    cout << "\nValue " << findValue << " is at found at subscript #" << i << endl << endl;
                }
            }

            if (!found)
            {
                cout << "\nValue " << findValue << " is not in MyBag.\n\n";
            }

        }break;
        case 4: // Remove an element at index
        {
            int index = inputInteger("\nEnter an index to be deleted: ", 0, myBag.size() - 1);
            cout << endl;
            if (index < 0 || index >= myBag.size())
            {
                cout << "Invalid index or index out of range.\n\n";
            }
            else
            {
                myBag.erase(myBag.begin() + index);
                cout << "Subscript " << index << " has been deleted.\n\n";
            }

        }break;
        case 5: // Sort
        {
            // sort the vector
            sort(myBag.begin(), myBag.end());

            cout << "\nMyBag has been sorted.\n\n";

        }break;
        case 6: // Display
        {
            cout << "\nMyBag:\n ";

            for (int i = 0; i < myBag.size(); i++)
            {
                cout << endl << "[" << i << "] - " << myBag[i] << " \n";
            }
            cout << endl << endl;

        }break;
        default:
            cout << "Invalid option. Please enter a valid option.\n";
        }

        // Pause display after every case
        system("pause");

        // New line
        cout << "\n";

    } while (true);

}