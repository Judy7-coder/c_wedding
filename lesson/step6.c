/* 第 6 步：加随机 —— 三个零件凑齐，就是完整的 wedding3 */
#include <stdio.h>
#include <stdlib.h>   /* rand / srand  */
#include <time.h>     /* time          */
#include <unistd.h>   /* usleep        */

const char *heart[] = {
    "     *****   *****     ",
    "   *******   *******   ",
    "  *******************  ",
    "***********************",
    " ********************* ",
    "  *******************  ",
    "   *****************   ",
    "    ***************    ",
    "     *************     ",
    "      ***********      ",
    "       *********       ",
    "        *******        ",
    "         *****         ",
    "          ***          ",
    "           *           "
};

const char *wishes[] = {
    "白头偕老", "百年好合", "永结同心",
    "早生贵子", "琴瑟和鸣", "举案齐眉"
};

void print_heart(int delay_ms)
{
    int n = sizeof(heart) / sizeof(heart[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", heart[i]);
        fflush(stdout);
        usleep(delay_ms * 1000);
    }
}

void type_text(const char *text, int delay_ms)
{
    int i = 0;
    while (text[i] != '\0')
    {
        unsigned char c = (unsigned char)text[i];
        int len = 1;
        if (c >= 0xF0)      len = 4;
        else if (c >= 0xE0) len = 3;
        else if (c >= 0xC0) len = 2;

        for (int k = 0; k < len && text[i + k] != '\0'; k++)
            putchar(text[i + k]);

        fflush(stdout);
        usleep(delay_ms * 1000);
        i += len;
    }
    printf("\n");
}

int main(void)
{
    srand((unsigned)time(NULL));   /* 拿当前时间当随机种子，每次跑都不一样 */

    print_heart(60);

    printf("\n        ");
    type_text("新婚快乐！", 120);
    printf("        ");
    type_text("愿你们：", 80);

    int count = sizeof(wishes) / sizeof(wishes[0]);
    int used[3] = {-1, -1, -1};    /* 记下已经抽过的下标 */
    int got = 0;                   /* 已经抽到几条 */

    while (got < 3)
    {
        int idx = rand() % count;  /* 0 ~ count-1 之间的随机整数 */
        int dup = 0;

        for (int k = 0; k < got; k++)   /* 查一下这次抽的是不是重复的 */
            if (used[k] == idx)
                dup = 1;

        if (dup)                       /* 重复就作废，重抽 */
            continue;

        used[got] = idx;
        got++;
        printf("        「%s」\n", wishes[idx]);
        usleep(200000);
    }

    return 0;
}
