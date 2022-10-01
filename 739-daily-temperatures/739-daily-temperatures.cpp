class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
  int n = temp.size();
	stack<int> s;
	vector<int> ans(n, 0);
	for (int i = 0; i < n; ++i) {
		while (!s.empty() and temp[s.top()] < temp[i]) {
			int j = s.top(); s.pop();
			ans[j] = i - j;
		}
		s.push(i);
	}
	return ans; 
    }
};
