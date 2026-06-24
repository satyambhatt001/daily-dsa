class Solution {
public:
    int calculate(string s) {
        long long ans = 0;
        long long interim = 0;
        long long num = 0;

        int i = 0;
        char op = '+';

        while(i < s.size()) {
            if(isdigit(s[i])) {
                num = 0;

                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                if(op == '+' || op == '-') {
                    ans += interim;
                    interim = (op == '-') ? -num : num;
                }
                else if(op == '*') {
                    interim *= num;
                }
                else if(op == '/') {
                    interim /= num;
                }

                continue;
            }
            else if(s[i] != ' ') {
                op = s[i];
            }

            i++;
        }

        ans += interim;

        return (int)ans;
    }
};
