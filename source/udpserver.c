//
// Created by kaiyan on 2022/1/4.
//

/* UDP的服务端程序 */

#include "../lib/common.h"

static int count;

static void recvfrom_int(int signo){
    printf("\nreceived %d datagrams\n", count);
    exit(0);
}

int main(int argc, char **argv){

    /* 创建UDP套接字 */
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    /* 初始化套接字地址和套接字进行绑定 */
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));


    char message[MAXLINE];
    count = 0;

    signal(SIGINT, recvfrom_int);

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    for (;;) {
        int n = recvfrom(socket_fd, message, MAXLINE, 0, (struct sockaddr *)&client_addr, &client_len);
        message[n] = 0;
        printf("received %d bytes: %s\n", n, message);

        char send_line[MAXLINE];
        sprintf(send_line, "Hi, %s", message);
        sendto(socket_fd, send_line, strlen(send_line), 0, (struct sockaddr *)&client_addr, client_len);

        count++;
    }
}
