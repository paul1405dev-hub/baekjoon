#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s;
    int num;
    cin >> num;

    int x;
    for (int i = 0; i < num; i++){

        cin >> x;
        if (x == 0){

            s.pop();
        }
        else{

            s.push(x);
        }
    }

    int sum = 0;
    while (!s.empty()){

        sum += s.top();
        s.pop();
    }
    
    cout << sum << endl;
}