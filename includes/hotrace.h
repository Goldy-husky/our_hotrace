/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:48:37 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/15 01:43:41 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 100000
# define TABLESIZE 263167
# define ROTATE_X 0
# define ROTATE_Y 2

typedef uint32_t	t_hash;

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_keyword
{
	t_hash				key;
	char				*value;
	struct s_keyword	*next;
}					t_keyword;


/*
** CRC32
*/
typedef uint8_t		t_crc;

# define POLY 0xD8
# define WIDTH  (8 * sizeof(t_crc))
# define TOPBIT (1 << (WIDTH - 1))
# define REDUCE 5

void		hr_crc_init_32(t_crc *table);
t_hash		hr_crc32(char *str, int size, int rotate, t_bool reduce);
t_hash		 set_tab_len(int reduce);

void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
void		ft_strdel(char **as);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *src);
char		*ft_strcat(char *dst, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

int			get_next_line(int const fd, char **line);

char		*ft_strextend(char *s1, const char *s2);
int			gnl_from_stash(char *tmp, char **line, char **stash);
int			gnl_from_buf(char *buf, char *tmp, char **line, char **stash);
int			get_last_line(char **line, char **stash);
int			get_next_line(int const fd, char **line);

t_keyword	*hr_keyword_lstadd(t_keyword *keyword, t_hash key, char *value);
//void		hr_keyword_lstchg(t_keyword *keyword, t_hash, const char *value);
void		hr_keyword_lstdel(t_keyword *keyword);

int			hr_parseinput(char *str, int lines, t_keyword **table);

char		*hr_key_search(t_keyword *keyword, t_hash key);
void		hr_print(char *str, char *value);
void		hr_search(char *str, t_keyword **table, t_hash x, t_hash y);

#endif
