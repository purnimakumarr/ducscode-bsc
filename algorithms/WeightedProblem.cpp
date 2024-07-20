#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

class weightedInterval {
public:
	int start, finish, weight;

	bool operator < (const weightedInterval& x) const {
		if (finish != x.finish)
			return finish < x.finish;
		return start < x.start;
	}
}*intervals;

int binarySearch(int first, int last, int val) {
	int mid;
	while (first < last) {
		mid = first + (last - first + 1) / 2;
		if (intervals[mid].finish <= val)
			first = mid;
		else
			last = mid - 1;
	}
	if (intervals[first].finish > val)
		return 0;
	return first;
}
int greatestNonOverlappingInterval(int j) {
	return binarySearch(0, j-1, intervals[j].start);
}

void display() {
	for (int i = 0; i <= 50; i++)
		cout << "=";
	cout << endl;
}
int main() {
	int n, *p, *dp;

	display();
	cout << "\tWEIGHTED INTERVAL PROBLEM\n";
	display();
	cout << "Enter number of intervals: ";
	cin >> n;

	intervals = new weightedInterval[n+1];

	intervals[0].start = intervals[0].finish = intervals[0].weight = 0;

	for (int i = 1; i <= n; i++)
	{
		cout << "\nFor interval " << i << ":-\n";
		cout << "Start time: ";
		cin >> intervals[i].start;
		cout << "Finish time: ";
		cin >> intervals[i].finish;
		cout << "Weight: ";
		cin >> intervals[i].weight;
	}

	//sorting intervals in increasing order of their finish time
	sort(intervals + 1, intervals + n + 1);

	p = new int[n+1];
	dp = new int[n+1];

	dp[0] = p[0] = 0;
	//determine the value of optimum solution
	for (int i = 1; i <= n; i++) {
		p[i] = greatestNonOverlappingInterval(i);
		dp[i] = max(intervals[i].weight + dp[p[i]], dp[i - 1]);
	}
	//constructing optimum solutiond
	stack<int> opt_sol;
	for (int i = n; i > 0; ) {
		if (intervals[i].weight + dp[p[i]] >= dp[i - 1]) {
			opt_sol.push(i);
			i = p[i];
		}
		else
			i--;
	}

	cout << "\n\nThe value of optimum solution: " << dp[n];
	cout << "\nThe optimum solution is:-\n";
	while (!opt_sol.empty()) {
		int i = opt_sol.top();
		opt_sol.pop();
		cout << "Interval " << i << "\tStart time:" << intervals[i].start << "\tFinish time: " << intervals[i].finish << "\tWeight: " << intervals[i].weight << "\n";
	}
	return 0;
}