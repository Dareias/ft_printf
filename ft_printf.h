/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fillip <fillip@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:41:25 by fillip            #+#    #+#             */
/*   Updated: 2025/06/04 07:48:47 by fillip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
#include "libft.h"

typedef struct s_format
{
	char	type;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		dot;
	int		prec;
} t_format;

typedef struct s_spec
{
	char	spec;
	int (*printer)(va_list, t_format *);
}	t_spec;

int	ft_printf(const char *format, ...);

void	parse_flag(t_format *f, const char **s);
void	parse_width(t_format *f, const char **s, va_list args);
void	parse_prec(t_format *f, const char **s, va_list args);

int	print_char(va_list args, t_format *f);
int	print_str(va_list args, t_format *f);
int	print_ptr(va_list args, t_format *f);
int	print_num(va_list args, t_format *f);
int print_uns(va_list args, t_format *f);
int print_lhex(va_list args, t_format *f);
int print_uhex(va_list args, t_format *f);
int print_perc(va_list args, t_format *f);

#endif