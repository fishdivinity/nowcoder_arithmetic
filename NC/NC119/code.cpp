class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> output;
        if( k > input.size())
            return output;
        sort(input.begin(),input.end())
            ;
        return vector<int>({input.begin(),input.begin()+k});
        
    }
};

//解决方法一：使用vector容器
//如果k>vector::size，返回空的容器
//sort排序（默认升序）
//返回
