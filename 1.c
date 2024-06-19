#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Hello World";
    printf("Original string %s",str);
    int len = strlen(str);
    printf("After applying AND operation : \n");
    for(int i=0;i<len;i++){
        printf("%c = %c\n",str[i],str[i]&127);
    }
    printf("After applying OR operation : \n");
    for(int i=0;i<len;i++){
        printf("%c = %c\n",str[i],str[i]|127);
    }
    printf("After applying XOR operation : \n");
    for(int i=0;i<len;i++){
        printf("%c = %c\n",str[i],str[i]^127);
    }
    return 0;
}