class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

    vector<string> s;
    for (int i = 0; i < n; i++) {
        s.push_back(bitset<32>(arr[i]).to_string());
    }

    vector<pair<int,int>> temp;
    for (int i = 0; i < n; i++) {
        int ones = 0;

        for (char c : s[i]) {
            if (c == '1') ones++;
        }

        temp.push_back({ones, arr[i]});
    }

    
    sort(temp.begin(), temp.end());

    vector<int> num;
    for (int i = 0; i < n; i++) {
        num.push_back(temp[i].second);
    }
    return num;
    }
};


//2nd 

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        vector<pair<int,int>> temp;

        for (int x : arr) {
            int ones = __builtin_popcount(x);  // count set bits
            temp.push_back({ones, x});
        }

        sort(temp.begin(), temp.end());

        vector<int> result;
        for (auto &p : temp) {
            result.push_back(p.second);
        }

        return result;
    }
};

//3rd

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        vector<pair<int,int>> temp;

        for (int x : arr) {
            int ones = bitset<32>(x).count();  // STL way
            temp.push_back({ones, x});
        }

        sort(temp.begin(), temp.end());

        vector<int> result;
        for (auto &p : temp) {
            result.push_back(p.second);
        }

        return result;
    }
};
