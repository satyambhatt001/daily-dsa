class Solution {
	public:
	bool isBitSet(int n) {
		// code here
		string s = bitset<32>(n).to_string();
		if (n == 0)
			return false;
		s.erase(0, s.find('1'));
		for (int i = 0; i<s.size(); i++)
		
			{
			if (s[i] == '0') {
				return false;
			}
		}
		return true;
		
	}
};
