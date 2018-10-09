#include <iostream>
#include <string>
#include "DataStructures/HashMap.h"

using namespace std;

int main(int argc, char *argv[])
{
    HashMap<string,int> map;
    map.insert("sunny",10);
    map.traverse();
    return 0;
}