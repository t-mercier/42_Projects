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

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define EXIT_FAILURE 1

# define RED "\x1b[31m"
# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define NORMAL "\x1b[m"

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/*
**			check_case.c
** ------------------------------------------ */
int		ft_islower(int c);
int		ft_isupper(int c);

/*
**			check_char.c
** ------------------------------------------ */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);

/*
**			check_bool.c
** ------------------------------------------ */
bool	is_negative(int n);
bool	is_space(int c);
bool	char_is_found(int c, char const *s);

/*
**			compare.c
** ------------------------------------------ */
bool	ft_intncmp(int *t1, int *t2, size_t n);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_memcmp(void const *s1, void const *s2, size_t n);

/*
**			convert_char.c
** ------------------------------------------ */
int		ft_tolower(int c);
int		ft_toupper(int c);
long	ft_strtol(char const *str);
int		ft_atoi(char const *str);

/*
**			convert_num.c
** ------------------------------------------ */
void	ft_itoa_str(long n, int radix, char *str);
char	*ft_itoa(long n, int radix);
int		ft_hextodeci(char *hex);

/*
**			copy.c
** ------------------------------------------ */
char	*ft_strcpy(char *dst, char *src);
void	*ft_memcpy(void *dst, void const *src, size_t n);
char	*ft_strdup(char const *s1);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
char	*ft_strncpy(char *dst, char const *src, size_t n);

/*
**			errors.c
** ------------------------------------------ */
void	exit_message(char *s, int code);
bool	ft_error_va(char *errmsg, ...);

/*
**			free.c
** ------------------------------------------ */
void	ft_free_2d_array(char **s);

/*
**			join.c
** ------------------------------------------ */
size_t	ft_strlcat(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char const *s2);

/*
**			length.c
** ------------------------------------------ */
size_t	ft_strlen(char const *s);
int		ft_numlen(long n, int radix);
size_t	ft_count_words(char const *s, char c);

/*
**			memory
** ------------------------------------------ */
void	*ft_calloc(size_t count, size_t size);
void	*ft_malloc(size_t esz);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_realloc(void *ptr, size_t size, size_t old_s);
void	ft_bzero(void *s, size_t len) __attribute__((deprecated));

/*
**			put_.c
** ------------------------------------------ */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int radix, int fd);
void	ft_putulong_fd(unsigned long n, int radix, int fd);

/*
**			search.c
** ------------------------------------------ */
char	*ft_strchr(char const *s, int c);
void	*ft_memchr(void const *s, int c, size_t n);
char	*ft_strnstr(char const *hs, char const *tofind, size_t n);
void	*ft_memmove(void *dst, void const *src, size_t len);
char	*ft_strrchr(char const *s, int c);

/*
**			split.c
** ------------------------------------------ */
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
**			split.c
** ------------------------------------------ */
long	tern_long(int condition, long _true, long _false);
int		tern_int(int condition, int _true, int _false);
size_t	tern_size_t(int condition, size_t _true, size_t _false);
char	tern_char(int condition, char _true, char _false);
char	*tern_str(int condition, char *_true, char *_false);

/*
**			FT_PRINTF
** ------------------------------------------ */
int		ft_printf(char const *format, ...);
int		ft_putstr_va_arg(va_list arg);
int		ft_putchar_va_arg(va_list arg);
int		ft_putnbr_va_arg(va_list arg);
int		ft_unsigned_va_arg(va_list arg);
int		ft_lowerhex_va_arg(va_list arg);
int		ft_upperhex_va_arg(va_list arg);
int		ft_print_address_va_arg(va_list arg);

/*
**			GET_NEXT_LINE
** ------------------------------------------ */
char	*ft_get_line(char *line, char *buff);
char	*get_next_line(int fd);

#endif
