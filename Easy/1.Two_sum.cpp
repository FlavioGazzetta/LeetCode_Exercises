class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        std::vector<int> out;

        int j = 0;
        
        for(int i = 0; i < nums.size(); i++){

            for(j = 1; j < nums.size(); j++){

                if(nums[i] + nums[j] == target && i != j){

                    out.push_back(i);
                    out.push_back(j);
                    return out;

                }

            }

        }

        return out;

    }
};