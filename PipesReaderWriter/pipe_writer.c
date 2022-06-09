#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main()
{
	int fd;
	char *fifo = "/tmp/newpipe";
	mkfifo(fifo,0666);
	char arr1[80],arr2[80];
	while(1)
	{
		fd = open(fifo,O_WRONLY);
		fgets(arr2,80,stdin);
		write(fd,arr2,strlen(arr2)+1);
		close(fd);
		fd = open(fifo,O_RDONLY);
		read(fd,arr1,sizeof(arr1));
		printf("\nUser 2:%s\n",arr1);
		close(fd);
	}
}

/*OUTPUT

hello
user 2 : hi 

*/
