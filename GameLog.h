#include <string>
#pragma once

//basically an array wrapper
//providing necessary utility
class GameLog
{
public:
	GameLog() = default;
	void addLog(const std::string&);
	void printLog();
	void resetEntries();
private:
	std::string logarr[3];
	int entries = 0;
	void moveArrElementsForward();
};

