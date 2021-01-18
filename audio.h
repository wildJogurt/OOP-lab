#ifndef AUDIO_H
#define AUDIO_H
#include <iostream>

enum Kind{AUDIO, TRACK, MEDLEY};

class Audio
{
public:
    Audio();
    Audio(std::string name, float moodCondition, float moodIntensity);
    Audio(Audio &au);
    ~Audio();
    std::string getName() const { return _name; }
    float getMoodCondition() const { return _moodCondition; }
    float getMoodIntensity() const { return _moodIntensity; }
    void setName(std::string name);
    void setMoodCondition(float moodCondition);
    void setMoodIntensity(float moodIntensity);
protected:
    Kind _kind;
    std::string _name;
    float _moodCondition, _moodIntensity;
};

#endif // AUDIO_H
