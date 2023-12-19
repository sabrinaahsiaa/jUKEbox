/* Structure that contains the chord that is to be played 
   and how fast the strum should be 
   servo_time[8] is only good for storing 8 strums,
   enter -1 as the last element if less than 8 strums is required per chord  
*/
struct Song {
    char chord_name[8];
    char servo_time[8];
};

// Songs
extern struct Song Riptide[]; // Riptide
extern struct Song SOTR[]; // Somewhere Over The Rainbow
extern struct Song CHFIL[]; // Can't Help Falling In Love
extern struct Song AT[]; // Adventure Time
extern struct Song LOFY[]; // Looking Out For You

// Will play the songs
void Play_Song(struct Song *song); 

// Takes input from freeplay mode
void Playback(void);
