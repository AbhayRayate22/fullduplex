#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
 
int main()
{
FILE *fp;
int fd1,fd2,l=1,w=1,c=0,i;
    char *myfifo1="file1",str1[100],ch;
    char *myfifo2="file2",str2[100];
  
//read data from first fifo
	fd1=open(myfifo1,O_RDONLY);
    	read(fd1,str1,100);
    	printf("\n pipe1:%s",str1);
    
// Count line,world,character

    i=0;
      while(str1[i]!='\0')
          {
            if(str1[i]==' '||str1[i]=='\n')
             l++;
            else if(str1[i]==' ')
              w++;
            else
              c++;
              i++;
           }
	// check result

     printf("\n No of Words: %d",w);
     printf("\n No of Characters: %d",c);
     printf("\n No of Lines: %d",l);
   
//write no word,line,character in a text file.
	{
	fp=fopen("kp.txt","w");
	fprintf(fp,"\n No of lines:%d",l);
	fprintf(fp,"\n No of Words:%d",w);
	fprintf(fp,"\n No of character:%d",c);
	fclose(fp);
	fp=fopen("kp.txt","r");
	ch=fgetc(fp);

	i=0;
	while(ch!=EOF)
	{
		str2[i]=ch;
		i++;
		ch=fgetc(fp);	
	}
	str2[i]='\0';
	fclose(fp);

	}

	close(fd1);
//write a data of text file in second pipe

	fd2=open(myfifo2,O_WRONLY);
	write(fd2,str2,strlen(str2)+1);
	close(fd2);
}




