#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include "BST.h"
#include "queue.h"
#include "SinglyLinkedList.h"
#include "Currency.h"


const int SIZE = 25;

using namespace std;

void clear_screen()
{
    #ifdef WINDOWS
        std::system("cls");
    #else
    std::system("clear");
    #endif
}
void print(Currency *myDollar)
{
    for (int i = 0; i < 10; i++)
    {
        cout << (*(myDollar + i));
    }
}
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
    inFile.open(file_path);

    for (int i = 0; i < 10; i++)
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

    read(myCurrency);
    print(myCurrency);

    BST<Currency>* myBST = new BST<Currency>();

    for (int i = 0; i < SIZE; i++)
    {
        myBST->insert(myCurrency[i]);
    }

    bool flag = true;
    int i, j;
    while (flag)
    {
        char userResponse;
        cout << "Select from the following: \n A. Add data to BST\n B. Search for data in the BST\n C. Delete Data from BST\n D. Print Data in all traversal methods\n E. Exit and Print" << endl;
        userResponse = toupper(getchar());

        switch(userResponse)
        {
            case 'A':
                cout << "Add some data to this BST\nInput(two integers, example: 24 25):" << endl;

                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                while (!(cin >> i >> j))
                {
                    cout << "input is not valid, integers only" << endl;
                    cout << "Follow this example - 22 25" << endl;
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                
                addedCurrency->setNoteValue(i);
                addedCurrency->setCoinValue(j);

                myBST->insert(*(addedCurrency));

                cout << "You have added the following data to the BST: " << addedCurrency->getNoteName() << " " << addedCurrency->getNoteValue() << " " << addedCurrency->getCoinValue() << " " << addedCurrency->getCoinName() << endl;
                cout << "Press any key to continue...." << endl;
              
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();

                break;
            case 'B':
                cout << "Search for some data in this BST: " << endl;

                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                while (!(cin >> i >> j))
                {
                    cout << "input is not valid, integers only" << endl;
                    cout << "Follow this example - 22 25" << endl;
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                addedCurrency->setNoteValue(i);
                addedCurrency->setCoinValue(j);
                if (myBST->contains(*addedCurrency) == 1)
                {
                    cout << "This data is exists in the BST" << endl;
                }
                else
                {
                    cout << "Data not found in the BST" << endl;
                }
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();
                break;
            case 'C':
                cout << "Delete some data from this BST" << endl;
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                while (!(cin >> i >> j))
                {
                    cout << "input is not valid, integers only" << endl;
                    cout << "Follow this example - 22 25" << endl;
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                addedCurrency->setNoteValue(i);
                addedCurrency->setCoinValue(j);

                if (myBST->remove(*addedCurrency) == 1)
                {
                    cout << "data has been removed" << endl;
                }
                else
                {
                    cout << "data is not there so... it cannot be removed" << endl;
                }
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();
                break;
            case 'D':
                myBST->printDataInOrder();
                myBST->printDataBreadthFirst();
                myBST->printDataPostOrder();
                myBST->printDataPreOrder();
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                getchar();
                clear_screen();
                break;
            case 'E':
                myBST->printDataInOrder();
                myBST->printDataBreadthFirst();
                myBST->printDataPostOrder();
                myBST->printDataPreOrder();
                delete addedCurrency;
                delete[] myCurrency;
                delete myBST;
                flag = false;
                break;
            default:
                cout << "Not a valid option, choices are not case sensitive - a,b,c,d,e are all valid - anything else is not!" << endl;
                break;
        }
    }
    
    return 0;
}

