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
    string fileName = "herbs.txt";
    ofstream out;
    out.open(fileName);

    if(!out)
    {
        cerr << "File did not open correctly. Program terminating.";
        exit(EXIT_FAILURE);
    }

    shared_ptr<Node<Herb>> current = list.getHead();

    while(current)
    {
        //Herb temp = current->getData();
        out << current->getData() << endl;
        current = current->getNext();
    }

    out.close();

}

void loadList(string file, DLL<Herb>& list)
{
    ifstream in;
    string hName;
    int hDosage;
    string hUses;
    string hPrecautions;
    string hPreparations;
    Herb anHerb;

    in.open(file);
    if(!in)
    {
        cerr << "File did not open correctly... program terminating." << endl;
        exit(EXIT_FAILURE);
    }

    //something here????
    //check "in" API for file reading
    //need to read a string until we reach ';'

    getline(in, hName, ';');

    while(!in.eof())
    {

        in >> hDosage;
        in.ignore(); 
        getline(in, hUses, ';');
        getline(in, hPrecautions, ';');
        getline(in, hPreparations, '\n');

        anHerb.addNew(hName, hDosage, hUses, hPrecautions, hPreparations);

        //add to DLL
        list.insert(anHerb);

        getline(in, hName, ';');


    }
    in.close();
}


int main()
{
    DLL<Herb> herbList;
    char option;
    string fileName = "herbs.txt";

    //load text file here
    loadList(fileName, herbList); 

    do {
        option = getOption();
        executeOption(option, herbList);
        cout << endl;

    }  while (tolower(option) != 'e');

    //save text file here
    save(herbList);

    cout << endl;
}
