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
//#include "libasm.a"

extern size_t ft_strlen(char const *str);




void	test_strlen(char *str)
{
	size_t	asm_strlen;
	size_t	c_strlen;

	asm_strlen = ft_strlen(str);
	c_strlen = 0;
	while (str[c_strlen] != '\0')
		c_strlen++;
	printf("\nString : %s\n", str);
	printf("ASM strlen : %zu - C strlen : %zu\n", asm_strlen, c_strlen);
}

int main(void)
{
	char	*str = "Hello World !";
	char	*str2 = "This is a test for ft_strlen.";

	printf("---------------\n---FT_STRLEN---\n---------------\n");
	test_strlen(str);
	test_strlen(str2);

	return 0;
}
