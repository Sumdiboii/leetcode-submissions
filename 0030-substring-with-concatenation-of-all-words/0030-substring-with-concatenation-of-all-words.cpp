class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        if (s.empty() || words.empty()) {
            return {};
        }

        int word_len = words[0].size();
        int word_count = words.size();
        int total_len = word_len * word_count;

        unordered_map<string, int> target;

        for (string& word : words) {
            target[word]++;
        }

        vector<int> ans;

        for (int offset = 0; offset < word_len; offset++) {

            int left = offset;
            int right = offset;

            unordered_map<string, int> window;
            int used = 0;

            while (right + word_len <= s.size()) {

                string word = s.substr(right, word_len);
                right += word_len;

                if (target.count(word)) {

                    window[word]++;
                    used++;

                    // Remove extra copies
                    while (window[word] > target[word]) {

                        string left_word = s.substr(left, word_len);

                        window[left_word]--;
                        left += word_len;
                        used--;
                    }

                    // Found valid substring
                    if (used == word_count) {

                        ans.push_back(left);

                        string left_word = s.substr(left, word_len);

                        window[left_word]--;
                        left += word_len;
                        used--;
                    }
                }
                else {
                    window.clear();
                    used = 0;
                    left = right;
                }
            }
        }

        return ans;
    }
};