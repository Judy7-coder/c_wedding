/* 第 3 步：用循环代替手写重复 —— 先用英文实验，保证逻辑对 */
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    const char *msg = "Happy Wedding!";
    int i = 0;

    while (msg[i] != '\0')      /* 遇到字符串结尾的 \0 就停 */
    {
        printf("%c", msg[i]);   /* 只打一个字符 */
        fflush(stdout);
        usleep(150000);         /* 停 0.15 秒 */
        i++;
    }

    printf("\n");
    return 0;
}
