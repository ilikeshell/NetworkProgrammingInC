//
// Created by kaiyan on 2022/1/2.
//

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                     /* read()等函数 */
#include <errno.h>                      /* 定义如EINTR等错误号 */
#include <string.h>                     /* 定义一些便利的函数，如bzero(), memset()等 */
#include <sys/types.h>                  /* size_t等类型定义 */
#include <sys/socket.h>                 /* 基本的socket定义 */
#include <netinet/in.h>                 /* sockaddr_in以及其它定义 */
#include <arpa/inet.h>                  /* inet_pton */

/* 从套接字中读取"size"个字节 */
size_t readn(int fd, void* buffer, size_t size);

void error(int status, int err, char *fmt, ...);


#define     SERV_PORT       43211
#define     BUFFER_SIZE     4096
#define     MAXLINE         4096

#endif //_COMMON_H_
