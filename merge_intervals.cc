/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Runtime: 16 ms, faster than 93.93% of C++ online submissions for Merge Intervals.
Memory Usage: 12.2 MB, less than 100.00% of C++ online submissions for Merge Intervals.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        if (intervals.empty()) return intervals;

        // sort the vector according to start of the intervals in-place. O(nlog(n))
        sort(begin(intervals), end(intervals),
             [](const vector<int>& interval_1, const vector<int>& interval_2) -> bool
             {
                 return interval_1.at(0) < interval_2.at(0);
             });
        
        // merge the adjacent overlapping intervals
        // initialize the merged_intervals with the first interval fromt he sorted vector
        vector<vector<int>> merged_intervals {intervals.front()};  
        
        for (const auto& current_interval: intervals) {
            auto& last_merged_interval = merged_intervals.back();
            

            if (current_interval.at(0) <= last_merged_interval.at(1)) {
                // merge the intervals if they overlap
                last_merged_interval.at(1) = max(current_interval.at(1), last_merged_interval.at(1));
            } else {
                // add the current meeting since it doesn't overlap
                merged_intervals.push_back(current_interval);    
            }        
        }          
    return merged_intervals;         
    }
};