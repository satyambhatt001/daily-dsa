vector<int> removeDuplicates(vector<int> &nums)
{
    unordered_map<int, int> freq;
    vector<int> result;

    for (int num : nums)
    {
        if (freq[num] == 0)
        {
            result.push_back(num);
        }
        freq[num]++;
    }

    return result;
}
