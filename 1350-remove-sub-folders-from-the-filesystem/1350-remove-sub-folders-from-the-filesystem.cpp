struct node {
public:
    unordered_map<string, node*> links;
    bool flag = false;

    bool containskey(string& s) {
        return links.find(s) != links.end();
    }

    void put(string& s, node* temp) {
        links[s] = temp;
    }

    node* get(string& s) {
        return links[s];
    }

    void setend() {
        flag = true;
    }

    bool isend() {
        return flag;
    }
};

class trie {
public:
    node* root;

    trie() {
        root = new node();
    }

    void insert(vector<string>& pathv) {
        node* temp = root;
        for (string& part : pathv) {
            if (!temp->containskey(part)) {
                temp->put(part, new node());
            }
            temp = temp->get(part);
            if (temp->isend()) return;
        }
        temp->setend();
    }

    void dfs(node* curr, vector<string>& ans, string path) {
        if (curr->isend()) {
            ans.push_back(path);
            return;
        }

        for (auto&i: curr->links) {
            string folder=i.first;
            node*child=i.second;
            dfs(child, ans, path + "/" + folder);
        }

    }

    void get_ans(vector<string>& ans) {
        dfs(root, ans, "");
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        trie t;
        for (string& f : folder) {
            vector<string> v;
            stringstream ss(f);
            string part;
            while (getline(ss, part, '/')) {
                if (!part.empty()){
                    v.push_back(part);
                }
            }
            t.insert(v);
        }

        vector<string> ans;
        t.get_ans(ans);
        return ans;
    }
};