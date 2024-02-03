#pragma once
#include <string>

class Score
{
public:
	//constructors
	Score(std::string name, int score_value);

	//setters
	void set_name(std::string name);
	void set_score_value(int score_value);

	//getters
	std::string get_name();
	int get_score_value();

private:
	std::string name_;
	int score_value_;
};