// PickTwoAndAdd.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> numbers)
{
	vector<int> answer;

	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			answer.push_back(numbers[i] + numbers[j]);
		}
	}

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return answer;
}

int main(void)
{
	//vector<int> testCase = {2,1,3,4,1};
	vector<int> testCase = { 5,0,2,7 };

	solution(testCase);

	return 0;
}