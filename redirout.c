#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]){
    if(argc<3){
        printf("Please provide a file name and a command in that order with spaces in between!\n");
        return 0;
    }
    int fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR);
    dup2(fd,1);
    char* *p=argv+2;
    execvp(argv[2],p);
    printf("please provide a valid command");
    close(fd);
}