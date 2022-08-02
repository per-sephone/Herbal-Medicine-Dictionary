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


    //linked.load();
    menu(); 
    cin >> option;
    getchar();

    do {
        switch(option)
        {
            case 'a':
            {
                herb.addNew();
                list.insert(herb);
                break;
            }
            case 'b':
            {
                //string input;
                //cout << "Enter the name of the herb you would like to remove: ";
                //getline(cin, input);
                //list.remove(input);
                break;
            }
            case 'c':
            {
                //string input;
                //cout << "Enter the name of the herb you would like to search: ";
                //getline(cin, input);
                //list.search(input);
                break;
            }
            case 'd':
            {
                list.display();
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

    cout << endl;
}
