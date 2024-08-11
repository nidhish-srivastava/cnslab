
#include <stdio.h>
#include <string.h>
int main()
{
   unsigned int a[3][3] = {{6,24,1},{13,16,10},{20,17,15}};
   unsigned int b[3][3] = {{8,5,10},{21,8,21},{21,12,8}};
   int i,j;
   unsigned int c[20],d[20];
   char msg[20];
   int determinant=0,t=0;
   printf("Enter the plaintext : \n");
   scanf("%s",msg);
   for(int i=0;i<3;i++){
       c[i] = msg[i] - 65;
       printf("%d",c[i]);
   }
   for(int i=0;i<3;i++){
       t=0;
       for(int j=0;j<3;j++){
           t += a[i][j] * c[j];
       }
       d[i] = t%26;
   }
   printf("\n Encrypted cipher text : ");
   for(int i=0;i<3;i++){
       printf("%c",d[i] + 65);
   }
   
   for(int i=0;i<3;i++){
       t=0;
       for(int j=0;j<3;j++){
           t += b[i][j] * d[j];
       }
       c[i] = t%26;
   }
   
   printf("\n Decrypted cipher text : ");
   for(int i=0;i<3;i++){
       printf("%c",c[i] + 65);
   }
   return 0;
}

/*
DRY RUN
Enter the plaintext : 
SDG
1836
 Encrypted cipher text : EEH
 Decrypted cipher text : SDG
*/
