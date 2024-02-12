/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:33:54 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/12 22:16:27 by jamrabhi         ###   ########.fr       */
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

	private:
		void	parseDatabase();
		void	parseInput();
		void	checkInput(std::string line);
		void	checkValue(float value);
		void	checkDate(std::string date);
		
		std::ifstream	_database;
		std::ifstream	_fileInput;
		std::map<std::string, float> _dataMap;
};

#endif
