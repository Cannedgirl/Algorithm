 vector<int> findDuplicates(vector<int>& nums) {
        vector<int>results;
        int i = 0;
        while(i<nums.size())
        {
            int val = nums[i];
            if(val==(i+1)||val==-1)
            {
                i++;
                continue;
            }
            else
            {
                if(nums[val-1]==val)
                {
                    results.push_back(val);
                    nums[val-1]=-1;
                    i++;
                    
                }
                else{
                    int temp = nums[val-1];
                    nums[val-1]=val;
                    nums[i]=temp;
                }
            }
        }
        return results;
 }
