#include "herb.h"

//constructor
Herb::Herb() : name("none"), dosage(0), uses("none"), precautions("none"),
    preparations("none")
{}

//copy constructor
Herb::Herb(const Herb& toCopy) : name(toCopy.name), dosage(toCopy.dosage),
    uses(toCopy.uses),precautions(toCopy.precautions), preparations(toCopy.preparations)
{}

//destructor
Herb::~Herb()
{}

//operator overloading
Herb& Herb::operator=(const Herb& h)
{
    if(this == &h)
        return *this;

    name = h.name;
    dosage = h.dosage;
    uses = h.uses;
    precautions = h.precautions;
    preparations = h.preparations;
    return *this;
}

//overloaded by name
bool Herb::operator>(const Herb& h) const
{
    if(name > h.name)
        return true;
    else
        return false;
}

bool Herb::operator>=(const Herb& h) const
{
    if(name >= h.name)
        return true;
    else
        return false;
}

bool Herb::operator<(const Herb& h) const
{
    if(name < h.name)
        return true;
    else
        return false;
}

bool Herb::operator<=(const Herb& h) const
{
    if(name <= h.name)
        return true;
    else
        return false;
}

bool Herb::operator==(const Herb& h) const
{
    if(name == h.name)
        return true;
    else
        return false;
}

bool Herb::operator!=(const Herb& h) const
{
    if(name != h.name)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& out, const Herb& herb)
{
    cout << "Herb name: " << herb.name << endl;
    cout << "Dosage: " << herb.dosage << " milligrams" << endl;
    cout << "Uses: " << herb.uses << endl;
    cout << "Precautions/Contraindications: " << herb.precautions << endl;
    cout << "Preparations: " << herb.preparations << endl;
    return out;
}

void Herb::addNew(const string n, const int d, const string u, 
        const string p, const string prep)
{
    name = n;
    dosage = d;
    uses = u;
    precautions = p;
    preparations = prep;
}

void Herb::addNew()
{
    newName();
    newDosage();
    newUse();
    newPrecaution();
    newPreparation();
}

void Herb::newName()
{
    string input;
    cout << "Enter herb name: ";
    getline(cin, input);

    name = input;
}

void Herb::newDosage()
{
    int input;
    cout << "Enter dosage in milligrams: ";
    cin >> input;
    getchar();

    //exception handling - is input a number?

    dosage = input;

}

void Herb::newUse()
{
    string input;

    cout<< "Enter uses for this herb, separated by commas: ";
    getline(cin, input);
    uses = input;
}

void Herb::newPrecaution()
{
    string input;

    cout << "Enter precautions/contraindications for this herb, separated by commas: ";
    getline(cin, input);
    precautions = input;
}

void Herb::newPreparation()
{
    string input;
    cout << "Enter preparations for this herb, separated by commas: ";
    getline(cin, input);
    preparations = input;
}

void Herb::display()
{
    cout << "Herb name: " << name << endl;
    cout << "Dosage: " << dosage << " milligrams" << endl;
    cout << "Uses: " << uses << endl;
    cout << "Precautions/Contraindications: " << precautions << endl;
    cout << "Preparations: " << preparations << endl;
}
