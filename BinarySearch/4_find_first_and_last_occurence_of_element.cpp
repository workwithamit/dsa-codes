Link:https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

//Brute Force: T.c = O(n^2)

vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        //first brute force
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        vector<int> res(2,-1);
        
        if(ans.size()>=1){
            res[0]=ans[0];
        res[1]=ans[ans.size()-1];
        }
        return res;
    }


//Efficient approach
vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2,-1);
        //find first occurence of the target
        ans[0] = search(nums,target,true);
        if(ans[0]!=-1){
            //last occurence of the target
            ans[1]= search(nums,target,false);
        }
        return ans;
       
    }
    int search(vector<int> & nums, int target, bool findStartIndex){
        int ans = -1;
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start<=end){
            mid = start+(end-start)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{
                ans=mid;
                if(findStartIndex){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        return ans;
    }
