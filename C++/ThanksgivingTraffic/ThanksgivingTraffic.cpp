#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define Hour_to_sec 3600
#define Min_to_sec 60

struct LogTimeValueStruct
{
	int StartTime = 0;
	int ProcessingTime = 0;
};

void TransferTimeStringToInt(string time, LogTimeValueStruct& stTime)
{
	int hourPos = time.find(':', 0);
	int minPos = time.find(':', hourPos + 1);
	int secPos = time.find(' ', minPos + 1);

	int secValue = Hour_to_sec * stoi(time.substr(hourPos - 2, 2));
	secValue += Min_to_sec * stoi(time.substr(minPos - 2, 2));
	secValue += (int)(stod(time.substr(secPos - 6, 6)));

	stTime.StartTime = secValue;

	string tmp = time.substr(24);
	tmp.pop_back();

	stTime.ProcessingTime = stod(tmp) + 1;

	return;
}

int solution(vector <string> lines)
{
	int maxTraffic = 0; // 최대 트래픽
	int answer = 0;


	int TimeLength = lines.size();

	LogTimeValueStruct* LogTimes = new LogTimeValueStruct[TimeLength];

	int startTimeSec = 0;
	int endTimeSec = 0;

	for (int i = 0; i < TimeLength; i++)
	{
		TransferTimeStringToInt(lines[i], LogTimes[i]);

		if (startTimeSec == 0)
			startTimeSec = LogTimes[i].StartTime;

		startTimeSec = min(LogTimes[i].StartTime, startTimeSec);
		endTimeSec = max(LogTimes[i].StartTime + LogTimes[i].ProcessingTime, endTimeSec);
	}

	int tempTraffic = 0;
	for (int i = startTimeSec; i < endTimeSec; i++)
	{
		tempTraffic = 0;
		for (int j = 0; j < TimeLength; j++)
		{
			if (LogTimes[j].StartTime <= i && (LogTimes[j].StartTime + LogTimes[j].ProcessingTime) >= i)
			{
				tempTraffic++;
			}
		}

		maxTraffic = max(maxTraffic, tempTraffic);
	}

	if (LogTimes != NULL)
		delete[] LogTimes;

	answer = maxTraffic;
	return answer;
}

int main(void)
{
	/*vector <string> testCase = { "2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s" };
	vector <string> testCase = { "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" };*/
	vector <string> testCase = { "2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s",
					"2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s",
					"2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s",
					"2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s",
					"2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s" };

	cout << "최대 트래픽 : " << solution(testCase) << endl;

	return 0;
}