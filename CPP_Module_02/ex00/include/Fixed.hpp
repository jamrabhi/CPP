/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:26:24 by jamrabhi          #+#    #+#             */
/*   Updated: 2023/07/12 00:26:29 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		int	getRawBits( void ) const;
		int	setRawBits( void ) const;

	private:
		int					_fixedValue;
		static const int	_fractBits;
};

#endif
