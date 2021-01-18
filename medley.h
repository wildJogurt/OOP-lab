#ifndef MEDLEY_H
#define MEDLEY_H
#include "audio.h"
#include "iostream"

class Medley : public Audio
{
public:
    Medley();
    Medley(std::string name, float moodCondition, float moodIntensity, float moodConditionEnd, float moodIntensityEnd);
    Medley(Medley &med);
    virtual ~Medley();
    float getMoodConditionEnd() const { return _moodConditionEnd; }
    float getMoodIntensityEnd() const { return _moodIntensityEnd; }
    void setMoodConditionEnd(float moodConditionEnd);
    void setMoodIntensityEnd(float moodIntensityEnd);
private:
    float _moodConditionEnd, _moodIntensityEnd;
};

#endif // MEDLEY_H
