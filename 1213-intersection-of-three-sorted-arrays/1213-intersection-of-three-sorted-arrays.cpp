class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) 
    {
        vector<int> res;
        for(int i1 = 0, i2 = 0, i3 = 0; i1 < arr1.size() && i2 < arr2.size() && i3 < arr3.size();)
        {
            if(arr1[i1] == arr2[i2] && arr1[i1] == arr3[i3])
                res.push_back(arr1[i1]);
            int m = min({arr1[i1], arr2[i2], arr3[i3]});
            if(arr1[i1]==m) ++i1;
            if(arr2[i2]==m) ++i2;
            if(arr3[i3]==m) ++i3;
        }
        return res;
    }
};