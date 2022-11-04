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
# include <math.h>
# include <limits.h>

# define EXIT_FAILURE    1

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/*
 * len : Vector real length
 * buff : Vector max size
 * esz : Element size
 */

typedef struct s_vector {
	void	*item;
	size_t	buff;
	size_t	len;
	size_t	esz;
} t_vector;

/*
**		check_case.c
** ---------------------------------
*/
int		ft_islower(int c);
int		ft_isupper(int c);

/*
**		check_char.c
** ---------------------------------
*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);

/*
**		compare.c
** ---------------------------------
*/
bool	ft_intncmp(int *t1, int *t2, size_t n);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_memcmp(void const *s1, void const *s2, size_t n);

/*
**		convert_char.c
** ---------------------------------
*/
int		ft_tolower(int c);
int		ft_toupper(int c);
long	ft_strtol(char const *str);
int		ft_atoi(char const *str);

/*
**		convert_num.c
** ---------------------------------
*/
void	ft_itoa(long n, int radix, char *buff);
int     ft_hextodeci(char *hex);

/*
**		copy.c
** ---------------------------------
*/
char	*ft_strcpy(char *dst, char *src);
void	*ft_memcpy(void *dst, void const *src, size_t n);
char	*ft_strdup(char const *s1);
size_t	ft_strlcpy(char *dest, char const *src, size_t dstsize);
char	*ft_strncpy(char *dst, char const *src, size_t n);

/*
**		join.c
** ---------------------------------
*/
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char const *s2);

/*
**		length.c
** ---------------------------------
*/
size_t	ft_strlen(char const *s);
int		ft_numlen(long n, int radix);
size_t	ft_count_words(char const *s, char c);

/*
**		memory
** ---------------------------------
*/
void	*ft_calloc(size_t count, size_t size);
void	*ft_malloc(void	*ptr, ssize_t esz);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_realloc(void *ptr, size_t size, size_t old_s);
char	**ft_freetab(char **s);

/*
**		put_.c
** ---------------------------------
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int radix, int fd);
void	ft_putulong_fd(unsigned long n, int radix, int fd);

/*
**		search.c
** ---------------------------------
*/
char	*ft_strchr(char const *s, int c);
void	*ft_memchr(void const *s, int c, size_t n);
char	*ft_strnstr(char const *haystack, char const *needle, size_t n);
void	*ft_memmove(void *dst, void const *src, size_t len);
char	*ft_strrchr(char const *s, int c);

/*
**		split.c
** ---------------------------------
*/
char	**ft_split(char const *s, char c);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
**		vector.c
** ---------------------------------
*/

t_vector *vector_init(size_t size);
void vector_append(t_vector *v, void *x);
void *free_vector(t_vector *v);

/*
**		FT_PRINTF
** ---------------------------------
*/
int		ft_printf(char const *format, ...);
int		ft_putstr_va_arg(va_list arg);
int		ft_putchar_va_arg(va_list arg);
int		ft_putnbr_va_arg(va_list arg);
int		ft_unsigned_va_arg(va_list arg);
int		ft_lowerhex_va_arg(va_list arg);
int		ft_upperhex_va_arg(va_list arg);
int		ft_print_address_va_arg(va_list arg);

/*
**		GET_NEXT_LINE
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