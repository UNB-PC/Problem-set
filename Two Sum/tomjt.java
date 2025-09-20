class Solution 
{
    public int[] twoSum(int[] nums, int target) 
    {
        int cur1;
        int cur2;
        int[] answer = new int[2];
        
        for (int i = 0; i < nums.length; i++)
        {
            cur1 = nums[i];
            for (int j = 0; j < nums.length; j++)
            {
                cur2 = nums[j];
                if (((cur1+cur2) == target) && i!=j)
                {
                    answer[0] = i;
                    answer[1] = j;
                }

            }
        }
        return answer;
    }




}
