#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
//p:48  �ַ���������ʹ�ú�����
//���ַ�������
//size_t  strlen();  //�����޷����� unsigned int

//���Ȳ������Ƶ��ַ�������
//char*  strcpy(); //��dest����ʼλ��
//char* strcat();
//strcmp(); //�Ƚ��ַ���

//���������Ƶ��ַ�������
//strncpy();
//strncat();
//strncmp()

//�ַ�������
//strstr(); //�����ִ�
//strtok(); //���շָ��� ���зָ��ַ���

//������Ϣ����
//strerror(); ���ش����� ��Ӧ�Ĵ�����Ϣ

//�ַ���������

//�ڴ��������
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
    //\0��ASSCI����Ϊ0
    if (*str != '\0') {
        return 1 + my_strlen3(str + 1);
    } else {
        return 0;
    }
}

//��src cpy��dest��
//���ִ���
char *my_strcpy(char *dest, const char *src) {
//    while (*src != '\0') {
//        *dest = *src;
//        src++;
//        dest++;
//        *dest++ = *src++;
//    }
    //�����ַ�
//    *dest = *src; //cpy \0�ַ�

    assert(dest != NULL);
    assert(src != NULL);
    char *ret = dest;
//���д�� ���\0ҲŪ��ȥ
    while (*dest++ = *src++) {

    }
    //���� dest����ʼ��ַ
    return ret;
}

char *my_strcat(char *dest, const char *src) {
    assert(dest && src);
    char *ret = dest;
    //1:�ҵ�Ŀ�ĵ� \0��λ�ã�׷�ӵ�\0
    while (*dest != '\0') {
        dest++; //ָ��++
    }
    //2:׷�� ��ʵ����strcpy()��
    while (*dest++ = *src++) {
    }
    return ret;

}

char *my_strncpy(char *dest, const char *src, int width) {
    char *ret = dest;

    while (width && (*dest++ = *src++)) {
        //copy  string
        width--;  //���ٴ�copy���ַ�
    }
    //�ַ��� �Ѿ���ɣ� ����\0
    if (width)
        while (--width)
            *dest++ = '\0';

    return ret;
}

int my_strcmp(const char *str1, const char *str2) {
    //�Ƚ� �����ͬ  ����һ��
    while (*str1 == *str2) {
        //abcdef\0
        //abcdef\0
        //str��\0 ˵�� str2 Ҳ��\0
        if (*str1 == '\0') {
            //��ͬ
            return 0;
        }
        str1++;
        str2++;
    }
    //abc def
    //abc eee
    //����ͬ�� ȷ����С
    if (*str1 > *str2) {
        return 1;
    } else {
        //С��
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
    //  bbc  //����src
    while (*cur) {
        s1 = cur; //����ָ��Ϊ��ǰָ���λ�� ƥ��ʧ�ܻص�ָ��
        s2 = sub; //ÿһ����ƥ�䶼ָ���ִ��Ŀ�ͷλ��
        //����Ҫ�� �ҵ���ͬ��ͷ���ִ��� ��Ҫ��һ���ж�
                    while ((*s1 != '\0') && (*s1 == *s2) && (*s2 != '\0')) {
                        s1++;
                        s2++;
                    }
                    //s2ƥ�����
                    if (*s2 == '\0') {
                        return cur;
                    }
        //������һ���ַ�����ƥ��ʱ��cur �ǲ����ģ������ͷ ����ƥ���ַ���
        cur++;
    }
    return NULL;

}


int main() {
//    int len = my_strlen3("abcdef\0");

//    printf("%d",len);

    //strlen()�ķ���ֵ���� size_t
    //size_t == unsigned int �޷�������
    //�����޷�������� ���Ϊ�޷�����(����)  �ڴ�Ĳ���洢ʱ�� �϶���һ������0����
//    if(strlen("abcd") - strlen("abcedef") > 0)
//    {
//        printf("haha \n"); //����0
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

//��ͬ�ı����� ���صĽ����ͬ
//    if (my_strcmp(arr1, arr2) > 0) {
//        printf(">");
//    } else {
//        printf("<");
//    }


    //����ָ���ֽڵ��ַ���  ����ʱ ��\0
    //my_strncpy(arr1, arr2, 5);


    //strncat ֻ׷��ָ���ֽڵ��ַ����� �����Ȳ���ʱ ����
//    strncat(arr1,arr2,6);


//    const char *p1 = "abcdef";
//    const char *p2 = "def";

//    int ret = strcmp(p1,p2);
//    int ret = strncmp(p1,p2,3);  //�Ƚ�ָ���ַ����ַ���   0����ͬ       >���ش���1������       <����һ��С��0������

//    printf("%d",ret);

//    char *ret = my_strstr(p1, p2);  //��p1�в���p2
//
//    if (ret == NULL) {
//        printf("no");
//    } else {
//        printf("Yes");
//    }


    //���ʮ���Ƶı�ʾ��ʽ
//    char arr[] = "192.168.213.21";
//    char *sep = ".";
//
//    char buf[1024] = {0};
//    strcpy(buf, arr);

    //�и�buf�е��ַ���
    //strtok()�� ����ǰλ�ø�Ϊ\0�������ص�ǰ�ָ����λ�ã����û�з���NULL
//    char* ret = strtok(arr,sep);  //192
//    printf("%s\n",ret);
//
//    ret = strtok(NULL,sep);
//    printf("%s\n",ret);


//    char *ret = NULL;
//    //ʹ��forѭ�� ������ ��ʼ������
//    for (ret = strtok(buf, sep); ret != NULL; ret = strtok(NULL, sep)) {
//        printf("%s\n", ret);
//    }


    //errno��һ��ȫ�ִ���ı���
    //��c���ԵĿ⺯����ִ�й����з����˴��󣬾ͻ���ж�Ӧ�Ĵ����룬��ֵ��errno��
//    char *str = strerror(3); //���ص�ǰ���������Ϣ
    //����c���Կ⺯��ִ��ʱ�Ĵ������Ӧ����Ϣ

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
