class Solution {
public:
    bool isValid(string s) {

        if (s.length()%2 != 0) {
            return false;
        }

        unordered_map<char, char> parenthes_map = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        stack<int> s_stack;
        for (int i = 0; i < s.length(); i++) {
            if (parenthes_map.count(s[i]) == 0) {
                s_stack.push(s[i]);
            }
            else {
                // 对于return false的情况，一般都是反向思路，而不是做为else的分支
                if (s_stack.empty() || parenthes_map[s[i]] != s_stack.top()){
                    return false;
                }
                s_stack.pop();
            }
        }

        return s_stack.empty();
    }
};