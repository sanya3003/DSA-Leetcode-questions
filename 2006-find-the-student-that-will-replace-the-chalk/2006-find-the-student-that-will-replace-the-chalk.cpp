class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long totalChalkSum = 0;// total chalks required in one iteration
        for(int &chalkReq : chalk){
            totalChalkSum += chalkReq;
        }
    // number of full iteration possible = k/totalChalkSum

    int remainChalk = k%totalChalkSum;

    for(int i=0;i<n;i++){
        if(remainChalk < chalk[i]){
            return i;
        }
        remainChalk-=chalk[i];
    }
    return -1;

    }
};