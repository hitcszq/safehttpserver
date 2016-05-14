#include <stdio.h>
#include <stdlib.h>
char *env_init[]={ ¡°USER=unknown¡±, ¡°PATH=/tmp¡±, NULL};
int main()
{   pid_t  pid;
¡¡¡¡¡¡if  ( (pid=fork())<0 )
¡¡¡¡¡¡    Err_sys(¡°fork error¡±);
¡¡¡¡¡¡else  if  (pid == 0)   {   /*specify path, specify environment  */
¡¡¡¡¡¡     if  ( execle(¡°/home/stevens/bin/echoall¡±, ¡°echoall¡±,  ¡°myarg1¡±, 
¡¡¡¡¡¡       ¡°MY ARG2¡±,  (char *) 0 , env_init) < 0)
¡¡¡¡¡¡               err_sys(¡°fork error¡±);    }¡¡
¡¡¡¡¡¡if  (waitpid(pid,NULL,0)<0)
¡¡¡¡¡¡        err_sys(¡°wait error¡±); 
¡¡¡¡¡¡if  ( (pid=fork())<0 )
¡¡¡¡¡¡    Err_sys(¡°fork error¡±);
¡¡¡¡¡¡else  if  (pid == 0)   {   /*specify path, specify environment  */
¡¡¡¡¡¡     if  ( execlp(¡°echoall¡±, ¡°echoall¡±,  ¡°only 1 args¡±, (char *) 0 < 0)
¡¡¡¡¡¡             err_sys(¡°fork error¡±);    }
¡¡¡¡¡¡exit(0);
}
