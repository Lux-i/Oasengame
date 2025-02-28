#include "GameLog.h"
#include <string>
#include <iostream>

void GameLog::addLog(const std::string& message) {
	if (entries < 3) {
		logarr[entries] = message;
		entries++;
	}
	else {
		moveArrElementsForward();
		logarr[entries - 1] = message;
	}
}

void GameLog::printLog() {
	for (int i = 0; i < entries; ++i) {
		std::cout << logarr[i] << '\n';
	}
}

void GameLog::moveArrElementsForward() {
	for (int i = 0; i < entries - 1; ++i) {
		logarr[i] = logarr[i + 1];
	}
}

/**
 * doesn't really reset entries
 * just resets the counter back to 0
 */

void GameLog::resetEntries() {
	entries = 0;
}
