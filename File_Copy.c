#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char file_name[100],buf[2];
	int new_file_desc,old_file_desc;
  long long i;
	old_file_desc = open(argv[1],O_RDONLY);
	mkdir("Assignment",S_IRWXU|S_IXGRP|S_IXOTH);
	chdir("Assignment");
	strcat(file_name,"output_");
	strcat(file_name,argv[1]);
	new_file_desc = creat(file_name,S_IWUSR|S_IRUSR);
	 for(i=-2;lseek(old_file_desc,i,SEEK_END)!=-1;i--){
   	lseek(old_file_desc,i,SEEK_END);
	 	read(old_file_desc,buf,1);
	 	write(new_file_desc,buf,1);
	 }
	close(old_file_desc);
	close(new_file_desc);
	new_file_desc=open(file_name,O_RDONLY);
	return 0;
}
