/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:33:54 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/09 21:35:45 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <iostream>
# include <fstream>
# include <stdexcept>
# include <map>
# include <locale>
# include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string database, std::string fileInput);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange();

		BitcoinExchange	&operator=(BitcoinExchange const &rhs);

		void	parseDatabase();
		void	parseInput();

	private:
		std::ifstream	_database;
		std::ifstream	_fileInput;
		std::map<std::string, float> _dataMap;
};

#endif
