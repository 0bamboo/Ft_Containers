/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _lexicographical_.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:57:04 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/19 16:26:18 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEXICOGRAPHICAL__HPP
# define _LEXICOGRAPHICAL__HPP

namespace ft
{
	// Lexicographical less-than comparison : it compares the elements that have the same position in both ranges..
	// if both equal until one of them ends the shorter seq is lexico.. less than the longer...
	
	template <typename InputIterator1, typename InputIterator2>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
	{
  		while (first1 != last1)
  		{
    		if (first2 == last2 || *first2 < *first1)
				return false;
    		else if (*first1 < *first2)
				return true;
    		++first1;
			++first2;
  		}
  		return (first2 != last2);
	}

	template <typename InputIterator1, typename InputIterator2, typename Compare>
  	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2,
                                Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first1, *first2))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != first1);
	}

};

#endif
