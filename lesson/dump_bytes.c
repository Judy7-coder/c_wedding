/* 工具程序：把字符串里每个字节的值打印出来，看清"一个汉字占 3 个字节" */
#include <stdio.h>

int main(void)
{
    const char *msg = "新婚快乐！";

    for (int i = 0; msg[i] != '\0'; i++)
        printf("第 %2d 格: 0x%02X\n", i, (unsigned char)msg[i]);

    return 0;
}
