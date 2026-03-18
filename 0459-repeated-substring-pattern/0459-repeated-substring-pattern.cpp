class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.empty()) return false;

        // Trick: double the string and remove first & last char
        string t = s + s;
        t = t.substr(1, t.size() - 2);

        // If original string exists inside the modified doubled string, it's repeating
        return t.find(s) != string::npos;
    }
};