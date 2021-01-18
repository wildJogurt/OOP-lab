#ifndef VECTOR_H
#define VECTOR_H
#include <track.h>
#include <medley.h>
#include <string.h>

class Vector
{
protected:
    Track *songs;
    int sizeOfVector, currentSize;
    void changeSize(int newSize);
public:
    Vector();
    Vector(int length);
    Vector(const Vector &cmp);
    ~Vector();
    void insert(Track &cmp, int position);
    void del(int position);
    Track getTrack(int i);
    void erase();
    int size();
    void writeToFile(std::string fileName);
    void readFromFile(std::string fileName);
    bool comparison(Vector &cmp1);
    Vector check(float conditionBegin, float intensityBegin, float conditionEnd, float intensityEnd);
};

#endif // VECTOR_H
