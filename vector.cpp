#include "vector.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <assert.h>
#include <cstdlib>

Audio* factory(Kind kind)
{
    if(kind == AUDIO)
    {
        return nullptr;
    }
    if(kind == TRACK)
    {
        return new Track;
    }
    if(kind == MEDLEY)
    {
        return new Medley;
    }
}

Vector::Vector()
{
    currentSize = 0;
    sizeOfVector = 20;
    songs = new Track[sizeOfVector];
}

Vector::Vector(int length)
{
    currentSize = length;
    sizeOfVector = 20;
    songs = new Track[sizeOfVector];
}

Vector::Vector(const Vector &cmp)
{
    currentSize = cmp.currentSize;
    sizeOfVector = cmp.sizeOfVector;
    songs = cmp.songs;
}

Vector::~Vector()
{
    delete[](songs);
}

int Vector::size()
{
    return currentSize;
}

void Vector::erase()
{
    int i;
    for(i = 0; i < sizeOfVector; i++)
        delete &songs[i];
    currentSize = 0;
}

void Vector::insert(Track &cmp, int position)
{
    if(position <= sizeOfVector)
    {
        if(position >= currentSize)
        {
            position = currentSize;
            *(songs + position) = cmp;
        }
        else
            for(int i = currentSize; i > position; i--)
            {
                *(songs + i) = *(songs + i - 1);
                *(songs + position) = cmp;
            }
        currentSize += 1;
    }
    else
        std::cout << "Please, input correct value." << std::endl;
}

void Vector::del(int position)
{
    if(position < currentSize)
    {
        for(int i = position; i < currentSize - 1; i++)
            *(songs + i) = *(songs + i + 1);
        currentSize--;
    }
    else
        std::cout << "Incorrect position." << std::endl;
}

bool Vector::comparison(Vector &cmp1)
{
    bool flag = true;
    if(currentSize != cmp1.currentSize)
        flag = false;
    else
        for(int i = 0; i < currentSize && flag == true; i++)
            if(songs[i].getName() != cmp1.songs[i].getName() ||
                    songs[i].getArtist() != cmp1.songs[i].getArtist() || songs[i].getMoodCondition() != cmp1.songs[i].getMoodCondition() || songs[i].getMoodIntensity() != cmp1.songs[i].getMoodIntensity())
                flag = false;
    return flag;
}

void Vector::readFromFile(std::string fileName)
{
    std::ifstream fin;
    char s[81];
    float n;
    fin.open(fileName);
    if (fin.is_open())
    {
        for(int i = 0; i < currentSize; i++)
        {
            fin.getline(s, 81);
            songs[i].setName(std::string(s));
            fin.getline(s, 81);
            songs[i].setArtist(std::string(s));
            fin.getline(s, 81);
            songs[i].setMoodCondition(std::stof(s));
            fin.getline(s, 81);
            songs[i].setMoodIntensity(std::stof(s));
        }
    }
    else
        std::cout << "Incorrect name of file." << std::endl;
    fin.close();
}

void Vector::writeToFile(std::string fileName)
{
    std::ofstream fout;
    std::string s;
    float count;
    fout.open(fileName, std::ios_base::trunc);
    for(int i = 0; i < currentSize; i++)
    {
        s = songs[i].getName();
        fout << s << std::endl;
        s = "";
        s = songs[i].getArtist();
        fout << s << std::endl;
        s = "";
        count = songs[i].getMoodCondition();
        fout << count << std::endl;
        count = songs[i].getMoodIntensity();
        fout << count << std::endl;
    }
    fout.close();
}

Track Vector::getTrack(int i)
{
    if (i >= 0 && i < currentSize)
        return *(songs + i);
    else
    {
        std::cout << "There's no track with that index." << std::endl;
    }
}

Vector Vector::check(float conditionBegin, float intensityBegin, float conditionEnd, float intensityEnd)
{
    Vector *cmp = new Vector();
    Track *c = new Track;
    float pointBegin = conditionBegin * conditionBegin + intensityBegin * intensityBegin;
    float pointEnd = conditionEnd * conditionEnd + intensityEnd * intensityEnd;
    if(pointBegin < pointEnd)
    {
        for(int i = 0; i < currentSize; i++)
        {
            if((pow(songs[i].getMoodCondition(), 2) + pow(songs[i].getMoodIntensity(), 2)) > pointBegin && (pow(songs[i].getMoodCondition(), 2) + pow(songs[i].getMoodIntensity(), 2)) < pointEnd)
            {
                cmp -> insert(songs[i], cmp -> currentSize);
            }
        }
    }
    else
    {
        for(int i = 0; i < currentSize; i++)
        {
            if((pow(songs[i].getMoodCondition(), 2.0) + pow(songs[i].getMoodIntensity(), 2.0)) < pointBegin && (pow(songs[i].getMoodCondition(), 2.0) + pow(songs[i].getMoodIntensity(), 2.0)) < pointEnd)
            {
                cmp -> insert(songs[i], cmp -> currentSize);
            }
        }
    }
    if(pointBegin > pointEnd)
    {
        for(int i = 0; i < cmp -> currentSize - 1; i++)
        {
            for(int j = 1; j < cmp -> currentSize; j++)
            {
                if(pow(cmp->songs[i].getMoodCondition(), 2.0) + pow(cmp->songs[i].getMoodIntensity(), 2.0) < pow(cmp->songs[j].getMoodCondition(), 2.0) + pow(cmp->songs[j].getMoodIntensity(), 2.0))
                {
                    *c = cmp -> songs[i];
                    cmp -> songs[i] = cmp -> songs[j];
                    cmp -> songs[j] = *c;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < cmp -> currentSize - 1; i++)
        {
            for(int j = 1; j < cmp -> currentSize; j++)
            {
                if(pow(cmp->songs[i].getMoodCondition(), 2.0) + pow(cmp->songs[i].getMoodIntensity(), 2.0) > pow(cmp->songs[j].getMoodCondition(), 2.0) + pow(cmp->songs[j].getMoodIntensity(), 2.0))
                {
                    *c = cmp -> songs[i];
                    cmp -> songs[i] = cmp -> songs[j];
                    cmp -> songs[j] = *c;
                }
            }
        }
    }
    return *cmp;
}
