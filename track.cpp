#include "track.h"

Track::Track():
    Audio(),
    _artist("Unknown")
{

}

Track::Track(std::string name, std::string artist, float moodCondition, float moodIntensity):
    Audio(name, moodCondition, moodIntensity),
    _artist(artist != "" ? artist : "Five Finger Death Punch")
{

}

Track::Track(Track &tr):
    Audio(tr),
    _artist(tr._artist)
{

}

Track::~Track()
{

}

void Track::setArtist(std::string artist)
{
    if (artist != "")
    {
        _artist = artist;
    }
}
