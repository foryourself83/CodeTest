// Camouflage.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<string, int> spyClothes;
	
	for (auto cloth : clothes)
	{
		spyClothes[cloth[1]]++;
	}
	
	for (auto item : spyClothes)
	{
		answer *= item.second + 1;
	}

	return answer - 1;
}

int main()
{
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};

	solution(clothes);

	exit(0);
}
