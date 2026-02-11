class Solution {
public:
    int n;
    void propagate(int i, int l, int r, vector<int>& segMin, vector<int>& segMax, vector<int>& lazy){
        if(lazy[i]!=0){
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];

            if(l!=r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }

    void updateRange(int qLeft, int qRight, int val, int i, int l, int r, vector<int>& segMin, vector<int>& segMax, vector<int>& lazy){
        propagate(i, l, r, segMin, segMax, lazy);

        if(l>qRight || r<qLeft){
            return;
        }
        
        if(l>=qLeft && r<=qRight){
            lazy[i] += val;
            propagate(i, l, r, segMin, segMax, lazy);
            return;
        }

        int mid = l + (r - l)/2;

        updateRange(qLeft, qRight, val, 2*i+1, l, mid, segMin, segMax, lazy);
        updateRange(qLeft, qRight, val, 2*i+2, mid+1, r, segMin, segMax, lazy);

        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
    }

    int findLeftMostZeroIndex(int i, int l, int r, vector<int>& segMin, vector<int>& segMax, vector<int>& lazy){
        propagate(i, l, r, segMin, segMax, lazy);

        if(segMin[i]>0 || segMax[i]<0){
            return -1;
        }
        if(l==r) return l;

        int mid = l + (r - l)/2;

        int leftMostIdx = findLeftMostZeroIndex(2*i+1, l, mid, segMin, segMax, lazy);
        if(leftMostIdx!=-1) return leftMostIdx;

        return findLeftMostZeroIndex(2*i+2, mid+1, r, segMin, segMax, lazy);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        vector<int> segMin(4*n), segMax(4*n), lazy(4*n);
        unordered_map<int, int> seen;

        int maxLen = 0;
        for(int i=0; i<n; i++){
            int val = nums[i]%2==0 ? 1 : -1;

            int prev = -1;
            if(seen.count(nums[i])){
                prev = seen[nums[i]];
            }

            if(prev!=-1){
                updateRange(0, prev, -val, 0, 0, n-1, segMin, segMax, lazy);
            }

            updateRange(0, i, val, 0, 0, n-1, segMin, segMax, lazy);

            int leftMostIdx = findLeftMostZeroIndex(0, 0, n-1, segMin, segMax, lazy);
            if(leftMostIdx!=-1){
                maxLen = max(maxLen, i-leftMostIdx+1);
            }

            seen[nums[i]] = i;
        }
        return maxLen;
    }
};