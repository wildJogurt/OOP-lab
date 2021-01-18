#ifndef TRACK_H
#define TRACK_H
#include "audio.h"

class Track : public Audio
{
public:
    Track();
    Track(std::string name, std::string artist, float moodCondition, float moodIntensity);
    Track(Track &tr);
    virtual ~Track();
    std::string getArtist() const { return _artist; }
    void setArtist(std::string artist);
private:
    std::string _artist;
};

#endif // TRACK_H
