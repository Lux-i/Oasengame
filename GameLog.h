#include <string>
#pragma once

//basically an array wrapper
//providing necessary utility
class GameLog
{
public:
	GameLog();
	void addLog(const std::string&);
	void printLog();
private:
	std::string logarr[3];
	int entries;
	void moveArrElementsForward();
};

