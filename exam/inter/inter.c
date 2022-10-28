/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/26 17:03:57 by tmercier      #+#    #+#                 */
/*   Updated: 2022/02/26 18:08:41 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i++]);
	return i;
}

int ft_check(char *s, char c, int len)
{
	for (int i = 0; i < len; i++)
		if (s[i] == c)
			return 1;
	return 0;
}

void ft_inter(char *s1, char *s2)
{
	int len = ft_strlen(s2);
	for (int i = 0; s1[i]; i++)
		if (ft_check(s2, s1[i], len) == 1)
			if (ft_check(s1, s1[i], i) == 0)
				write(1, &s1[i], 1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return 0;
}
