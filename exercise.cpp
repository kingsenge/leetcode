class Solution1 {
public:
	//1025 Divisor Game
    bool divisorGame(int N) {
		vector<bool> dp(1001, false);

		dp[2]=true;
		if(N<=3)
			return dp[N];

		for(int i=4;i<=N;i++)
		{
			bool bWin = false;
			for(int k = 1;k<i/2;k++)
			{
				if(i%k == 0 && dp[i-k]==false)
				{
					bWin = true;
                    break;
				}
			}
			if(bWin){
                    dp[i] = true;
            }
		}

		return dp[N];
    }
};

class Solution2 {
public:
	//121 Best Time to Buy and Sell Stock
   int maxProfit(vector<int>& prices) {
	
		int size=  prices.size();
		if(size == 0)
            return 0;
            
        int min = prices[0];
		int max_profit = 0;
		int profit = 0;

		for(int i=1;i<size;i++)
		{
			if(prices[i]>min)
			{
				profit = prices[i]-min;
				if(profit > max_profit)
					max_profit= profit;
			}
			else
				min = prices[i];
		}
		
		return max_profit;
		
    }
};

class Solution3 {
public:
	//746 Min Cost Climbing stairs
    int minCostClimbingStairs(vector<int>& cost) {
    
		int size = cost.size();
		int first = cost[0];
		int second = cost[1];
		int tmp1,tmp2;
		for(int i = 2;i<size;i++)
		{
			tmp1 = first+cost[i];
			tmp2 = second + cost[i];

			first = second;
			if(tmp1< tmp2)
				second = tmp1;
			else
				second = tmp2;
		}

		if(first > second)
			return second;

		return first;
	}
};


class Solution4 {
public:
	//70 Climbing Stairs
    int climbStairs(int n) {
        int  step1 = 1;
		int  step2 = 2;

		if(n<3)
			if(n==1)
				return 1;
			else
				return 2;

		int temp = 0;
		for(int i = 3;i<=n;i++)
		{
			temp = step1+step2;
			step1 = step2;
			step2 = temp;
		}

		return step2;
    }
};

class Solution5 {
public:
	//53 Maximum Subarray
    int maxSubArray(vector<int>& nums) {
        int dp = 0;
		int size = nums.size();
		
		if(size == 0)
			return 0;

		int prior = nums[0];
		dp = prior;
		int temp = 0;

		for(int i = 1;i<size;i++)
		{
			temp = prior+nums[i];
			if(temp>nums[i])
				prior = temp;
			else
				prior = nums[i];

			if(prior>dp)
				dp=prior;
		}

		return dp;
    }
};

class Solution {
public:
    //198 House Robber
    int rob(vector<int>& nums) {
        int size = nums.size();
		if(size == 0)
			return 0;

		if(size <=3)
        {
			if(size==1)
				return nums[0];
			else if(size ==2)
			{
				if(nums[1]>nums[0])
					return nums[1];
				else
					return nums[0];
			}
            else
            {
                int temp = nums[0]+nums[2];
                if(temp>nums[1])
                    return temp;
                else
                    return nums[1];
            }
       
        }   

		int first = nums[0];
		int second = nums[1];
		int thrid = nums[2]+nums[0];
        int temp = 0;
        
		for(int i = 3;i<size;i++)
		{
		    if(nums[i]+first>nums[i]+second)
                temp =nums[i]+first;
            else
                temp = nums[i]+second;
            
            first = second;
            second = thrid;
            thrid = temp;
		}

		if(thrid>second)
			return thrid;
		else
			return second;
	}
};