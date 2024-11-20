// #include <stdio.h>
// #include <unistd.h>
// int main() {
    // int binary = 0b1010;  // Binary (GNU C extension)
    // int octal = 012;      // Octal
    // int hex = 0xA;        // Hexadecimal

    // printf("Binary (0b1010): %i\n", binary);
    // printf("Octal (012): %i\n", octal);
  //
  //  printf("Hexadecimal (0xA): %\n",0xabc);
// int a = 5;
//   int *p =NULL;
//   int b=printf("%p\n",p);
//   printf("%d\n",b);
//  //int c= printf("\n");
//  //printf("%d",c);
//     printf("%ld",write(1,"(nil)",5));
// }

#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"
int main()
{
   int len;
   int len2;
   unsigned int ui;
   void *addr;

len = printf("lets try to printf a simple sentence .\n");
len2= ft_printf("lets try to printf a simple sentence .\n");
ui = (unsigned int)INT_MAX +1024;
addr = (void *)0x7ffe637541f0;
printf("length : [ %d, %i]\n", len , len);
ft_printf("length : [ %d, %i]\n", len , len);
printf("negative : [ %d ]\n",-762534);
ft_printf("negative : [ %d ]\n",-762534);
printf("unsigned : [ %u ]\n",ui);
ft_printf("unsigned : [ %u ]\n",ui);
printf("unsigned hexadecimal : [%x  , %X ]\n",ui,ui);
ft_printf("unsigned hexadecimal : [%x  , %X ]\n",ui,ui);
printf(" caracter : [ %c ]\n",'H');
ft_printf(" caracter : [ %c ]\n",'H');

printf(" string  : [ %s ]\n"," i am a string ");
ft_printf(" string  : [ %s ]\n"," i am a string ");

printf(" adress : [ %p ]\n",addr);
ft_printf(" adress : [ %p ]\n",addr);
len = printf("percent:[%%]\n");
len2 =ft_printf("percent:[%%]\n");
printf("len:[%d]\n",len);
ft_printf("len:[%d]\n",len2);

//printf(" unknown :[%r]")
    return 0;
}