//
// Created by kaiyan on 2022/1/2.
//
#include "../lib/common.h"
#include <errno.h>
#include <arpa/inet.h>   //inet_pton

#define MESSAGE_SIZE    1024000

void send_data(int sockfd){
    char *query;
    query = malloc(MESSAGE_SIZE + 1);
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        query[i] = 'a';
    }
    query[MESSAGE_SIZE] = '\0';

    const char *cp;
    cp = query;
    size_t remainning = strlen(query);
    while (remainning){
        int n_written = send(sockfd, cp, remainning, 0);
        fprintf(stdout, "send into buffer %d \n", n_written);

        if(n_written <= 0){
            error(1, errno, "send failed!");
            return;
        }

        remainning -= n_written;
        cp += n_written;
    }
    //return;
}

int main(int argc, char** argv)
{
    int sockfd;
    struct  sockaddr_in servaddr;

   if(argc != 2)
       error(1, 0, "usage: tcpclient <IPaddress>");

   sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    /* 将IP地址在“点分十进制”和“二进制整数”之间转换 */
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    int connect_rt = connect(sockfd,(struct sockaddr*)&servaddr, sizeof(servaddr));
    if(connect_rt < 0){
        error(1, errno, "connect failed ");
    }
    send_data(sockfd);

    return  0;
}
