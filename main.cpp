#include <iostream>
#include "track.h"
#include "vector.h"
#include <assert.h>

using namespace std;

void output(Vector &cmp)
{
    for(int i = 0; i < cmp.size(); i++)
    {
        cout << cmp.getTrack(i).getName() << endl;
        cout << cmp.getTrack(i).getArtist() << endl;
        cout << cmp.getTrack(i).getMoodCondition() << endl;
        cout << cmp.getTrack(i).getMoodIntensity() << endl;
    }
}

int main()
{
    Vector *song1 = new Vector(5);
    Track *a = new Track();
    assert(song1 -> size() == 5);
    song1 -> readFromFile("input.txt");
    Vector *song2 = new Vector(*song1);
    assert(song2 -> comparison(*song1));
    Vector *song3 = new Vector();
    a -> setName("Bulletproof");
    a -> setArtist("Godsmack");
    a -> setMoodCondition(4.5);
    a -> setMoodIntensity(6.2);
    song1 -> insert(*a, 5);
    *song3 = *song1;
    song3 -> check(0.0, 0.0, 10.0, 10.0);
    output(*song3);
    song3 -> writeToFile("output.txt");
//    Medley *live = new Medley;
//    live->setName("Knife Party Concert");
//    live->setMoodCondition(6.9);
//    live->setMoodIntensity(8.9);
//    live->setMoodConditionEnd(7.8);
//    live->setMoodIntensityEnd(6.7);
//    cout << live->getName() << endl;
//    cout << live->getMoodCondition() << endl;
//    cout << live->getMoodIntensity() << endl;
//    cout << live->getMoodConditionEnd() << endl;
//    cout << live->getMoodIntensityEnd() << endl;
    return 0;
}
