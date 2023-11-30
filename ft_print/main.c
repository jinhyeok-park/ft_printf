#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

int main()
{
    //ft_printf("%d\n" ,ft_printf("%c\n", '0'));
    //printf("%d\n", printf("orig : %c %c %c \n", '0', 0, '1'));
    //printf ("this is print %d" , printf("%c%c%c\n", 0, 0, 0));
    
    ft_printf("%d\n", ft_printf("%cc%cc%c", 'a', '\t', 'b'));


    
    printf("%d\n" , printf("%cc%cc%c", 'a', '\t', 'b'));
    int j =  printf("this is test");
    //printf("%d" ,j );
    //printf("%d" , 0);
    // char *str = (char *)malloc(sizeof(char) * INT_MAX + 1);
	// if (!str)
	// 	return (0);
	// memset(str, 97, INT_MAX);
	// str[INT_MAX] = '\0';
    // printf("%lu", strlen(str));
	// //printf("%d\n", printf("%s", str));
	// printf("%d\n", ft_printf("%s", str));
	return (0);
}