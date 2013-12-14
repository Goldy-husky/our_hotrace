/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:48:37 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/14 06:06:42 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "get_next_line.h"

# define TABLESIZE 263167
# define ROTATE_X 5
# define ROTATE_Y 2


typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_keyword
{
	unsigned int		key;
	char				*value;
	struct s_keyword	*next;
}				t_keyword;


/*
** CRC32
*/
typedef uint8_t	t_crc;
# define POLY 0xD8
# define WIDTH  (8 * sizeof(crc))
# define TOPBIT (1 << (WIDTH - 1))


t_keyword	*hr_keyword_lstadd(t_keyword *keyword, int key, const char *value);
void		hr_keyword_lstchg(t_keyword *keyword, int key, const char *value);
void		hr_keyword_lstdel(t_keyword *keyword);

#endif
