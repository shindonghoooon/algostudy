#ifndef NULL
#define NULL 0
#endif 

#define bit7(x) ((x>>8) & (1<<7) - 1)

int N, arr[10005][200], bcnt;
const int SIZE = 1 << 21;

struct Hash {
   int id, pos;
   Hash* next;
   Hash* myAlloc(int _id, int _pos, Hash* _next) {
      id = _id, pos = _pos, next = _next;
      return this;
   }
} buf[SIZE], *hash[SIZE];

void push(int key, int id, int pos)
{
   hash[key] = buf[bcnt++].myAlloc(id, pos, hash[key]);
}

int Key(int a, int b, int c)
{
   return (bit7(a) << 14) | (bit7(b) << 7) | bit7(c);
}

void initUser(int soundNum) {
   N = soundNum;
   bcnt = 0;
   for (int i = 0; i < SIZE; i++) hash[i] = 0;
}

void registerSound(int soundID, int soundLen, int soundArr[200]) {
   int i, key;
   for (i = 0; i < soundLen; i++) arr[soundID][i] = soundArr[i];
   for (i = 0; i <= soundLen - 8; i++)
   {
      key = Key(soundArr[i], soundArr[i + 1], soundArr[i + 2]);
      push(key, soundID, i);
   }
}

int chkhash(int *a, int *b)
{
   for (int i = 0; i < 8; i++)
   {
      if (a[i] - 128 > b[i] || a[i] + 127 < b[i]) return 0;
   }
   return 1;
}

int pat[3][8] = { {-127, -127, -127, -127, 128, 128, 128, 128},
              {-127, -127, 128, 128, -127, -127, 128, 128},
              {-127, 128, -127, 128, -127, 128, -127, 128} };

int plagiarismCheck(int newData[8])
{
   int id = 0, key;
   for (int i = 0; i < 8; i++)
   {
      key = Key(newData[0] + pat[0][i], newData[1] + pat[1][i], newData[2] + pat[2][i]);
      for (Hash* p = hash[key]; p; p = p->next)
      {
         if (chkhash(arr[p->id] + p->pos, newData)) return p->id;
      }
   }
   
   return id;
}
 

main.cpp

#ifndef _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#endif 

#include <stdio.h> 

#define SOUND_MAX_LENGTH (200) 
#define NEW_SOUND_LENGTH (8) 

static int randomSeed, soundNum, lengthLimit, queryCount;
static int soundData[10005][SOUND_MAX_LENGTH];
static int newData[10005];

extern void initUser(int soundNum);
extern void registerSound(int soundID, int soundLen, int soundArr[SOUND_MAX_LENGTH]);
extern int  plagiarismCheck(int newData[NEW_SOUND_LENGTH]);


static int getRand(void) {
   randomSeed = randomSeed * 0x343FD + 0x269EC3;
   return (randomSeed >> 16) & 0x7FFF;
}

static void generateSoundData() {
   int args[SOUND_MAX_LENGTH];
   int sound_len_args;
   for (int id = 1; id <= soundNum; id++) {
      sound_len_args = newData[id] = getRand() % lengthLimit + 1;

      if (newData[id] < NEW_SOUND_LENGTH)
         sound_len_args = newData[id] = NEW_SOUND_LENGTH;

      for (int i = 0; i < newData[id]; i++) {
         args[i] = soundData[id][i] = getRand() - 16384;
      }

      registerSound(id, sound_len_args, args);
   }
}

static bool generateNewData() {
   int args[NEW_SOUND_LENGTH];

   int soundID = getRand() % soundNum + 1;
   int stIdx = getRand() % newData[soundID];

   if (stIdx + NEW_SOUND_LENGTH >= newData[soundID]) {
      stIdx = newData[soundID] - NEW_SOUND_LENGTH;
   }

   for (int i = 0; i < NEW_SOUND_LENGTH; i++) {
      args[i] = soundData[soundID][i + stIdx] + getRand() % 256 - 128;
   }

   int return_val = plagiarismCheck(args);

   return return_val == soundID;
}

int main() {
   setbuf(stdout, NULL);
   int testCase, totalScore = 0;

   // freopen("input.txt", "r", stdin); 

   scanf("%d", &testCase);

   for (int tc = 1; tc <= testCase; tc++) {
      scanf("%d%d%d%d", &randomSeed, &soundNum, &lengthLimit, &queryCount);

      int correctCount = 0;

      initUser(soundNum);
      generateSoundData();

      for (int query = 0; query < queryCount; query++) {
         if (generateNewData())
            correctCount++;
      }
      if (correctCount == queryCount) {
         printf("#%d 100\n", tc);
         totalScore += 100;
      }
      else {
         printf("#%d 0\n", tc);
      }
   }
   printf("Total Score : %d\n", totalScore / testCase);

   return 0;
}
