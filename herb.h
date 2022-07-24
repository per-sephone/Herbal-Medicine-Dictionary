#ifndef HERB_H
#define HERB_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

class Herb 
{
    protected:
        string name;
        int dosage; //in milligrams
        string uses;
        string precautions;
        string preparations;

    public: 
        Herb();
        Herb(const Herb& toCopy);
        ~Herb();
        
        Herb& operator=(const Herb& h);
        bool operator>(const Herb& h) const;
        bool operator>=(const Herb& h) const;
        bool operator<(const Herb& h) const;
        bool operator<=(const Herb& h) const;
        bool operator==(const Herb& h) const;
        bool operator!=(const Herb& h) const;
        friend ostream& operator<<(ostream& out, const Herb& herb);
        
        void addNew(const string n, const int d, const string u, 
                const string p, const string prep);
        void addNew();
        void newName();
        void newDosage();
        void newUse();
        void newPrecaution();
        void newPreparation();

        void display();
};




#endif


//Uses could be its own class
//user would be able to search for herbs by ailment
