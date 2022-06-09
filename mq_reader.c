#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10

struct msg_buffer
{
	long mesg_type;
	char mesg_text[100];
}message;

int main()
{
	key_t key;
	int msgid;
	key = ftok("programFile",65);
	msgid = msgget(key,0666|IPC_CREAT);
	msgrcv(msgid,&message,sizeof(message),1,0);
	printf("Data received is : %s",message.mesg_text);
	msgctl(msgid,IPC_RMID,NULL);
}
