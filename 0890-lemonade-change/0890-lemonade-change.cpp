class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        for (int bill : bills) {
            if (bill == 5) {                    // Case-01: 05
                fives++;
            } else if (bill == 10) {            // Case-02: 10
                if (fives == 0) {
                    return false;
                }
                fives--;
                tens++;
            } else {
                if (tens > 0 && fives > 0) {    // Case-03: 20
                    tens--;
                    fives--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;

    }
};