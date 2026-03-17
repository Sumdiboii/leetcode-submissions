class Solution {
public:
    int compress(vector<char>& chars) {
        map<char, int> mp;
        int ans = 0;

        for (int i = 0; i < chars.size(); i++) {
            mp[chars[i]]++;

            // check if next char is different OR end reached
            if (i == chars.size() - 1 || chars[i] != chars[i + 1]) {
                char letter = chars[i];
                int count = mp[letter];

                // write character
                chars[ans++] = letter;

                // write count if > 1
                if (count > 1) {
                    for (char c : to_string(count)) {
                        chars[ans++] = c;
                    }
                }

                mp.clear(); // reset for next group
            }
        }

        return ans;
    }
};