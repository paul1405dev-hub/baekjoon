#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;

    int num;
    cin >> num;

    string cmd;

    for (int i = 0; i < num; i++){
        cin >> cmd;

        if (cmd == "push"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if (cmd == "pop"){
            if (q.empty()) cout << -1 << endl;
            else{
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (cmd == "size"){
            cout << q.size() << endl;
        }
        else if (cmd == "empty"){
            cout << q.empty() << endl;
        }
        else if (cmd == "front"){
            if (q.empty()) cout << -1 << endl;
            else cout << q.front() << endl;
        }
        else if (cmd == "back"){
            if (q.empty()) cout << -1 << endl;
            else cout << q.back() << endl;
        }
    }
}