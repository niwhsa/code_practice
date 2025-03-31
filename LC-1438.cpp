// 1438. Longest Continuous Subarray With Absolute Diff 
// Less Than or Equal to Limit
#include <vector>
#include <queue>

using namespace std;

class Solution {

public: 
  int longestSubarray(vector<int>& A, int limit) {
    deque<int> maxd; //strictly dec
    deque<int> mind; //strictly inc
    int maxResult = 0;
    int left = 0, right = 0;

    while (right < size(A)) {

        while (!empty(maxd) && A[maxd.back()] <= A[right]) {
            maxd.pop_back();
        }
        maxd.emplace_back(right);

        while(!empty(mind) && A[mind.back()] >= A[right]) {
            mind.pop_back();
        }
        mind.emplace_back(right);

        //if the abs diff (i.e the diff between the snallest and largest so far)
        // is greater than limit, adjust the left and continue
        if (A[maxd.front()] - A[mind.front()] > limit) {
            ++left;
            if (maxd.front() < left) maxd.pop_front();
            if (mind.front() < left) mind.pop_front();
            continue;
        } 
        
        //within the limit - new candidate
        maxResult = max(maxResult, right - left + 1);
        ++right;
    } 

    return maxResult;
  }
};

