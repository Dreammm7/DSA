class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> count;
        vector<string> result;

        for (string name : names) {
            if (count.find(name) != count.end()) {
                int k = count[name];
                string uniqueName = name + "(" + to_string(k) + ")";
                
                while (count.find(uniqueName) != count.end()) {
                    k++;
                    uniqueName = name + "(" + to_string(k) + ")";
                }
                
                count[name] = k + 1;
                count[uniqueName] = 1;
                result.push_back(uniqueName);
            } else {
                count[name] = 1;
                result.push_back(name);
            }
        }
        return result;
    }
};
