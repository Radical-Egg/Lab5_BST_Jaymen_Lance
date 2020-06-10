#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "queue.h"
#include "SinglyLinkedList.h"
#include "Currency.h"



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
    ifstream inFile;

    inFile.open("data.txt");

    for (int i = 0; i < 10; i++)
    {
       inFile >> (*(myDollar + i));
    }
    inFile.close();
}

int main()
{
    Currency* myCurrency = new Currency[10];

    read(myCurrency);
    print(myCurrency);

    BST<Currency> myBST(myCurrency[0]);
    return 0;
}

/*
int main()
{
    Dollar* myDollar = new Dollar[10];

    read(myDollar);
    print(myDollar);


    BST<Dollar> myBST(myDollar[0]);

    for (int i = 0; i < 10; i++)
    {
        myBST.insert(myDollar[i]);
    }

    myBST.printDataInOrder();

    bool flag = true;

    char x;
    cout << " A. Add\n B. Search \n C. Delete" << endl;
    cin >> x;

    switch(x)
    {
        // add
        case 'A':
            Dollar* addDollar = new Dollar();
            Dollar test;
            cout << "Enter dollar value (format dollar 24 15 cent): ";
            cin >> addDollar;
            myBST.insert(addDollar[0]);
            cout << addDollar[0] << "Has been added to the BST! " << endl;
            delete addDollar;
            myBST.printDataInOrder();
            break;
    }

    delete[] myDollar;
    //cout << myDollar[1];

}
*/


