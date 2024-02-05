#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
    int fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR);
    dup2(fd,1);
    char* *p=argv+2;
    execvp(argv[2],p);
}