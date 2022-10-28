/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   union.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/26 17:01:12 by tmercier      #+#    #+#                 */
/*   Updated: 2022/03/07 19:16:41 by timotheemer   ########   odam.nl         */
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

void ft_union(char *s1, char *s2)
{
	int len = ft_strlen(s1) + ft_strlen(s2);

	char temp[len];
	int i;

	for (i = 0; s1[i]; i++)
		temp[i] = s1[i];
	for (int j = 0; s2[j]; i++, j++)
		temp[i] = s2[j];
	temp[i] = '\0';
	for (int i = 0; temp[i]; i++)
		if (!ft_check(temp, temp[i], i))
			write(1, &temp[i], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return 0;
}