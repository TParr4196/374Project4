#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//int argc, char *argv[]
int main(){
    int pfd[2];
    pipe(pfd);
    pid_t pid=fork();
    char* commands[100];
    if(pid>0){
        dup2(pfd[1],1);
        close(pfd[0]);
        commands[0]="ls";
        commands[1]="-1a";
        execlp(commands[0],"ls","-1a",(char *)NULL);
    }else if(pid==0){
        dup2(pfd[0],0);
        close(pfd[1]);
        commands[0]="wc";
        commands[1]="-l";
        commands[2]=NULL;
        execlp(commands[0],"wc","-l",(char *)NULL);
    }
}