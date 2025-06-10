class Solution{            //Class Solution for the C++ Code 
    public:                //visibility mode to allow public access of class contents

    vector<int> twoSum(vector<int> &nums, int target)  //array implementation
    {
        for(int i=0;i<=nums.size()-1;i++)   //first for loop to assign value of i to first array element 
        {
            for(int j=i+1;j<nums.size();j++)   //second for loop to assign value of j to decond array element; this loop will execute till its end point only then will the first loop increment its value 
            {
                if(target==nums[i]+nums[j])  // if the target required is acquired by the addition of any two array values during the looping stage...we will return those index values
                {
                    return  {i,j};  //return desired indices that add up to the target
                }
            }
        }
        return {};  //if no indices found that add upto the target
    }
};