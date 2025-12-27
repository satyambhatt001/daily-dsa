//1st approach

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;

        // convert all numbers to strings
        for (int x : nums) {
            s.push_back(to_string(x));
        }

        // custom sort
        sort(s.begin(), s.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // if the largest is "0", then all are zeros
        if (s[0] == "0") return "0";

        // build answer
        string result = "";
        for (string &x : s) result += x;

        return result;
    }
};


//2nd approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;

        // convert all numbers to strings
        for (int x : nums) {
            s.push_back(to_string(x));
        }

        // custom sort
        sort(s.begin(), s.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // if the largest is "0", then all are zeros
        if (s[0] == "0") return "0";

        // build answer
        string result = "";
        for (string &x : s) result += x;

        return result;
    }
};
