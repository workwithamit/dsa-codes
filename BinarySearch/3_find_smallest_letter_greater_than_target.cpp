Link:https://leetcode.com/problems/find-smallest-letter-greater-than-target/
char nextGreatestLetter(vector<char>& arr, char target) {
        int n = arr.size();
        int l=0,r=n-1;
        int mid;
        while(l<=r){
            mid = l+(r-l)/2;
            
            if(arr[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        //the answer is basically the start index 
        //but if we don't find any desired answer then we are doing 
        //what is mentioned in the question
        //if we don't find the target character then start will point to the n
        //so n%n = 0 that is what we have to return according to question
        return arr[l%n];
    }
