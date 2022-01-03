//
// Created by kaiyan on 2022/1/2.
//

#include "common.h"
#include <stdarg.h>

/* 打印一个错误诊断信息并可选择退出 */
void error(int status, int err, char *fmt, ...){
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    if(err)
        fprintf(stderr, ": %s (%d)\n", strerror(err), err);
    if(status)
        exit(status);
}