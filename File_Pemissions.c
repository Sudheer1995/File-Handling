#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void mode_(struct stat stat_obj){
	char m = '-';
	if(stat_obj.st_mode & S_IFDIR)
		m = 'd';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IRUSR)
		m = 'r';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IWUSR)
		m = 'w';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IXUSR)
	  m = 'x';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IRGRP)
		m = 'r';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IWGRP)
		m = 'w';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IXGRP)
		m = 'x';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IROTH)
		m = 'r';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IWOTH)
		m = 'w';
	write(STDOUT_FILENO,&m,1);
	m = '-';
	if(stat_obj.st_mode & S_IXOTH)
	 	m = 'x';
	write(STDOUT_FILENO,&m,1);
 	m = '-';
	write(STDOUT_FILENO,"\n",strlen("\n"));
	return;
}
int main(int argc, char const *argv[])
{
	struct stat stat_obj;
	char file_name[100],old_buf[2],new_buf[2];
	int old_filedesc,new_filedesc,flag=0;
	long long k,i=-1,j=0;
	unsigned long mode;
	old_filedesc = open(argv[1],O_RDONLY);
	strcat(file_name,"Assignment/output_");
	strcat(file_name,argv[1]);
	write(STDOUT_FILENO,"Checking whether the directory has been created: ",strlen("Checking whether the directory has been created: "));
	if(access("Assignment",F_OK)==0)
	write(STDOUT_FILENO,"Yes\n",strlen("Yes\n"));
	else
	write(STDOUT_FILENO,"No\n",strlen("No\n"));
	write(STDOUT_FILENO,"Checking whether the file has been created: ",strlen("Checking whether the file has been created: "));
	if(access(file_name,F_OK)==0)
	write(STDOUT_FILENO,"Yes\n",strlen("Yes\n"));
	else
	write(STDOUT_FILENO,"No\n",strlen("No\n"));
	stat("Assignment",&stat_obj);
	write(STDOUT_FILENO,"Checking the permissions for directory: ",strlen("Checking the permissions for directory: "));
	mode_(stat_obj);
	stat(file_name,&stat_obj);
	write(STDOUT_FILENO,"Checking the permissions for file: ",strlen("Checking the permissions for file: "));
	mode_(stat_obj);
	write(STDOUT_FILENO,"Checking whether file contents have been reversed: ",strlen("Checking whether file contents have been reversed: "));
	new_filedesc=open(file_name,O_RDONLY);
	if(new_filedesc >= 0){
	while(lseek(new_filedesc,i,SEEK_END)!=-1&&lseek(old_filedesc,j,SEEK_SET)!=-1){
		lseek(new_filedesc,i,SEEK_END);
		read(new_filedesc,new_buf,1);
		lseek(old_filedesc,j,SEEK_SET);
		read(old_filedesc,old_buf,1);
		if(new_buf[0]!=old_buf[0]){
			flag = 1;
			break; }
			j++;
			i--;
		  }
		if(flag==0)
		write(STDOUT_FILENO,"Yes\n",strlen("Yes\n"));
		else
		write(STDOUT_FILENO,"No\n",strlen("No\n"));
		}
		else
		write(STDOUT_FILENO,"No\n",strlen("No\n"));
		close(old_filedesc);
		close(new_filedesc);
		return 0;
	}
