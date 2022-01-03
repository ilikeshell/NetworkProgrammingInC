//
// Created by kaiyan on 2022/1/2.
//

#include "../lib/common.h"

void read_data(int connfd) {
    ssize_t n;
    char buf[1024];

    int time = 0;
    for(;;){
        fprintf(stdout, "Block in read\n");
        if((n = read(connfd, buf, 1024)) == 0)
            return;
        time++;
        fprintf(stdout, "1K read for %d \n", time);
        usleep(1000);
    }
}

int main(int argc, char **argv)
{
    int listenfd, connfd;
    socklen_t client;
    struct  sockaddr_in cliaddr, servaddr;

    /* 创建一个套接字 */
    listenfd = socket(PF_INET, SOCK_STREAM, 0);

    /* 设置套接字地址 */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    /* 绑定套接字 */
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    /* 开始监听 */
    listen(listenfd, 1024);

    /* 开始循环处理用户请求 */
    while (1)
    {
        client = sizeof(cliaddr);
        connfd = accept(listenfd, &cliaddr, &client);
        read_data(connfd);
        close(connfd);
    }

    return 0;
}