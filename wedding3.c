/* 版本 3：把动作拆成函数 + 随机祝福语（第 5 章函数的实战） */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static const char *HEART[] = {
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

static const char *WISHES[] = {
    "白头偕老", "百年好合", "永结同心",
    "早生贵子", "琴瑟和鸣", "举案齐眉"
};

/* 函数 1：画心，参数是每行间隔多少毫秒 */
void print_heart(int delay_ms)
{
    int n = sizeof(HEART) / sizeof(HEART[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", HEART[i]);
        fflush(stdout);
        usleep(delay_ms * 1000);
    }
}

/* 函数 2：一个字一个字往外打，像打字机。
   注意：UTF-8 里一个汉字占 3 个字节，char 走的是字节不是字，
   所以必须先算出这个字占几字节，整组打出去，否则会把汉字劈成两半。 */
void type_text(const char *text, int delay_ms)
{
    int i = 0;
    while (text[i] != '\0')
    {
        unsigned char c = (unsigned char)text[i];
        int len = 1;                       /* 默认 1 字节，即 ASCII */
        if (c >= 0xF0) len = 4;            /* 4 字节：emoji 等 */
        else if (c >= 0xE0) len = 3;       /* 3 字节：汉字 */
        else if (c >= 0xC0) len = 2;       /* 2 字节：拉丁扩展 */

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
    srand((unsigned)time(NULL));              /* 用当前时间做随机种子 */

    print_heart(60);

    printf("\n");
    printf("        ");
    type_text("新婚快乐！", 120);
    printf("        ");
    type_text("愿你们：", 80);

    int count = sizeof(WISHES) / sizeof(WISHES[0]);
    int used[3] = {-1, -1, -1};
    int got = 0;

    while (got < 3)                           /* 抽 3 条不重复的 */
    {
        int idx = rand() % count;
        int dup = 0;
        for (int k = 0; k < got; k++)
            if (used[k] == idx) dup = 1;
        if (dup) continue;

        used[got] = idx;
        got++;
        printf("        「%s」\n", WISHES[idx]);
        usleep(200000);
    }

    return 0;
}
