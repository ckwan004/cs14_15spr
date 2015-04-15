//
//  main.cpp
//  thing
//
//  Created by Charles Kwang on 4/12/15.
//  Copyright (c) 2015 Charles Kwang. All rights reserved.
//

#include "MyList.h"

int main()
{
    MyList thing;
    thing.push_back('h');
    thing.push_back('e');
    thing.push_back('y');
    thing.push_back(' ');
    thing.push_back('t');
    thing.push_back('h');
    thing.push_back('e');
    thing.push_back('r');
    thing.push_back('e');
    thing.push_back(' ');
    
    MyList thing2 = MyList(" part 2");
    MyList thing4 = MyList(thing);
    thing.display();
    cout << endl;
    thing4.display();
    cout << endl;
    
    MyList thing3 = MyList("ey");
    
    cout << thing.find(thing3) << endl;
    
    thing.reverse();
    thing.display();
    cout << endl;
    
    thing3 = thing + thing2;
    thing3.display();
    cout << endl;
    
    return 0;
}

//fix reverse