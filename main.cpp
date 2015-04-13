#include "MyList.h"

int main()
{
    MyList thing = MyList("hey there man");
    MyList thing2 = MyList(" part 2");
    thing.display();
    cout << endl;
    
    MyList thing3 = MyList("ey");
    
    cout << thing.find(thing3) << endl;
    
    thing.reverse();
    thing.display();
    
    return 0;
}