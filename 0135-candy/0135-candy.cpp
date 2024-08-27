class Solution {
public:
    int candy(vector<int>& arr) {
        int i=1;
        int sum=1;
        int n=arr.size() - 1;
        while(i<=n){
            int peek=1;
            while(i<=n && arr[i]>arr[i-1]){
                peek = peek+1;
                sum += peek;
                i++;
            }
            int down = 0;
            while(i<=n && arr[i]<arr[i-1]){
                if(i==1 || arr[i-1]==arr[i-2])
                down = 1;

                down = down+1;
                sum+=down;
                i++;
            }
            while(i<=n && arr[i]==arr[i-1]){
                sum+=1;
                ++i;
            }
            if(down>=peek && peek!=1){
                sum+=down-peek+1;
            }
        }
        return sum;
    }
};