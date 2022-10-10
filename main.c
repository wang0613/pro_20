#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
//p:48  字符串函数的使用和剖析
//求字符串长度
//size_t  strlen();  //返回无符号数 unsigned int

//长度不受限制的字符串长度
//char*  strcpy(); //返dest的起始位置
//char* strcat();
//strcmp(); //比较字符串

//长度受限制的字符串长度
//strncpy();
//strncat();
//strncmp()

//字符串查找
//strstr(); //查找字串
//strtok(); //按照分隔符 进行分割字符串

//错误信息报告
//strerror(); 返回错误码 对应的错误信息

//字符操作函数

//内存操作函数
//memcpy();
//memmove();
//memset();
//memcmp();

int my_strlen1(const char *str) {
    int count = 0;
    assert(str != NULL);
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int my_strlen2(char *str) {
    char *start = str;
    char *end = str;
    while (*end != '\0') {
        end++;
    }
    return end - start;

}

int my_strlen3(char *str) {
    //\0的ASSCI编码为0
    if (*str != '\0') {
        return 1 + my_strlen3(str + 1);
    } else {
        return 0;
    }
}

//将src cpy到dest中
//满分代码
char *my_strcpy(char *dest, const char *src) {
//    while (*src != '\0') {
//        *dest = *src;
//        src++;
//        dest++;
//        *dest++ = *src++;
//    }
    //结束字符
//    *dest = *src; //cpy \0字符

    assert(dest != NULL);
    assert(src != NULL);
    char *ret = dest;
//最简写法 会把\0也弄进去
    while (*dest++ = *src++) {

    }
    //返回 dest的起始地址
    return ret;
}

char *my_strcat(char *dest, const char *src) {
    assert(dest && src);
    char *ret = dest;
    //1:找到目的地 \0的位置，追加到\0
    while (*dest != '\0') {
        dest++; //指针++
    }
    //2:追加 其实就是strcpy()；
    while (*dest++ = *src++) {
    }
    return ret;

}

char *my_strncpy(char *dest, const char *src, int width) {
    char *ret = dest;

    while (width && (*dest++ = *src++)) {
        //copy  string
        width--;  //减少待copy的字符
    }
    //字符串 已经完成， 补充\0
    if (width)
        while (--width)
            *dest++ = '\0';

    return ret;
}

int my_strcmp(const char *str1, const char *str2) {
    //比较 如果相同  找下一个
    while (*str1 == *str2) {
        //abcdef\0
        //abcdef\0
        //str是\0 说明 str2 也是\0
        if (*str1 == '\0') {
            //相同
            return 0;
        }
        str1++;
        str2++;
    }
    //abc def
    //abc eee
    //不相同， 确定大小
    if (*str1 > *str2) {
        return 1;
    } else {
        //小于
        return -1;
    }


}

char *my_strstr(const char *src, const char *sub) {
    assert(src && sub);
    char *s1 = NULL;
    char *s2 = NULL;
    char *cur = src;
    if (*sub == '\0') {
        return src;
    }
    //abbbcdef
    //  bbc  //遍历src
    while (*cur) {
        s1 = cur; //调整指针为当前指向的位置 匹配失败回调指针
        s2 = sub; //每一重新匹配都指向字串的开头位置
        //符合要求 找到相同开头的字串， 需要进一步判断
                    while ((*s1 != '\0') && (*s1 == *s2) && (*s2 != '\0')) {
                        s1++;
                        s2++;
                    }
                    //s2匹配完毕
                    if (*s2 == '\0') {
                        return cur;
                    }
        //当进行一组字符尝试匹配时，cur 是不动的，方便回头 重新匹配字符串
        cur++;
    }
    return NULL;

}


int main() {
//    int len = my_strlen3("abcdef\0");

//    printf("%d",len);

    //strlen()的返回值就是 size_t
    //size_t == unsigned int 无符号整形
    //两个无符号数相间 结果为无符号数(负数)  内存的补码存储时候 肯定是一个大于0的数
//    if(strlen("abcd") - strlen("abcedef") > 0)
//    {
//        printf("haha \n"); //大于0
//    }else
//    {
//        printf("hehe \n");
//    }

//
//    char arr1[] = "abc\0iiiiii";
//    char arr2[] = "aba";

//    my_strcpy(arr1, arr2);
//    printf("%s\n", arr1);
//    printf("%s\n", arr2);

//    my_strcat(arr1, arr2);
//    printf("%s\n", arr1);

//不同的编译器 返回的结果不同
//    if (my_strcmp(arr1, arr2) > 0) {
//        printf(">");
//    } else {
//        printf("<");
//    }


    //拷贝指定字节的字符串  不够时 补\0
    //my_strncpy(arr1, arr2, 5);


    //strncat 只追加指定字节的字符串， 当长度不够时 不管
//    strncat(arr1,arr2,6);


//    const char *p1 = "abcdef";
//    const char *p2 = "def";

//    int ret = strcmp(p1,p2);
//    int ret = strncmp(p1,p2,3);  //比较指定字符的字符串   0：相同       >返回大于1的数字       <返回一个小于0的数字

//    printf("%d",ret);

//    char *ret = my_strstr(p1, p2);  //在p1中查找p2
//
//    if (ret == NULL) {
//        printf("no");
//    } else {
//        printf("Yes");
//    }


    //点分十进制的表示方式
//    char arr[] = "192.168.213.21";
//    char *sep = ".";
//
//    char buf[1024] = {0};
//    strcpy(buf, arr);

    //切割buf中的字符串
    //strtok()： 将当前位置改为\0，并返回当前分割符的位置，如果没有返回NULL
//    char* ret = strtok(arr,sep);  //192
//    printf("%s\n",ret);
//
//    ret = strtok(NULL,sep);
//    printf("%s\n",ret);


//    char *ret = NULL;
//    //使用for循环 巧妙解决 初始化部分
//    for (ret = strtok(buf, sep); ret != NULL; ret = strtok(NULL, sep)) {
//        printf("%s\n", ret);
//    }


    //errno是一个全局错误的变量
    //当c语言的库函数在执行过程中发生了错误，就会把中对应的错误码，赋值到errno中
//    char *str = strerror(3); //返回当前错误码的信息
    //返回c语言库函数执行时的错误码对应的信息

    //0:No error
    //1:Operation not permitted
    //2:No such file or directory
    //3:No such process
    //.........
//    FILE* pf = fopen("test.txt","D:\\");
//    if(pf == NULL)
//    {
//        printf("%s\n", strerror(errno));  //No such file or directory      Invalid argument
//    }else
//    {
//        printf("open this file success!!");
//    }





    char arr[] = "I AM A STUDENT";
    int i = 0;
    while (arr[i])
    {
        if(isupper(arr[i]))
        {
            arr[i] = tolower(arr[i]);
        }
        i++;
    }
    printf("%s\n", arr);

    return 0;
}
