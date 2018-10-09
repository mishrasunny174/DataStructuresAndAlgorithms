#include <iostream>
#include <string>
#include "DataStructures/HashMap.h"

using namespace std;

int main(int argc, char *argv[])
{
    HashMap<string, int> map;
    map.insert("Sunny", 10);
    map.insert("Mishra", 20);
    map.insert("asdfgh", 40);
    try
    {
        int get = map.get("Sunny");
        cout << get << endl;
        map.remove("MISHRA");
    }
    catch (ElementNotFoundException e)
    {
        cout << e.what() << endl;
    }
    map.traverse();
    return 0;
}