//
// Created by kaiyan on 2021/12/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int make_socket(uint16_t port){
    int sock;
    struct sockaddr_in name;

    /* 创建流式IPV4 socket */
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* 设置IP和port */
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    /* 绑定地址 */
    if(bind(sock, (struct sockaddr*)&name, sizeof(name)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    return sock;
}

int main(int argc, char** argv){
    int sockfd = make_socket(12345);
    exit(0);
}
