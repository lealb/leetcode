#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *longestCommonPrefix_0(char **strs, int strsSize)
{
    if (0 == strsSize)
    {
        return "";
    }
    char *prefix = strs[0];
    // strstr 返回字串的首地址
    //获得字串的第一个字符的首地址
    for (int i = 0; i < strsSize; i++)
    {
        // 没有考虑到["c","acc","ccc"]
        while (0 == strstr(strs[i], prefix))
        {
            int preLength = strlen(prefix);
            char *subch = (char *)calloc(sizeof(char), preLength + 1);
            strncpy(subch, prefix, preLength-1);
            prefix = subch;
        }
    }
    return prefix;
}

int main(int argc, char const *argv[])
{
    // ["c","acc","ccc"]
    char *strs[3] = {"flower", "flow", "flight"};
    printf(longestCommonPrefix_0(strs, 3));
    // printf("%d", strpbrk("flower", "fles"));
    return 0;
}
