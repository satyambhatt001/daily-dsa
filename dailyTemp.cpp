#include <vector>
#include <stack>
using namespace std;

// Function that, for each temperature, returns how many days until a warmer temperature
vector<int> Temp(vector<int> &temp) {
    int n = temp.size();          // number of elements in input
    vector<int> ans(n, 0);        // output vector initialized with 0s (n elements)
    stack<int> st;                // stack to store indices of temperatures

    // Traverse all temperatures
    for (int i = 0; i < n; i++) {

        // While the stack is not empty AND
        // current temperature > temperature at index on top of the stack
        // it means we found a *warmer* temperature for that earlier day
        while (!st.empty() && temp[i] > temp[st.top()]) {

            int prevIdx = st.top();   // get index of that previous day
            st.pop();                 // remove it from stack because we found its answer

            // difference between indices gives number of days waited
            ans[prevIdx] = i - prevIdx;
        }

        // push current day's index into the stack
        // (we haven't yet found a warmer day for it)
        st.push(i);
    }

    // return result vector
    return ans;
}
