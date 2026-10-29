/* 第 2 步：让它说话有停顿（故意写得笨，为了让你感到"重复很烦"） */
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("新");
    fflush(stdout);
    usleep(200000);

    printf("婚");
    fflush(stdout);
    usleep(200000);

    printf("快");
    fflush(stdout);
    usleep(200000);

    printf("乐");
    fflush(stdout);
    usleep(200000);

    printf("！\n");
    return 0;
}
