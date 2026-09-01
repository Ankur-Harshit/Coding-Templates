class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        int i=0;
        while(i<n-1){
            if(arr[i]<arr[i+1]){
                int s = i;
                while(i<n-1 && arr[i]<arr[i+1]) i++;
                if(i==n-1) return maxi;
                if(i<n-1 && arr[i]==arr[i+1]){
                    i++;
                    continue;
                }
                while(i<n-1 && arr[i]>arr[i+1])i++;
                if(i-s+1 >= 3)
                maxi = max(maxi,i-s+1);
            }
            else i++;
        }
        return maxi;
    }
};
