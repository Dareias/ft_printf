/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fillip <fillip@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:12:25 by fillip            #+#    #+#             */
/*   Updated: 2025/06/09 16:11:33 by fillip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*typedef struct s_format
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
} t_format;*/
 
//ft_printf("%cspdiuxX%")
void	parse_flag(t_format *f, const char **s)
{
	while (**s == '-' || **s == '+' || **s == ' ' || **s == '#' || **s =='0')
	{
		if (**s == '-') f->minus = 1;
		else if ( **s == '+') f->plus = 1;
		else if ( **s == ' ') f->space = 1;
		else if ( **s == '#') f->hash = 1;
		else if ( **s == '0') f->zero = 1;
		(*s)++;
	}
}

void	parse_width(t_format *f, const char **s, va_list args)
{
	if (**s == '*')
	{
		f->width = va_arg(args, int);
		(*s)++;
	}
	else if (*s >= '0' && *s <= '9')
	{
		f->width = ft_atoi(*s);
		while (*s >= '0' && *s <= '9')
			(*s)++;
	}
}

void	parse_prec(t_format *f, const char **s, va_list args)
{
	if (**s == '.')
	{
		f->dot = 1;
		*(s)++;
		if (**s == '*')
		{
			f->prec = va_arg(args, int);
			(*s)++;
		}
		else
		{
			f->prec = ft_atoi(*s);
			while (**s >= '0' && **s <= '9')
				(*s)++;
		}
	}
}

void	parse_len()
{
	
}

void	parse_spec()
{
	
}
