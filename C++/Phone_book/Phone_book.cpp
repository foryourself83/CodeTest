// Phone_book.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	sort(phone_book.begin(), phone_book.end(), greater<string>());

	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		if (phone_book[i].find(phone_book[i + 1]) == 0)
		{
			answer = false;
			break;
		}
	}

	return answer;
}

int main()
{
	//vector<string> phone_book = {"119","97674223","1195524421"};
	//vector<string> phone_book = { "123","456","789" };
	vector<string> phone_book = { "12","123","1235", "567", "88" };
	solution(phone_book);
}
