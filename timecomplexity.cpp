/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timecomplexity.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:14:44 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/17 20:40:47 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

// TIME COMPLEXITY :
// Big O notation also known as the worst case time complexity,
// Most common Big O notation examples :

// The worst to the best cases (high order to low order) (slowest to fastest algos time complexity) :
// O(n!) --- O(2^(x)) --- O(x^(3)) --- O(x^(2)) --- O(n log(n)) --- O(n) --- O(log(n)) --- O(1)


// Examples :

// O(1) :
void	_BigO_of_1_(int arr[])
{
	std::cout << arr[0] << std::endl;
}

// O(n) :
void	_BigO_of_n_(int arr[], int size)
{
	for (int i = 1; i < size; i++)
		std::cout << arr[i] << std::endl;
}

// O(n^(2)) : 
void	_BigO_of_n2_(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			std::cout << arr[i] << " - " << arr[j] << std::endl;
	}
}

// O(2^(n))  (Fibonacci) :
int		_BigO_of_2n_(int num)
{
	if (num <= 1)
		return (num);
	return (_BigO_of_2n_(num - 2) + _BigO_of_2n_(num - 1));
}

// O(log(n)) (binary search (as u know the array must already be sorted)) :

int		_BigO_of_logn_(int arr[], int size, int search)
{
	int low = 0, high = size - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (search == arr[mid])
			return (true);
		else if (search < arr[mid])
			high = mid - 1;
		else if (search > arr[mid])
			low = mid + 1;
		else
			break;
	}
	return (false);
}

// O(nlog(n)) (like merge sort and heap sort and quick sort).

// O(n!) like NP-complete problems like (The Traveling Salesman Problem (look for it :D)) .


int main()
{
	
}