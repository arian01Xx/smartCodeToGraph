#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void bellman(unordered_map<string, double>& best, vector<vector<string>>& pairs, vector<double>& rate){
        for(int relax=0; relax<pairs.size(); ++relax){
            for(int i=0; i<pairs.size(); ++i){
                best[pairs[i][1]]=max(best[pairs[i][1]], best[pairs[i][0]]*rate[i]);
                best[pairs[i][0]]=max(best[pairs[i][0]], best[pairs[i][1]]/rate[i]);
            }
        }
    }

    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, double> best;
        best[initialCurrency]=1;
        bellman(best, pairs1, rates1);
        bellman(best, pairs2, rates2);
        return best[initialCurrency];
    }
};

int main(){
    return 0;
}