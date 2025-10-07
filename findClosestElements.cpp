class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-k;
        vector<int> ans;
        while(left<right)
        {
            int mid = left + (right-left)/2;
            if(x-arr[mid] <= arr[mid+k] - x)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        for(int i=left;i<left+k;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
