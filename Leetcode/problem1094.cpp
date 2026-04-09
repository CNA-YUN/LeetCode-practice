#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
		int len = trips.size();
		vector<int> diff(1001, 0);
		for (int i = 0; i < len; ++i) {
			int numPassengers = trips[i][0];
			int from = trips[i][1];
			int to = trips[i][2];
			diff[from] += numPassengers;
			diff[to] -= numPassengers;
		}
		int currentPassengers = 0;
		for (int i = 0; i <= 1000; ++i) {
			currentPassengers += diff[i];
			if (currentPassengers > capacity) {
				return false;
			}
		}
		return true;
    }
};