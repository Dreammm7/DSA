class Solution {
public:
    vector<string> fizzBuzz(int n) {
       vector<string> ans;
        for(int i = 1; i <= n; i++){
            string currstr = "";

            if (i % 3 == 0) currstr += "Fizz";
            if (i % 5 == 0) currstr += "Buzz";
    
            if (currstr == "") {
                currstr = to_string(i);
            }
            ans.push_back(currstr);
        }
        return ans;
    }
};