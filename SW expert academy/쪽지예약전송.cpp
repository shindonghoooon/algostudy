#define MAXM	3
#define MAX_MESSAGE 100000
#define MAX_N 1000
#include <malloc.h>


typedef struct _msg {
	int mID;
	int uID1, uID2;
	int cTime, sTime;
	struct _msg* sNext;
	struct _msg* iNext;
}MSG;

MSG pool[MAX_MESSAGE + 1];
MSG *smsg[MAX_N + 1];
MSG* imsg[MAX_N + 1];

bool isRead[MAX_MESSAGE + 1];
bool sDel[MAX_MESSAGE + 1];
bool iDel[MAX_MESSAGE + 1];
int users = 0;


void init(int N)
{
	users = N;
	for (register int i = 0; i <= N; i++)
	{
		if (smsg[i]) {
			free(smsg[i]);
			smsg[i] = NULL;
		}
		if (imsg[i]) {
			free(imsg[i]);
			imsg[i] = NULL;
		}
		smsg[i] = (MSG*)malloc(sizeof(MSG));
		smsg[i]->sNext = NULL;
		imsg[i] = (MSG*)malloc(sizeof(MSG));
		imsg[i]->iNext = NULL;
	}

}

void sendMessage(int cTimestamp, int uID1, int uID2, int mID, int scheduleTimestamp)
{
	pool[mID].uID1 = uID1;
	pool[mID].uID2 = uID2;
	pool[mID].cTime = cTimestamp;
	pool[mID].sTime = scheduleTimestamp;
	pool[mID].sNext = smsg[uID1]->sNext;
	smsg[uID1]->sNext = &pool[mID];
	isRead[mID] = false;
	sDel[mID] = false;
	iDel[mID] = false;


	MSG *tmp = imsg[uID2];
	while (tmp!=NULL) {
		if (!(tmp->iNext))
			break;
		if (tmp->iNext->sTime <= scheduleTimestamp)
			break;
		tmp = tmp->iNext;
	}
	pool[mID].iNext = tmp->iNext;
	tmp->iNext = &pool[mID];
}

int retrieveSentbox(int cTimestamp, int uID, int mIDList[MAXM], int uIDList[MAXM], int readList[MAXM])
{
	int num = 0;
	MSG* tmp = smsg[uID];
	
	while (tmp!=NULL) {
		if (!(tmp->sNext))
			break;
		int mi = tmp->sNext->mID;
		mIDList[num] = mi;
		uIDList[num] = tmp->sNext->uID2;
		if (iDel[mi]<)
		{
			readList[num] = 1;
		}
		else
		{
			readList[num] = 0;
		}
		num++;
		tmp = tmp->sNext;
	}


	return num;
}

int retrieveInbox(int cTimestamp, int uID, int mIDList[MAXM], int uIDList[MAXM], int readList[MAXM])
{

	return -1;
}

int readMessage(int cTimestamp, int uID, int mID)
{
	return -1;
}

int deleteMessage(int cTimestamp, int uID, int mID)
{
	return -1;
}
