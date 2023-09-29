#include "MyBag.h"

MyBag::MyBag()
{
    size = 0;
    capacity = 0;
}

MyBag::MyBag(int newSize, int newCapacity)
{
    size = newSize;
    capacity = newSize;
}

void MyBag::setSize(int newSize)
{
    size = newSize;
}

int MyBag::getSize()
{
    size = myBag.size();
    return size;
    //return myBag.size();
}

void MyBag::setCapacity(int newCapacity)
{
    capacity = newCapacity;
}

int MyBag::getCapacity()
{
    capacity = myBag.capacity();
    return capacity;
    //return myBag.capacity();
}

MyBag::~MyBag()
{}

void MyBag::subMenu()
{

    do
    {
        system("cls");
        cout << endl;
        cout << "\t1> Non-template MyBag of integers" << endl;
        cout << "\t" << string(80, char(205)) << endl;
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
        case '0': system("cls"); mainMenu(); break;
        case 'A':
        {
            myBag.clear();

            cout << "\nMy bag is cleared of all elements.\n";
            cout << endl << "The size of the bag is: " << getSize() << endl << endl;
        }system("pause"); system("cls"); break;
        case 'B':
        {
            int insertInt = inputInteger("\nEnter a value and insert into MyBag: ");
            myBag.push_back(insertInt);
        }break;
        case 'C':
        {
            cout << endl << "The size of the bag is: " << getSize() << endl << endl;
            int findValue = inputInteger("\nEnter a value to search from MyBag: ");
            bool found = false;

            for (int i = 0; i < getSize(); i++)
            {
                if (myBag.at(i) == findValue)
                {
                    found = true;
                    cout << "\n" << findValue << " is at index: " << i << endl;
                }
            }

            if (!found)
            {
                cout << "\nThe number you entered is not in the bag.\n";
            }

        }system("pause"); system("cls"); break;
        case 'D':
        {
            int index = inputInteger("\nEnter an index to erase: ", 0, 100);
            cout << endl;
            if (index < 0 || index >= myBag.size())
            {
                cout << "Invalid index or index out of range.\n";
            }
            else
            {
                myBag.erase(myBag.begin() + index);
            }

        }system("pause"); system("cls"); break;
        case 'E':
        {
            // sort the vector
            sort(myBag.begin(), myBag.end());

        }system("pause"); break;
        case 'F':
        {
            // Print the sorted vector
            cout << "\nSorted Vector: ";
            for (int num : myBag) {
                cout << num << " ";
            }
            cout << endl << endl;

            cout << endl << "The size of the bag is: " << getSize() << endl;
            cout << endl << "The capacity of the bag is: " << getCapacity() << endl << endl;
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