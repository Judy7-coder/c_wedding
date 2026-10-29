/* 第 4 步：把循环包进函数（第 5 章核心），同时修好中文 */
#include <stdio.h>
#include <unistd.h>

/* 函数：逐字打印一段文字
   参数 1：text     —— 要打的字，const char * 表示"只读的字符串"
   参数 2：delay_ms —— 每个字之间停多少毫秒
   返回值：void     —— 不返回任何东西，只干活 */
void type_text(const char *text, int delay_ms)
{
    int i = 0;

    while (text[i] != '\0')
    {
        unsigned char c = (unsigned char)text[i];
        int len = 1;                  /* 这个字占几个字节 */
        if (c >= 0xF0)      len = 4;  /* emoji */
        else if (c >= 0xE0) len = 3;  /* 汉字 */
        else if (c >= 0xC0) len = 2;  /* 带音标的字母 */

        for (int k = 0; k < len && text[i + k] != '\0'; k++)
            putchar(text[i + k]);     /* 整组一次打出去，不劈开 */

        fflush(stdout);
        usleep(delay_ms * 1000);      /* 毫秒 -> 微秒 */
        i += len;                     /* 直接跳过整个字 */
    }

    printf("\n");
}

int main(void)
{
    type_text("新婚快乐！", 150);
    type_text("百年好合", 150);
    type_text("Happy Wedding!", 80);
    return 0;
}
