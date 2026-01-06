class TimeMap {
public:

    // We need to store for each KEY:
    //   -> many (timestamp, value) pairs
    //
    // unordered_map:
    //   key   -> string (like "apple", "love")
    //   value -> vector of pairs (timestamp, value)
    //
    // Example inside map:
    //   "love" -> [ (1,"high"), (5,"low") ]
    //
    unordered_map<string, vector<pair<int, string>>> mp;


    // Constructor (empty — nothing special to initialize)
    TimeMap() {}


    // -------------------------------
    // SET FUNCTION
    // -------------------------------
    //
    // Stores the value for a key at a given timestamp
    //
    // Important constraint: timestamps are ALWAYS increasing
    // for the same key. So new entries always come at the end.
    //
    void set(string key, string value, int timestamp) {

        // We push this pair into the vector for this key.
        // If key does NOT exist, map auto-creates it.
        mp[key].push_back({timestamp, value});
    }


    // -------------------------------
    // GET FUNCTION
    // -------------------------------
    //
    // We need to return:
    //   value with timestamp <= given timestamp
    //   but closest (maximum possible)
    //
    // If nothing qualifies, return "".
    //
    string get(string key, int timestamp) {

        // If the key doesn't exist at all, answer is empty string
        if (mp.find(key) == mp.end())
            return "";

        // Reference to the vector of (timestamp, value) pairs
        // Example: [(1,"high"), (5,"low")]
        auto &arr = mp[key];

        int left = 0;
        int right = arr.size() - 1;

        // Stores best possible answer found so far
        // initially nothing
        string ans = "";


        // -------------------------------
        // BINARY SEARCH
        // -------------------------------
        //
        // We search for largest timestamp <= given timestamp
        //
        while (left <= right) {

            // Middle index (avoid overflow formula)
            int mid = left + (right - left) / 2;

            // arr[mid].first = timestamp stored at mid
            //
            // Case 1:
            // if stored_time <= given timestamp,
            // then this is a VALID candidate
            //
            if (arr[mid].first <= timestamp) {

                // store value as possible answer
                ans = arr[mid].second;

                // But maybe there is an EVEN CLOSER timestamp
                // on the RIGHT side (higher timestamp but still <= given)
                left = mid + 1;
            }

            // Case 2:
            // stored_time > given timestamp
            // this timestamp is too big, so move LEFT
            else {
                right = mid - 1;
            }
        }

        // Whatever we found last remains in ans
        // If nothing valid was found, ans is still ""
        return ans;
    }
};
