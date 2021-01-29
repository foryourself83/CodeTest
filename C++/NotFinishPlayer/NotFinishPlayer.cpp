// NotFinishPlayer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> notFinishPlayer;

	for (auto player : completion)
	{
		notFinishPlayer[player] += 1;
	}

	for (auto player : participant)
	{
		notFinishPlayer[player] -= 1;

		if (notFinishPlayer[player] < 0)
		{
			answer = player;
			break;
		}
	}

	return answer;
}

int main()
{
	vector<string> participants = { "leo", "kiki", "eden" };
	vector<string> completions = { "kiki", "eden" };

	string player = solution(participants, completions);

    std::cout << player << "\n";
}

