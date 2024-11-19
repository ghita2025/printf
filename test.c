// #include <stdio.h>
// #include <unistd.h>
// int main() {
//     // int binary = 0b1010;  // Binary (GNU C extension)
//     // int octal = 012;      // Octal
//     // int hex = 0xA;        // Hexadecimal

//     // printf("Binary (0b1010): %i\n", binary);
//     // printf("Octal (012): %i\n", octal);
//   //
//   //  printf("Hexadecimal (0xA): %\n",0xabc);
// int a = 5;
//   int *p =NULL;
//   int b=printf("%p\n",p);
//   printf("%d\n",b);
//  //int c= printf("\n");
//  //printf("%d",c);
//     printf("%d",write(1,"(nil)",6));
// }

#include <stdio.h>

int main()
{
    int a = 67153365;
    printf("%d\t%i\t%u\t%c\t%s\t%u\t%x\t%X\n",a, a, -a ,a-67153300, "ghita", &a, a, a);

    return 0;
}