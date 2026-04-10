#include <iostream>;
#include <vector>;
using namespace std;
class Solution {
public:
	int getMinDistance(vector<int> nums) {
		int res = INT_MAX;
		for (int id = 2;id < nums.size();id++) {
			int dis = 2*(nums[id] - nums[id - 2]);
			if (dis<res) {
				res=dis;
			}
		}
		return res;
	}

    int minimumDistance(vector<int>& nums) {
		int res = INT_MAX;
		vector<int> row;
		vector<vector<int>> matrix(nums.size()+1, row);
		//vector<int> count(nums.size()+1, 0);
		for (int i = 0;i < nums.size();i++) {
			matrix[nums[i]].push_back(i);
			//count[nums[i]]++;
		}
		for (int i = 0;i < nums.size();i++)
		{
			
				int dis = getMinDistance(matrix[nums[i]]);
				if (dis < res) {
					res = dis;
				}
			

		}		
		return res == INT_MAX ? -1 : res;
    }
};