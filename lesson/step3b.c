/* 第 3 步 · 实验 B：把英文换成中文，看会发生什么
   —— 同样的代码，只是 msg 变了。跑一下，注意速度和屏幕上的样子。 */
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    const char *msg = "新婚快乐！";
    int i = 0;

    while (msg[i] != '\0')
    {
        printf("%c", msg[i]);
        fflush(stdout);
        usleep(150000);
        i++;
    }

    printf("\n");
    return 0;
}
