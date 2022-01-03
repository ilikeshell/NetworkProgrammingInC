//
// Created by kaiyan on 2022/1/2.
//
#include "common.h"

/* 从套接字中读取"size"个字节 */
size_t readn(int fd, void* buffer, size_t size){
    char *buffer_pointer = buffer;
    int length = size;

    while (length > 0){
        int result = read(fd, buffer_pointer, length);

        /* 处理返回值为0或者为负的情况 */
        if(result < 0)
        {
            if(result == EINTR)
                continue;
            else
                return (-1);
        }else if(result == 0)
            break;

        /* 更新剩余缓存长度和缓存基址 */
        length -= result;
        buffer_pointer += result;
    }

    return (size - length);     //返回实际读取的值
}
