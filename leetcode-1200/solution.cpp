class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));

        int diff = INT_MAX;
        int n = arr.size();

        for(int i=0; i<n-1; i++){
            int currDiff = abs(arr[i]-arr[i+1]);
            diff = min(diff, currDiff);
        }

        vector<vector<int>> result;
        for(int i=0; i<n-1; i++){
            int currDiff = abs(arr[i]-arr[i+1]);

            if(currDiff==diff){
                result.push_back({arr[i], arr[i+1]});
            }
        }
        return result;
    }
};