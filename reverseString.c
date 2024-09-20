#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// reverse string
void reverseString(char *str);
int main() {
    
    // detramine len of str
    char *str = (char *) malloc(1*sizeof(char));
    int i = 0;
    while((str[i]=getchar()) != '\n'){
        i++;
        str= (char *)realloc(str, i*sizeof(char));
    }
    str[i]=0;
    printf("current string: %s\n",str);
    reverseString(str);
    printf("reversed string: %s\n",str);
    return 0;
}

void reverseString(char *str){
    char temp;
    int start=0;
    int end=strlen(str)-1;
    while(start<end){
        temp = str[start];
        str[start]= str[end];
        str[end]= temp;
        start++;
    }
    
}
