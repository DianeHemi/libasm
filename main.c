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
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

extern size_t 	ft_strlen(char const *str);
extern char 	*ft_strcpy(char *dest, char const *str);
extern int		ft_strcmp(char *s1, char *s2);
extern void		ft_write(int fd, char *str, int len);
extern void		ft_read(int fd, char *str, int len);
extern	char	*ft_strdup(const char *str);

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
	char	*str4 = "Oh yes; but one is never so pretty after being mended, you know.";
	char	var_strcpy[60];
	char 	*to_read;
	int fd;

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


	printf("\n---------------\n---FT_WRITE---\n---------------\n\n");

	printf("Write in stdout : \n\n");
	printf("printf : %s\n", str4);
	ft_write(1, "ft_write : ", 11);
	ft_write(1, str4, ft_strlen(str4));
	ft_write(1, "\n\n", 2);
	printf("printf : %s\n", str2);
	ft_write(1, "ft_write : ", 11);
	ft_write(1, str2, ft_strlen(str2));
	ft_write(1, "\n\n", 2);
	printf("printf : %s\n", str1);
	ft_write(1, "ft_write : ", 11);
	ft_write(1, str1, ft_strlen(str1));
	ft_write(1, "\n\n", 2);
	printf("printf : %s\n", str3);
	ft_write(1, "ft_write : ", 11);
	ft_write(1, str3, ft_strlen(str3));
	ft_write(1, "\n", 1);

	printf("\n-----\n\n");

	fd = open("./example.txt", O_RDWR|O_CREAT, 0766);  //O-APPEND to add instead
	printf("To write in file 'example.txt' : \n\n%s%s\n%s\n%s\n", "Hello\n", str2, str4, str3);
	ft_write(fd, "Hello\n", 6);
	ft_write(fd, str2, ft_strlen(str2));
	ft_write(fd, "\n", 1);
	ft_write(fd, str4, ft_strlen(str4));
	ft_write(fd, "\n", 1);
	ft_write(fd, str3, ft_strlen(str3));
	ft_write(fd, "\n", 1);
	close(fd);


	printf("\n-----------------\n-----FT_READ-----\n-----------------\n\n");
	printf("Read 120 characters from file 'example.txt' : \n\n");
	to_read = malloc(sizeof(char) * 121);
	fd = open("./example.txt", O_RDONLY);
	ft_read(fd, to_read, 120);
	ft_write(1, to_read, 120);
	to_read[120] = '\0';
	ft_write(1, "\n", 1);
	printf("\nLen : %ld\n", strlen(to_read));
	free(to_read);

	printf("\n-----");

	printf("\n\nRead 14 characters from file 'ft_write.s' : \n\n");
	to_read = malloc(sizeof(char) * 15);
	fd = open("./ft_write.s", O_RDONLY);
	ft_read(fd, to_read, 14);
	ft_write(1, to_read, 14);
	to_read[14] = '\0';
	printf("\nLen : %ld\n", strlen(to_read));
	free(to_read);


	printf("\n---------------\n---FT_STRDUP---\n---------------\n\n");
	char	*dup1; 

	dup1 = ft_strdup(str);
	printf("Expected : %s\nResult : %s\n\n", str, dup1);
	free(dup1);
	dup1 = ft_strdup(str2);
	printf("Expected : %s\nResult : %s\n\n", str2, dup1);
	free(dup1);
	dup1 = ft_strdup(str4);
	printf("Expected : %s\nResult : %s\n\n", str4, dup1);
	free(dup1);
	dup1 = ft_strdup("");
	printf("Expected : %s\nResult : %s\n\n", "", dup1);
	free(dup1);
	dup1 = ft_strdup("Thought you could outwit an onion ?");
	printf("Expected : %s\nResult : %s\n\n", "Thought you could outwit an onion ?", dup1);
	free(dup1);

	return 0;
}
