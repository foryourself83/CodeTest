#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define HourToMsec 3600000
#define MinToMsec 60000
#define SecToMsec 1000

struct LogTimeValueStruct
{
	int StartTime = 0;
	int EndTime = 0;
};

void TransferTimeStringToInt(string time, LogTimeValueStruct& stTime)
{
	int hourPos = time.find(':', 0);
	int minPos = time.find(':', hourPos + 1);
	int secPos = time.find(' ', minPos + 1);

	int msecValue = HourToMsec * stoi(time.substr(hourPos - 2, 2));
	msecValue += MinToMsec * stoi(time.substr(minPos - 2, 2));
	msecValue += SecToMsec * stod(time.substr(secPos - 6, 6));


	string tmp = time.substr(24);
	tmp.pop_back();

	stTime.EndTime = msecValue;
	stTime.StartTime = msecValue - (stod(tmp) * SecToMsec) + 1;

	return;
}

int solution(vector<string> lines)
{
	int maxTraffic = 0;
	int answer = 0;
	int TimeLength = lines.size();
	int startTimeSec = 0;
	int endTimeSec = 0;

	LogTimeValueStruct* LogTimes = new LogTimeValueStruct[TimeLength];

	for (int i = 0; i < TimeLength; i++)
	{
		TransferTimeStringToInt(lines[i], LogTimes[i]);
	}

	for (int i = 0; i < TimeLength; i++)
	{
		int end_time = LogTimes[i].EndTime + 1000;
		int count = 0;

		for (int j = i; j < TimeLength; j++)
		{
			if (LogTimes[j].StartTime < end_time)
				count++;
		}

		answer = max(answer, count);
	}

	if (LogTimes != NULL)
		delete[] LogTimes;

	return answer;
}

int main(void)
{
	//vector<string> testCase = { "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s" };
	//vector<string> testCase = { "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" };
	vector<string> testCase = { "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s",
					"2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s",
					"2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s",
					"2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s",
					"2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s" };

	cout << "Max Traffic : " << solution(testCase) << endl;

	return 0;
}