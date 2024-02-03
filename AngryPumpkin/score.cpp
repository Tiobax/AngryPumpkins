#include "score.h"

Score::Score(std::string name, int score_value)
{
    name_ = name;
    score_value_ = score_value;
}

void Score::set_name(std::string name)
{
    name_ = name;
}

void Score::set_score_value(int score_value)
{
    score_value_ = score_value;
}

std::string Score::get_name()
{
    return name_;
}

int Score::get_score_value()
{
    return score_value_;
}




