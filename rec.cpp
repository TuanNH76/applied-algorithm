#include <bits/stdc++.h>
using namespace std;

int A[1000][1000];
int R,C;

int maxHist(int row[])
{
	stack<int> result;
	int top_val; // Top of stack
	int max_area = 0; // Initialize max area in current
	int area = 0; // Initialize area with current top
	int i = 0;
	while (i < C) {
	
		if (result.empty() || row[result.top()] <= row[i])
			result.push(i++);
		else {
			top_val = row[result.top()];
			result.pop();
			area = top_val * i;
			if (!result.empty())
				area = top_val * (i - result.top() - 1);
			max_area = max(area, max_area);
		}
	}

	while (!result.empty()) {
		top_val = row[result.top()];
		result.pop();
		area = top_val * i;
		if (!result.empty())
			area = top_val * (i - result.top() - 1);

		max_area = max(area, max_area);
	}
	return max_area;
}


int maxRectangle(int A[][1000]){
	int result = maxHist(A[0]);
	for (int i = 1; i < R; i++) {

		for (int j = 0; j < C; j++)

			// if A[i][j] is 1 then add A[i -1][j]
			if (A[i][j])
				A[i][j] += A[i - 1][j];
		result = max(result, maxHist(A[i]));
	}

	return result;
}

int main()
{
	
    cin >> R >> C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>A[i][j];
        }
    }
	cout << maxRectangle(A);

	return 0;
}
