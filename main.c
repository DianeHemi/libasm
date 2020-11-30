/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dchampda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:45:42 by user42            #+#    #+#             */
/*   Updated: 2020/11/04 14:45:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
//#include "libasm.a"

extern size_t 	ft_strlen(char const *str);
extern char 	*ft_strcpy(char *dest, char const *str);
extern int		ft_strcmp(char *s1, char *s2);

void	test_ft_strcmp(char *s1, char *s2)
{
	printf("S1 : %s -- S2 : %s\n", s1, s2);
	printf("C Diff : '%d' -- ASM diff : '%d'\n\n", strcmp(s1, s2), ft_strcmp(s1, s2));
}

void	test_ft_strcpy(char *dest, const char *src)
{
	printf("Src : %s -- Len : %ld\n", src, strlen(src));
	printf("ASM : %s", ft_strcpy(dest, src));
	printf(" -- Len : %ld\n\n", strlen(dest));
}

void	test_strlen(char *str)
{
	size_t	c_strlen;

	c_strlen = 0;
	while (str[c_strlen] != '\0')
		c_strlen++;
	printf("\nString : %s\n", str);
	printf("ASM strlen : %zu - C strlen : %zu\n", ft_strlen(str), c_strlen);
}

int main(void)
{
	char	*str = "Hello World !";
	char	*str1 = "Hallo Welt !";
	char	*str2 = "Thus begin the age of fire, and with fire, came disparity.";
	char	*str3 = "";
	char	var_strcpy[60];

	printf("---------------\n---FT_STRLEN---\n---------------\n");
	test_strlen(str);
	test_strlen(str1);
	test_strlen(str2);
	test_strlen(str3);

	printf("\n\n----------------\n---FT_STRCPY---\n----------------\n\n");
	test_ft_strcpy(var_strcpy, str);
	test_ft_strcpy(var_strcpy, str1);
	test_ft_strcpy(var_strcpy, str2);
	test_ft_strcpy(var_strcpy, str3);

	printf("\n---------------\n---FT_STRCMP---\n---------------\n\n");
	test_ft_strcmp(str, str);
	test_ft_strcmp(str, str1);
	test_ft_strcmp(str1, str);
	test_ft_strcmp(str2, str1);
	test_ft_strcmp(str3, str2);
	test_ft_strcmp(str1, str3);

	//printf("\n---------------\n---FT_WRITE---\n---------------\n\n");
	//printf("\n----------------\n---FT_READ---\n----------------\n\n");
	//printf("\n---------------\n---FT_STRDUP---\n---------------\n\n");

	return 0;
}
