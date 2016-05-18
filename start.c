#include <stdio.h>
#include <stdlib.h>
char *env_init[]={"USER=zhangqi","PATH=/tmp",NULL};
int main()
{   
	pid_t  pid;
	printf("dad_p uid:%d,euid:%d\n",getuid(),geteuid());
	if  ((pid=fork())<0)
  		printf("fork error!!\n");
	else  if  (pid == 0)  
	 {   
		/*specify path, specify environment  */
		printf("son_p before exec:::uid:%d,euid:%d",getuid(),geteuid());
		if  (execle("httpserversafe", "httpserversafe",(char *)0,env_init) < 0)
		{
		   printf("exc_error!!!\n");    
		}
	}
	exit(0);
}
