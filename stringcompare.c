
//Charles Letonnellier de Breteuil
//27296592

#include <stdio.h>
#include <stdbool.h>

_Bool twoStrgCompr(const char str1[], const char str2[]) {
    int counter=0;
while(str1[counter]!='\0' && str2[counter]!='\0'){
        if(str1[counter]<str2[counter]){
            return true;
        }
        else if(str1[counter]>str2[counter]){
            return false;
        }
    counter++;
    }
  return  str1[counter]=='\0'? true : false;

}
_Bool twoStrgCompr_pointer(char* str1, char* str2){
    while(*str1!= '\0' && *str2 != '\0'){
     if(*str1<*str2){
         return true;
     }
     else if (*str1>*str2){
         return false;
     }
     else {
         str1++;
         str2++;
     }
    }
   return  *str1=='\0'? true: false;
}
int main() {
    twoStrgCompr_pointer("abc","abcd")==true? printf("true"):printf("false");
    printf("\n");
    twoStrgCompr("abc","abcd")==true? printf("true"):printf("false");
    printf("\n");
    return 0;
}