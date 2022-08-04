class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //heap
        //no extra space, then binary search and rank of element
         priority_queue<int>maxHeap;
    for(auto & row : matrix)
    {
        for(int & col : row)
        {
            maxHeap.push(col);
            if(maxHeap.size()>k)
            {
                maxHeap.pop();
            }
        }
    }
    return maxHeap.top();
    }
};