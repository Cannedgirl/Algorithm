 vector<int> findDuplicates(vector<int>& nums) {
   vector<int >results;
	for (int i = 0; i < nums.size(); i++)
	{
        int j = i + 1;
		while (nums[i] != j&&nums[i]!=-1 )
		{
			int num = nums[i];
			if (nums[num-1] == -1)
				break;
			else if (nums[num - 1] == num)
			{
				results.push_back(num);
				nums[num - 1] = -1;
                break;
			}
			nums[i] = nums[num - 1];
			nums[num - 1] = num;
		}
	}
	return results;
    }
