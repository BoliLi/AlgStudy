#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        vector<int> intermediate;
        dfs(ret, num, intermediate);
        return ret;
    }
private:
    void dfs(vector<vector<int> > &result, vector<int> num, vector<int> &intermediate) {
        if(intermediate.size() == num.size()) {
            result.push_back(intermediate);
            for(int i = 0; i < intermediate.size(); i++)
                cout << intermediate[i] << " ";
            cout << endl;
            return;
        }
        for(int i = 0; i < num.size(); i++) {
            vector<int>::iterator pos = find(intermediate.begin(), intermediate.end(), num[i]);
            if(pos != intermediate.end())
                continue;
            intermediate.push_back(num[i]);
            dfs(result, num, intermediate);
            intermediate.pop_back();
        }
    }
};

int main()
{
    Solution a;
    vector<vector<int> > rt;
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(2);
    numbers.push_back(8);
    //numbers.push_back(15);
    rt = a.permute(numbers);
    cout << "Hello world!" << endl;
    return 0;
}
