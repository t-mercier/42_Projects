/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmercier <tmercier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/29 14:48:22 by tmercier      #+#    #+#                 */
/*   Updated: 2021/12/18 14:34:42 by tmercier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>

# define EXIT_FAILURE    1

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

/*
**		conversion
** ---------------------------------
*/
int		ft_tolower(int c);
int		ft_toupper(int c);
long	ft_strtol(const char *str);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	ft_itoa(long n, int radix, char *buff);

/*
**		int(char) check
** ---------------------------------
*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isupper(int c);

/*
**		memory
** ---------------------------------
*/
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	**free_doublearr(char **s);

/*
**		numeric
** ---------------------------------
*/
int		ft_nbrlen(long n, int radix);
bool	ft_intncmp(int *t1, int *t2, size_t n);

/*
**		print to fd
** ---------------------------------
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int radix, int fd);
void	ft_putulong_fd(unsigned long n, int radix, int fd);

/*
**		string manipulation
** ---------------------------------
*/
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, char *src);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
**		printf
** ---------------------------------
*/
int		ft_printf(const char *format, ...);
int		ft_putstr_va_arg(va_list arg);
int		ft_putchar_va_arg(va_list arg);
int		ft_putnbr_va_arg(va_list arg);
int		ft_unsigned_va_arg(va_list arg);
int		ft_lowerhex_va_arg(va_list arg);
int		ft_upperhex_va_arg(va_list arg);
int		ft_print_address_va_arg(va_list arg);

/*
**		get next line
** ---------------------------------
*/
char	*ft_get_line(char *line, char *buff);
char	*get_next_line(int fd);
char	*ft_free(char **tmp, int line);

/*
** DEPRECATED
** ---------------------------------
*/
static inline void	ft_bzero(void *s, size_t len)
{
	ft_memset((s), '\0', (len));
}

#endif 