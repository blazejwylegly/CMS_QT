#include "TimeManager.h"
#include <iostream>
#include <time.h>
#include <ctime>

std::regex TimeManager::hourRegex("([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$");
std::regex TimeManager::dateRegex("(0[1-9]|\\d{2})[.](0[1-9]|\\d{2})[.]\\d{4}");

void TimeManager::printTime(const tm* time) {
	
	if (time != nullptr) {
		std::cout << prettyTimePrinting(time) << std::endl;
	}
	else {
		std::cout << "Time not initialized " << std::endl;
	}
}

void TimeManager::printDate(const tm* date) {
	if (date != nullptr) {
		std::cout << prettyPrinting(date);
	}
	else {
		std::cout << "Date not initialized!" << std::endl;
	}
}

void TimeManager::initTime(tm* time) {

	std::cout << "enter hour [hour]:[minutes]: ";
	std::string tmp = "";

	while (std::cin >> tmp && (std::regex_match(tmp, hourRegex) == false)) {
		std::cout << "Invalid time! Try again!" << std::endl;
	}

	std::smatch result;
	std::regex_search(tmp, result, hourRegex);

	std::string res = result[0];
	time->tm_hour = std::stoi(res.substr(0, res.find(':')));
	time->tm_min = std::stoi(res.substr(res.find(':') + 1, res.length()));
	
}

void TimeManager::initDate(tm* date) {
	
	time_t rawTime = -1;
	std::string tmp;
	std::cout << "Enter date [day.month.year]:" << std::endl;
	std::smatch result;
	while (rawTime == -1) {

		while (std::cin >> tmp && std::regex_match(tmp, dateRegex) == false)  {
			std::cout << "Invalid date! Try again!" << std::endl;
		}

		std::regex_search(tmp, result, dateRegex);
		std::string res = result[0];
		
		int values[3];
		for (int i = 0; i < 3; i++) {
			values[i] = std::stoi(res.substr(0, res.find(".")));
			res.erase(0, res.find(".") + 1);
		}

		date->tm_mday = values[0];
		date->tm_mon = values[1] - 1;
		date->tm_year = values[2] - 1900;

		time_t tempTime = mktime(date);

		if (tempTime == -1) {
			std::cout << "Invalid date!" << std::endl;
		}
		else {
			initTime(date);
			rawTime = mktime(date);
			if (rawTime == -1) {
				std::cout << "Invalid date and time! Try Again!" << std::endl;
			}
		}
	}

	system("cls");

	std::cout << "Registered date:" << std::endl;
	printDate(date);
	std::cout << "Accept and proceed? Y/N ?" << std::endl;

	char choice;
	std::cin >> choice;
	if (choice == 'N' || choice == 'n') {
		system("cls");
		initDate(date);
	}
}

void TimeManager::initStartDate(tm* startDate) {
	initDate(startDate);	
}

void TimeManager::initEndDate(tm* startDate, tm* endDate) {

	initDate(endDate);

	if (difftime(mktime(endDate), mktime(startDate)) <=0) {
		std::cout << "End date is before start date!" << std::endl;
		std::cout << "Start date:" << std::endl;
		printDate(startDate);
		std::cout << "End date:" << std::endl;
		printDate(endDate);
		std::cout<<"Initialize dates again to proceed!" << std::endl;
		initEndDate(startDate, endDate);
	}
}

void TimeManager::initStartTime(tm* startTime) {
	initTime(startTime);
}

void TimeManager::initEndTime(tm* startTime, tm* endTime) {

	initTime(endTime);

	if (difftime(mktime(endTime), mktime(startTime)) < 0) {
		std::cout << "End date is before start date!" << std::endl;
		std::cout << "Start date:" << std::endl;
		printDate(startTime);
		std::cout << "End date:" << std::endl;
		printDate(endTime);
		std::cout << "Initialize end date again to proceed!" << std::endl;
		initEndDate(startTime, endTime);
	}
}

double TimeManager::getDifference(tm* date1, tm* date2){
	return difftime(mktime(date2), mktime(date1));
}

std::string TimeManager::prettyTimePrinting(const tm* time) {
	
	if (time != nullptr) {
		std::string str;
		if (time->tm_hour < 10) {
			str.append("0");
		}
		str.append(std::to_string(time->tm_hour));
		str.append(":");
		if (time->tm_min < 10) {
			str.append("0");
		}
		str.append(std::to_string(time->tm_min));
		return str;
	}
	else {
		return "none";
	}
	
	
}

std::string TimeManager::prettyDatePrinting(const tm* date) {
	
	if (date != nullptr) {
		std::string str;
		if (date->tm_mday < 10) {
			str.append("0");
		}
		str.append(std::to_string(date->tm_mday));
		str.append(":");
		if (date->tm_mon < 10) {
			str.append("0");
		}
		str.append(std::to_string(date->tm_mon));
		str.append(":");
		str.append(std::to_string(date->tm_year + 1900));
		return str;
	}
	else {
		return "none";
	}
}

std::string TimeManager::prettyPrinting(const tm* date) {
	return prettyDatePrinting(date).append(", ").append(prettyTimePrinting(date));
}

std::unique_ptr<tm> TimeManager::parseTime(const std::string& obj) {
	std::string delimiter = ":";
	std::string txt = obj;
    int values[3];
	for (int i = 0; i < 3; i++) {
        values[i] = std::stoi(txt.substr(0, txt.find(delimiter)));
        txt.erase(0, txt.find(delimiter) + 1);
	}
	std::unique_ptr<tm> time = std::make_unique<tm>();
	time->tm_hour = values[0];
	time->tm_min = values[1];
	return time;
}
