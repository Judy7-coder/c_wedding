#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
const char *heart[] = 
{
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
    "           *           ",
};

    const char *wishes[] = 
    {
        "白头偕老","百年好合","永结同心",
        "早生贵子","琴瑟和鸣","举案齐眉"
    };

void type_text(const char *text, int delay_ms)
{
    int i = 0;

    while(text[i] != '\0')
    {
        unsigned char c = (unsigned char)text[i];

        int len = 1;
        if (c >= 0xF0)      len = 4;
        else if (c >= 0xE0) len = 3;
        else if (c >= 0xC0) len = 2;

        for(int k = 0; k < len && text[i + k] != '\0'; k++)
            putchar(text[i + k]);

        fflush(stdout);
        usleep(delay_ms * 1000);
        i += len;
    }

    printf("\n");
}
void print_heart(int delay_ms)
{
    int n = sizeof(heart) / sizeof(heart[0]);

    for(int i = 0; i < n; i++)
    {
        printf("%s\n",heart[i]);
        fflush(stdout);
        usleep(delay_ms * 1000);
    }
}
int main(void)
{
    srand((unsigned)time(NULL));

    print_heart(80);

    type_text("新婚快乐！",150);
    type_text("愿你们：",80);

    int count = sizeof(wishes) / sizeof(wishes[0]);
    int used[3] = { -1, -1, -1};
    int got = 0;

    while(got < 3)
    {
        int idx = rand() % count;
        int dup = 0;

        for(int k = 0;k < got; k++)
           if(used[k] == idx)
              dup = 1;

        if (dup)
            continue;

        used[got] = idx;
        got++;
        printf("         「%s」\n",wishes[idx]);
        usleep(200000);
    }
    return 0;
}