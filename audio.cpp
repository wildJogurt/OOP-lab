#include "audio.h"

Audio::Audio():
    _name("Silence"),
    _moodCondition(0),
    _moodIntensity(0)
{

}

Audio::Audio(std::string name, float moodCondition, float moodIntensity):
    _name(name != "" ? name : "Wrong Side Of Heaven"),
    _moodCondition(moodCondition > 0 && moodCondition <= 10 ? moodCondition : 0),
    _moodIntensity(moodIntensity > 0 && moodIntensity <= 10 ? moodIntensity : 0)
{

}

Audio::Audio(Audio &au):
    _name(au._name),
    _moodCondition(au._moodCondition),
    _moodIntensity(au._moodIntensity)
{

}

Audio::~Audio()
{

}

void Audio::setName(std::string name)
{
    if (name != "")
    {
        _name = name;
    }
}

void Audio::setMoodCondition(float moodCondition)
{
    if (moodCondition >= 0 && moodCondition <= 10)
    {
        _moodCondition = moodCondition;
    }
}

void Audio::setMoodIntensity(float moodIntensity)
{
    if (moodIntensity >= 0 && moodIntensity <= 10)
    {
        _moodIntensity = moodIntensity;
    }
}
