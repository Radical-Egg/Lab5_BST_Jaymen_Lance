#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include "BST.h"
#include "queue.h"
#include "SinglyLinkedList.h"
#include "Currency.h"


const int SIZE = 10;

using namespace std;


/*
void clear_screen();

clear the screen for windows or POSIX

Pre:	None.
Post:	None.
Return:	None.
*/
void clear_screen()
{
    #ifdef _WIN32
        std::system("cls");
    #else
    std::system("clear");
    #endif
}
/*
void print(Currency *myDollar);

print an array of currency objects

Pre:	Currency *myDollar.
Post:	None.
Return:	None.
*/
void print(Currency *myDollar)
{
    for (int i = 0; i < 10; i++)
    {
        cout << (*(myDollar + i));
    }
}
/*
void read(Currency *myDollar)

read data from file and assign the data to currency objects

Pre:	Currency *myDollar.
Post:	None.
Return:	None.
*/
void read(Currency *myDollar)
{
    // file
    ifstream inFile;

    // file path
    std::string file_path;

    // get file path
    std::cout << "Enter file path: " << std::endl;
    getline(cin, file_path);

    // open then file
    inFile.open(file_path.c_str());

    // assigning data
    for (int i = 0; i < SIZE; i++)
    {
       inFile >> (*(myDollar + i));
    }
    inFile.close(); // close file
}


int main()
{
    // currency objects
    Currency* myCurrency = new Currency[SIZE];
    Currency* addedCurrency = new Currency();

    // read from file and create objects
    cout << "Creating currency objects from text file " << endl;
    read(myCurrency);
    cout << "objects created" << endl;

    // BST object 
    BST<Currency>* myBST = new BST<Currency>();

    cout << "Putting all currency object into Binary Search Tree" << endl;
    for (int i = 0; i < SIZE - 1; i++)
    {
        myBST->insert(myCurrency[i]); // adding objects to BST
    }
    cout << "Complete" << endl;
    // moving to main menu, clearing input buffer as well
    cout << "Press any key to move to the main menu" << endl;
    //cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    getchar();
    clear_screen();

    // bool variable for main menu and int variables for object creation
    bool flag = true;
    int i, j;
    while (flag) // main menu
    {
        char userResponse; // char variable for switch
        // main menu stdout
        cout << "Select from the following: \n A. Add data to BST\n B. Search for data in the BST\n C. Delete Data from BST\n D. Print Data in all traversal methods\n E. Exit and Print" << endl;
        // toupper the userResponse so that the user doesn't need to worry about case
        userResponse = toupper(getchar());

        // start switch
        switch(userResponse)
        {
            // case A - Add data
            case 'A':
                cout << "Add some data to this BST\nInput(two integers, example: 24 25):" << endl;
                // clear buffer
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                while (!(cin >> i >> j)) // while loop to ensure user puts in int values
                {
                    cout << "input is not valid, integers only" << endl;
                    cout << "Follow this example - 22 25" << endl;
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                // add data to currency object
                addedCurrency->setNoteValue(i);
                addedCurrency->setCoinValue(j);

                // insert data into bst
                myBST->insert(*(addedCurrency));
                // let the user know the data has been added
                cout << "You have added the following data to the BST: " << addedCurrency->getNoteName() << " " << addedCurrency->getNoteValue() << " " << addedCurrency->getCoinValue() << " " << addedCurrency->getCoinName() << endl;
                cout << "Press any key to continue...." << endl;
                // clear input buffer 
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();

                break;
            // case B - Search data
            case 'B':
                cout << "Search for some data in this BST\nInput(two integers, example: 24 25): " << endl;
                // clear buffer
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                while (!(cin >> i >> j)) // while loop to ensure user puts in int values
                {
                    cout << "input is not valid, integers only" << endl;
                    cout << "Follow this example - 22 25" << endl;
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                // add data to currency object
                addedCurrency->setNoteValue(i);
                addedCurrency->setCoinValue(j);

                // check to see if the data is there, if 1 then its true and let the user know the data is there, otherwise false and let the user know data could not be found
                if (myBST->contains(*addedCurrency) == 1)
                {
                    cout << "This data is exists in the BST" << endl;
                }
                else
                {
                    cout << "Data not found in the BST" << endl;
                }
                cout << "Press any Key to continue..." << endl;

                // clear buffer
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();

                break;
            // case C - Delete data
            case 'C':
                cout << "Delete some data from this BST\nInput(two integers, example: 24 25):" << endl;
                // clear buffer
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                while (!(cin >> i >> j)) // while loop to ensure puts in int values
                {
                    cout << "input is not valid, integers only" << endl;
                    cout << "Follow this example - 22 25" << endl;
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                // add data to currency object
                addedCurrency->setNoteValue(i);
                addedCurrency->setCoinValue(j);

                // if the data is there remove it, otherwise let them know it could not be found, therefore cannot be removed
                if (myBST->remove(*addedCurrency) == 1)
                {
                    cout << "data has been removed" << endl;
                }
                else
                {
                    cout << "data is not there so... it cannot be removed" << endl;
                }
                cout << "Press any Key to continue..." << endl;

                // clear buffer
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();

                break;
            // case D - print data
            case 'D':
                // print data in order, breadth first, post, and pre order
                cout << "Printing Data in Order " << endl;
                myBST->printDataInOrder();
                cout << "\n Printing Data Breadth First " << endl;
                myBST->printDataBreadthFirst();
                cout << "\n Printing Data Post Order " << endl;
                myBST->printDataPostOrder();
                cout << "\nPrinting Data Pre Order " << endl;
                myBST->printDataPreOrder();

                cout << "Press any Key to continue..." << endl;
                
                // clear buffer
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();
                
                break;
            // case E - print and exit
            case 'E':
                // print data in order, breadth first, post, and pre order
                cout << "Printing Data in Order " << endl;
                myBST->printDataInOrder();
                cout << "\n Printing Data Breadth First " << endl;
                myBST->printDataBreadthFirst();
                cout << "\n Printing Data Post Order " << endl;
                myBST->printDataPostOrder();
                cout << "\nPrinting Data Pre Order " << endl;
                myBST->printDataPreOrder();
                
                // free memory
                delete addedCurrency;
                delete[] myCurrency;
                delete myBST;
                
                // break out of loop and exit
                flag = false;
                break;
            default:
                // make sure the user is inputting valid response
                cout << "Not a valid option, choices are not case sensitive - a,b,c,d,e are all valid - anything else is not!" << endl;
                cout << "Press any Key to continue..." << endl;

                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();
                
                break;
        }
    }
    
    return 0;
}

