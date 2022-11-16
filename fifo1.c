/*
Problem Statement: Inter process communication in Linux using following.
a. Pipes: Full duplex communication between parent and child processes. Parent process writes a
pathname of a file (the contents of the file are desired) on one pipe to be read by child process
and child process writes the contents of the file on second pipe to be read by parent process and
displays on standard output.
*/


#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
	int fd1,fd2;
	char *myfifo1="file1",str1[100],str2[100];
	char *myfifo2="file2";

	//create fifo pipe
	
	fd1=mkfifo(myfifo1,0666);
	fd2=mkfifo(myfifo2,0666);

	//read data to write on first fifo pipe

	printf("\nEnter String:");
	fgets(str1,100,stdin);
	
	//write data in first fifo file

	fd1=open(myfifo1,O_WRONLY);
	write(fd1,str1,strlen(str1)+1);
	close(fd1);
	
	//read data from second pipe
	
	fd2=open(myfifo2,O_RDONLY);
	read(fd2,str2,100);

	//print output

	printf("Message from Fifo process:\n%s",str2);
	close(fd2);
	

}
