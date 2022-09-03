#include "herb.h"
#include "DLL.h"

void menu ()
{
    cout << endl << "Welcome to my herbal medicine dictionary!" << endl;
    cout << "a. Add new herb to the list" << endl;
    cout << "b. Remove herb from the list" << endl;
    cout << "c. Search for an herb by name" << endl;
    cout << "d. Display the list of herbs" << endl; 
    cout << "e. Exit" << endl << endl;
    cout << "Select from the options above: ";


}


int main()
{
    Herb herb;
    DLL<Herb> list;
    char option;

    //load text file here

    cout << endl << "Welcome to my herbal medicine dictionary!" << endl;
    cout << "a. Add new herb to the list" << endl;
    cout << "b. Remove herb from the list" << endl;
    cout << "c. Search for an herb by name" << endl;
    cout << "d. Display the list of herbs" << endl; 
    cout << "Select from the options above: ";
    
    cin >> option;
    getchar();

    do {
        switch(option)
        {
            case 'a':
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
            case 'b':
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
            case 'c':
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
            case 'd':
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

        menu();
        cin >> option;
        getchar();
        tolower(option);
        cout << endl;

    }  while (option == 'a' || option == 'b' || option == 'c' || option == 'd');

    //save text file here

    cout << endl;
}
