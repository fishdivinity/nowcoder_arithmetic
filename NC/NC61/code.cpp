class Solution
{
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // write code here
        // 返回数组，记录两个下标
        vector<int> res;
        unordered_map<int, int> mymap;
        // 建立hash table array's value=> array's index
        for (int i = 0; i < numbers.size(); i++)
        {
            mymap[numbers[i]] = i;
        }
        // 第二次遍历，查询是否存在当前数的complement在hash table中
        for (int i = 0; i < numbers.size(); i++)
        {
            int complement = target - numbers[i];
            if (mymap.count(complement) != 0 && mymap.at(complement) != i)
            {
                res = {i + 1, mymap.at(complement) + 1};
                return res;
            }
        }
        throw invalid_argument("No two sum solution");
    }
};