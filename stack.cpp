#include <bits/stdc++.h>
using namespace std;

stack<int> st;   // STL stack

void push(int x) {
    st.push(x);
}

void pop() {
    if (!st.empty())
        st.pop();
    else
        cout << "Stack empty\n";
}

int peek() {
    if (!st.empty())
        return st.top();
    return -1;
}

int size() {
    return st.size();
}

bool empty() {
    return st.empty();
}

int main() {

    push(10);
    push(20);
    push(30);

    cout << "Top: " << peek() << endl;

    pop();

    cout << "Top: " << peek() << endl;

    cout << "Size: " << size() << endl;

    if (empty())
        cout << "Empty\n";
    else
        cout << "Not Empty\n";

    return 0;
}

//2nd approach
#include <bits/stdc++.h>
using namespace std;

stack<int> st;   // STL stack

void push(int x) {
    st.push(x);
}

void pop() {
    if (!st.empty())
        st.pop();
    else
        cout << "Stack empty\n";
}

int peek() {
    if (!st.empty())
        return st.top();
    return -1;
}

int size() {
    return st.size();
}

bool empty() {
    return st.empty();
}

int main() {

    push(10);
    push(20);
    push(30);

    cout << "Top: " << peek() << endl;

    pop();

    cout << "Top: " << peek() << endl;

    cout << "Size: " << size() << endl;

    if (empty())
        cout << "Empty\n";
    else
        cout << "Not Empty\n";

    return 0;
}
