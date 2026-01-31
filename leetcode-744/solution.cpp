class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        
        int n = letters.size();
        int low = 0, high = n-1;

        while(low<=high){
            int mid = low + (high - low)/2;
            char currChar = letters[mid];

            if(currChar>target){
                ans = currChar;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};