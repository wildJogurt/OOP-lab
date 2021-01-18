#include "medley.h"
#include "iostream"

Medley::Medley():
    Audio(),
    _moodConditionEnd(0),
    _moodIntensityEnd(0)
{

}

Medley::Medley(std::string name, float moodCondition, float moodIntensity, float moodConditionEnd, float moodIntensityEnd):
    Audio(name, moodCondition, moodIntensity),
    _moodConditionEnd(moodConditionEnd > 0 && moodConditionEnd <= 10 ? moodConditionEnd : 0),
    _moodIntensityEnd(moodIntensityEnd > 0 && moodIntensityEnd <= 10 ? moodIntensityEnd : 0)
{

}

Medley::Medley(Medley &med):
    Audio(med),
    _moodConditionEnd(med._moodConditionEnd),
    _moodIntensityEnd(med._moodIntensityEnd)
{

}

Medley::~Medley()
{

}

void Medley::setMoodConditionEnd(float moodConditionEnd)
{
    if (moodConditionEnd >= 0 && moodConditionEnd <= 10)
    {
        _moodConditionEnd = moodConditionEnd;
    }
}

void Medley::setMoodIntensityEnd(float moodIntensityEnd)
{
    if (moodIntensityEnd >= 0 && moodIntensityEnd <= 10)
    {
        _moodIntensityEnd = moodIntensityEnd;
    }
}
