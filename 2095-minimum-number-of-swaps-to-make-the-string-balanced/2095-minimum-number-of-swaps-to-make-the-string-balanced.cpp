class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(char &ch : s){
            if(ch == '['){
                st.push(ch);
            } else if(!st.empty()){
                st.pop();// balancing closing bracket with an open bracket in the stack
            }
        }
        // size of stack = number of open brackets 
        return (st.size()+1)/2;
    }
};