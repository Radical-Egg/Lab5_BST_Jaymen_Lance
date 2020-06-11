#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "queue.h"
#include "SinglyLinkedList.h"
#include "Currency.h"


const int SIZE = 10;

using namespace std;

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

    read(myCurrency);
    print(myCurrency);

    BST<Currency>* myBST = new BST<Currency>();

    for (int i = 0; i < SIZE; i++)
    {
        myBST->insert(myCurrency[i]);
    }

    myBST->printDataInOrder();
    myBST->printDataBreadthFirst();
    myBST->printDataPostOrder();
    myBST->printDataPreOrder();
    
    return 0;
}

