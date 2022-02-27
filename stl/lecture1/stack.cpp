#include <iostream>
#include <stack>
//https://www.cplusplus.com/reference/stack/stack/
using namespace std;
int main() {
    stack<int> stack;

    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
     
        stack.pop();
    stack.pop();
 
    while (!stack.empty()) {
        cout << ' ' << stack.top();  //don't check top if stack empty

        stack.pop();
    }
}