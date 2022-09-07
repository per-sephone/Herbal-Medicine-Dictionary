#include "herb.h"
#include "DLL.h"
#include <fstream>



void menu()
{
    cout << endl << "Herbal Medicine Dictionary Menu" << endl;
    cout << "---------------------------------" << endl;
    cout << "a. Insert new herb to the list" << endl;
    cout << "b. Remove herb from the list" << endl;
    cout << "c. Search for an herb by name" << endl;
    cout << "d. Display the list of herbs" << endl; 
    cout << "e. Exit" << endl << endl;
    cout << "Select from the options above: ";
}

char getOption()
{
    char opt;
    menu(); 
    cin >> opt;
    getchar();

    return opt;
}

void executeOption(char option, DLL<Herb>& list)
{
        Herb herb;

        switch(option)
        {
            case 'a': //insertion
            {
                herb.addNew();

                try{
                    list.insert(herb);
                }
                catch(...)
                {
                    cerr << "Error occured during insert" << endl;
                }
                break;
            }
            case 'b': //removal
            {
                string input;
                cout << "Enter the name of the herb you would like to remove: ";
                getline(cin, input);
                
                try {
                list.remove(input);
                }
                catch(...)
                {
                    cerr << "Error occured during remove" << endl;
                }

                break;
            }
            case 'c': //search
            {
                string input;

                cout << "Enter the name of the herb you would like to search: ";
                getline(cin, input);
                cout << endl;

                try{
                (list.search(input))->display();
                }
                catch(...)
                {
                    cerr << "Error occured during search" << endl;
                }

                break;
            }
            case 'd': //display
            {
                try{
                list.display();
                }
                catch(...)
                {
                    cerr << "List is empty" << endl;
                }
                break;
            }
            default:
            {
                break;
            }
        }

}

void save(DLL<Herb>& list)
{

    ofstream out;
    out.open("herbs.txt");

    if(!out)
    {
        cerr << "File did not open correctly. Program terminating.";
        exit(1);
    }

    shared_ptr<Node<Herb>> current = list.getHead();


    while(current != nullptr)
    {
        Herb temp = current->getData();
        out << temp << endl;
        current = current->getNext();
    }

    out.close();

}

int main()
{
    DLL<Herb> herbList;
    char option;

    //load text file here


    do {
        option = getOption();
        executeOption(option, herbList);
        cout << endl;

    }  while (tolower(option) != 'e');

    //save text file here
    save(herbList);

    cout << endl;
}
