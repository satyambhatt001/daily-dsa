class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
            vector<string> res;
       for (int x : arr)
        res.push_back(to_string(x));

    
    sort(res.begin(), res.end(), [](string a, string b) {
        return a + b > b + a;
    });

    
    if (res[0] == "0")
        return "0";

   
    string ans = "";
    for (string s : res)
        ans += s;

    return ans;
    }
};
