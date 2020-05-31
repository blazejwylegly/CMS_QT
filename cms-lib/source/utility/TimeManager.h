#pragma once
#include <regex>
#include <memory>
class TimeManager
{
private:
	static std::regex hourRegex;
	static std::regex dateRegex;
	static void initDate(tm* date);
	static void initTime(tm* time);

public:
	static double getDifference(tm* date1, tm* date2);
	static void initStartDate(tm* startDate);
	static void initEndDate(tm* startDate, tm* endDate);
	static void initStartTime(tm* startTime);
	static void initEndTime(tm* startTime, tm* endTime);
	static void printDate(const tm* date);
	static void printTime(const tm* time);
	static std::string prettyDatePrinting(const tm* date);
	static std::string prettyTimePrinting(const tm* time);
	static std::string prettyPrinting(const tm* date);
	static std::unique_ptr<tm> parseTime(const std::string& obj);
};

