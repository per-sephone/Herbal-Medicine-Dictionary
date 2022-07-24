#include "herb.h"
#include "DLL.h"

int main()
{
    cout << "Welcome to my herbal medicine dictionary!" << endl;
    
    Herb herb;
    DLL<Herb> list;

    //linked.load();
    herb.addNew();
    list.insert(herb);
    list.display();
    
}
