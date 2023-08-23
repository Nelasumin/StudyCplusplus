#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

int main()

{

    putchar('a');
    write(1, "b", 1);

    putchar('a');
    write(1, "b", 1);

    putchar('a');
    write(1, "b", 1);

    //使用strace 来查看运行文件

    //结果为什么为bbbaaa?
    //因为文件io响应速度快刺探内核
    //putchar的结果为什么最后输出？
    //使用strace命令查看 编译后的文件
    //因为putchar
    //是把内容存储在缓冲区中 最后三次内容一起输出出去。



    exit(0);
}