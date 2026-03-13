#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s;

    int n;
    cin >> n;

    string cmd;
    for (int i = 0; i < n; i++){

        cin >> cmd;

        if (cmd == "push"){
            
            int x;
            cin >> x;

            s.push(x);
        }
        else if(cmd == "pop"){

            if (s.empty()){

                cout << -1 << endl;
            }
            else{

                cout << s.top() << endl;
                s.pop();
            }
        }
        else if(cmd == "size"){
            
            int num = s.size();
            cout << num << endl;
        }
        else if(cmd == "empty"){
            
            if (s.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(cmd == "top"){
            
            if (s.empty()){

                cout << -1 << endl;
            }
            else{

                cout << s.top() << endl;
            }
        }
    }
    
    

}

