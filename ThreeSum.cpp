//Source:https://leetcode-cn.com/problems/3sum/
//Author: J.X. Zhao
//Date:2020-9-7

/* 3sum:

	给你一个包含 n 个整数的数组 nums，判断 nums 中
	是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出
	所有满足条件且不重复的三元组。

    注意：答案中不可以包含重复的三元组

*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 思路：
//	   先排序，排序的时间复杂度为O(NlogN);
//	   双指针，固定最左的指针，移动中间和最右的指针；
//	   去重复，当sum[k]==sum[k-1]时，跳过不计。
//

vector<vector<int>> threeSum(vector<int>& nums) {
	//排序
	sort(nums.begin(), nums.end());
	//
	vector<vector<int>> res;
	for (int i = 0; i < nums.size(); i++) {
		//若数字重复，则跳过不计
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		//若不是，则判断双指针指向的数字与目标数字（-nums[i]）的大小，并进行合适的移动
		int k = nums.size() - 1;
		int target = -nums[i];
		for (int j = i + 1; j < nums.size(); ++j) {
			//若数字重复，则跳过不计
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;
			//否则判断大小
			while (j<k && nums[j] + nums[k]>target) {
				--k;
			}
			if (j == k)
				break;
			if (nums[j] + nums[k] == target) {
				res.push_back({ nums[i],nums[j],nums[k] });
			}
		}
	}
	return res;
}
void PrintMatrix(vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size(); i++)
	{
		printf("{");
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%3d", matrix[i][j]);
		}
		printf("}");
	}
	cout << endl;
}

int main() {
	int a[] = { -1,1,1,1,-1,-1,0,0,0 };
	vector<int> n(a, a + sizeof(a) / sizeof(int));
	vector<vector<int>> result = threeSum(n);
	PrintMatrix(result);
	return 0;
}
