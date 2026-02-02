class Solution {
public:
    typedef long long ll;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        set<pair<int, int>> main, extra;

        ll minSum = LLONG_MAX;
        ll sum = 0LL;

        int n = nums.size();
        int i = 1;
        
        while(i-dist<1 && i<n){
            main.insert({nums[i], i});
            sum += nums[i];

            if(main.size()>k-1){
                auto largest = *main.rbegin();
                sum -= largest.first;

                extra.insert(largest);
                main.erase(largest);
            }
            i++;
        }

        while(i<n){
            main.insert({nums[i], i});
            sum += nums[i];

            if(main.size()>k-1){
                auto largest = *main.rbegin();
                sum -= largest.first;

                extra.insert(largest);
                main.erase(largest);
            }
            minSum = min(minSum, sum);

           auto remove = make_pair(nums[i-dist], i-dist);

           if(main.count(remove)){
                main.erase(remove);
                sum -= remove.first;

                if(!extra.empty()){
                    auto smallest = *extra.begin();
                    sum += smallest.first;

                    main.insert(smallest);
                    extra.erase(smallest);
                }
           }
           else{
                extra.erase(remove);
           }
           i++;
        }
        return nums[0] + minSum;
    }
};