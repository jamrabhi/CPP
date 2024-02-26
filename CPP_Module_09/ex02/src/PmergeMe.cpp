/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <jamrabhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:21:33 by jamrabhi          #+#    #+#             */
/*   Updated: 2024/02/26 23:06:19 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/* 							CONSTRUCTORS / DESTRUCTORS						  */
/* ************************************************************************** */

PmergeMe::PmergeMe(int ac, char *av[])
{
	parseSequence(ac, av);
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

/* ************************************************************************** */
/* 									OPERATORS								  */
/* ************************************************************************** */

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

/* ************************************************************************** */
/* 								MEMBER FUNCTIONS							  */
/* ************************************************************************** */

size_t		jacobsthal(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void	checkDigit(std::string num)
{
	for (size_t i = 0; i < num.length(); ++i)
	{
		if (!isdigit(num[i]))
			throw std::runtime_error("sequence must contains only positive int");
	}
	if (atoi(num.c_str()) <= 0)
		throw std::runtime_error("sequence must contains only positive int");
}

void	PmergeMe::parseSequence(int ac, char *av[])
{
	std::string	num;
	
	for	(int i = 1; i < ac; ++i)
	{
		num = av[i];
		checkDigit(num);
		_sequence.push_back(atoi(num.c_str()));
	}
	merge_insert();
}

void	insertionSort(std::vector<int> &sortedSeq, std::vector<int> &unsortedSeq)
{
	size_t i = 3;
	for (size_t jacobIndex = jacobsthal(i); jacobsthal(i - 1) <= unsortedSeq.size(); jacobIndex = jacobsthal(++i))
	{
		(void) sortedSeq;
		size_t prev_jacobIndex = jacobsthal(i - 1);
		size_t index;
		if (jacobIndex > unsortedSeq.size())
			index = unsortedSeq.size();
		else
			index = jacobIndex;
		// std::cout << "i = " << i << " prev_jacobIndex = " << prev_jacobIndex << " jacobIndex = " << jacobIndex << " unsortedSeq.size() = " << unsortedSeq.size() << " index = " << index << std::endl;
		while (index > prev_jacobIndex)
		{
			// std::cout << "\t\t\t\tInserting " << unsortedSeq[index - 1] << std::endl;
			std::vector<int>::iterator insert = std::upper_bound(sortedSeq.begin(), sortedSeq.end(), unsortedSeq[index - 1]);
			std::cout << "J = " << jacobIndex << " index = " << index <<" -  Inserting within : " << std::endl;
			for (std::vector<int>::iterator it = sortedSeq.begin(); it <= insert; ++it)
			{
				std::cout << *it << " ";
			}
			std::cout << std::endl;
			sortedSeq.insert(insert,unsortedSeq[index - 1]);
			index--;
			std::cout << "Sorted sequence : [ ";
			for (size_t i = 0; i < sortedSeq.size(); i++)
			{
				std::cout << sortedSeq[i] << " ";
			}
			std::cout << std::endl;
		}
	}
}

void	merge(std::vector<std::pair<int, int> > &seq, int start, int mid, int end)
{
	int	leftVecSize = mid - start + 1;
	int	rightVecSize = end - mid;

	std::vector<std::pair<int, int> >	leftVec(leftVecSize);
	std::vector<std::pair<int, int> >	rightVec(rightVecSize);

	for (int i = 0; i < leftVecSize; i++)
		leftVec[i] = seq[start + i];
	for (int i = 0; i < rightVecSize; i++)
		rightVec[i] = seq[mid + i + 1];
	
	int i = 0, j = 0, k = start;
	for (; i < leftVecSize && j < rightVecSize; ++k)
	{
		if (leftVec[i].first < rightVec[j].first)
		{
			seq[k] = leftVec[i];
			++i;
		}
		else
		{
			seq[k] = rightVec[j];
			++j;
		}
	}
	
	for (; i < leftVecSize; ++i, ++k)
		seq[k] = leftVec[i];

	for (; j < rightVecSize; ++j, ++k)
		seq[k] = rightVec[j];	
}

void	mergeSort(std::vector<std::pair<int, int> > &seq, int start, int end)
{
	if (start < end)
	{
		int	mid = (start + end) / 2;
		mergeSort(seq, start, mid);
		mergeSort(seq, mid + 1, end);
		merge(seq, start, mid, end);
	}
}

void	PmergeMe::merge_insert()
{
	std::cout << "Original sequence :" << std::endl;
	for (size_t i = 0; i < _sequence.size(); ++i)
		std::cout << _sequence[i] << " ";
	std::cout << std::endl;
	
	//	1.	Group the elements of X into [n/2] pairs of elements, arbitrarily,
	//		leaving one element unpaired if there is an odd number of elements.
	std::vector<std::pair<int, int> > vec_seq;
	for (size_t i = 1; i < _sequence.size(); i += 2)
	{
		vec_seq.push_back(std::make_pair(_sequence[i-1], _sequence[i]));
	}
	int	lastElem = 0;
	if (_sequence.size() % 2 == 1)
		lastElem = *(_sequence.end() - 1);
		
	std::cout << "\t\t1. Vector with pairs :" << std::endl;
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		std::cout << vec_seq[i].first << "\t" << vec_seq[i].second << std::endl;
	}
	
	// 2.	Perform [n/2] comparisons, one per pair,
	// 		to determine the larger of the two elements in each pair.
	std::cout << "\t\t2. Sorting pairs :" << std::endl;
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		if (vec_seq[i].first < vec_seq[i].second)
			std::swap(vec_seq[i].first, vec_seq[i].second);
	}
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		std::cout << vec_seq[i].first << "\t" << vec_seq[i].second << std::endl;
	}
	
	// 3.	Recursively sort the [n/2] larger elements from each pair,
	// 		creating a sorted sequence S of [n/2] of the input elements,
	//		in ascending order.
	std::cout << "\t\t3. Recursively sort pairs :" << std::endl;
	mergeSort(vec_seq, 0, vec_seq.size() - 1);
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		std::cout << vec_seq[i].first << "\t" << vec_seq[i].second << std::endl;
	}
	std::vector<int> sortedSeq;
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		sortedSeq.push_back(vec_seq[i].first);
	}
	std::vector<int> unsortedSeq;
	for (size_t i = 0; i < vec_seq.size(); i++)
	{
		unsortedSeq.push_back(vec_seq[i].second);
	}
	if (lastElem)
		unsortedSeq.push_back(lastElem);
	
	std::cout << "Sorted sequence : [ ";
	for (size_t i = 0; i < sortedSeq.size(); i++)
	{
		std::cout << sortedSeq[i] << " ";
	}
	std::cout << "] - Unsorted sequence : [ ";
	for (size_t i = 0; i < unsortedSeq.size(); i++)
	{
		std::cout << unsortedSeq[i] << " ";
	}
	std::cout << "]" << std::endl;
	
	// 4.	Insert at the start of S the element that was paired with the first
	// 		and smallest element of S.
	std::cout << "\t\t4.Inserting the first unsorted element :" << std::endl;
	sortedSeq.insert(sortedSeq.begin(), *(unsortedSeq.begin()));
	// unsortedSeq.erase(unsortedSeq.begin());
	
	std::cout << "Sorted sequence : [ ";
	for (size_t i = 0; i < sortedSeq.size(); i++)
	{
		std::cout << sortedSeq[i] << " ";
	}
	std::cout << "] - Unsorted sequence : [ ";
	for (size_t i = 0; i < unsortedSeq.size(); i++)
	{
		std::cout << unsortedSeq[i] << " ";
	}
	std::cout << "]" << std::endl;

	// 5.	Insert the remaining [n/2] - 1 elements of X \ S into S,
	//		one at a time, with a specially chosen insertion ordering described
	// 		below. Use binary search in subsequences of S (as described below)
	// 		to determine the position at which each element should be inserted.
	// 		Source : https://en.wikipedia.org/wiki/Merge-insertion_sort

	std::cout << "\t\t5.Inserting the remaining sequence :" << std::endl;
	insertionSort(sortedSeq, unsortedSeq);
	
	std::cout << std::endl << std::endl;

	std::cout << "Sorted sequence : [ ";
	for (size_t i = 0; i < sortedSeq.size(); i++)
	{
		std::cout << sortedSeq[i] << " ";
	}
	std::cout << " ]" << std::endl;
	for (size_t i = 0; i < sortedSeq.size(); ++i)
	{
		if (sortedSeq[i] > sortedSeq[i + 1])
		{
			std::cout << sortedSeq[i] << " > " << sortedSeq[i+1] << std::endl;
		}
	}
}

