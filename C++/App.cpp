#include <iostream>
#include "DataStructures/StackArray.h"

using namespace std;

int main(int argc, char* argv[])
{
    Stack<int> stck;
    stck.push(10);
    stck.push(11);
    stck.push(12);
    stck.push(13);
    stck.push(14);
    stck.push(15);
    try{
        while(true){
            cout<<stck.top()<<endl;
            stck.pop();
        }
    } catch (StackEmptyException e) {
        cout<<e.getMsg()<<endl;
    }
    return 0;
}