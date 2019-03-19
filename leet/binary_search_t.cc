#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
	if (nums.empty()) return -1;
	int low = 0, high = nums.size()-1;
	int mid = 0;
	while (low <= high) {
		mid = (high - low + 1) / 2 + low;
		if (target == nums[mid])
			break;
		if (nums[low] < nums[high]) {
			if (target < nums[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		} else {
			if (target >= nums[low]) {
				if (nums[mid] > nums[low] && nums[mid] < target) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			} else {
				if (target < nums[mid] && nums[mid] < nums[high]) {
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}
		}
	}
	if (nums[mid] != target)
	   mid = -1;
	return mid;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
	if (matrix.empty() || matrix[0].empty()) return false;
	int r_len = matrix.size(), c_len = matrix[0].size();
	int curpos_x = r_len - 1, curpos_y = 0;
	bool flag = false;
	while (true) {
		if (matrix[curpos_x][curpos_y] == target) {
			flag = true;
			break;
		} else if (matrix[curpos_x][curpos_y] < target) {
			curpos_y++;
		} else {
			curpos_x--;
		}
		if (curpos_x < 0 || curpos_y >= c_len)
			break;
	}
	return flag;
}

int main(int argc, char** argv)
{
	vector<vector<int>> matrix = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24},{18,21,23,26,30}};
	cout << searchMatrix(matrix, 5) << endl;
	cout << searchMatrix(matrix, 20) << endl;
	vector<vector<int>> matrix2 = {{-1}, {-1}};
	cout << searchMatrix(matrix2, 0) << endl;
	return 0;
}
