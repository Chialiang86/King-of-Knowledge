#ifndef MUSICINFO_H
#define MUSICINFO_H
#include <QString>

namespace music_info {

typedef enum SharpFlat {sharp,flat} sharpflat;
const QString ToneTable[2][12] = {{"C", "#C", "D", "#D", "E", "F",
        "#F", "G", "#G", "A", "#A", "B"
    },
    {
        "C", "bD", "D", "bE", "E", "F",
        "bG", "G", "bA", "A", "bB", "B"
    }
};

typedef enum Chord3 {maj,min,aux,dim} chord3;
const QString Chord3_key[4] = {"maj", "m", "aux", "dim"};
const int chord3_struct[4][3] = {{0, 4, 7}, //maj
    {0, 3, 7}, //min
    {0, 4, 8}, //aux
    {0, 3, 6}
};//dim

typedef enum Chord7 {maj7,min7,M7,m7b5,dim7} chord7;
const QString Chord7_key[5] = {"maj7", "m7", "7", "m7b5", "dim7"};
const int chord7_struct[5][4] = {{0, 4, 7, 11}, //maj7
    {0, 3, 7, 10}, //min7
    {0, 4, 7, 10}, //M7
    {0, 3, 6, 10}, //m7b5
    {0, 3, 6, 9}
};//dim7

typedef struct Tone_Base {
    QString tone;
    sharpflat type;
    QString chord3struct;
    QString chord7struct;
} tone_base;

}


#endif // MUSICINFO_H
