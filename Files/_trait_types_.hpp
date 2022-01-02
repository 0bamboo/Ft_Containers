/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _trait_types_.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 18:37:30 by abdait-m          #+#    #+#             */
/*   Updated: 2022/01/02 01:38:29 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TRAIT_TYPES_HPP
# define _TRAIT_TYPES_HPP

# include <iostream>

namespace ft
{
	// dispatch tag so i think this tags is used when u want to redirect the call of template class to a specific one 
	template<bool Cond, class T = void>
	struct enable_if { }; // if the condition u give it is true then u allowed to consider the template that u want to use so in this case our condition is defined by is_integral tag
	 //SFINAE : SUSBTITUTION FAILURE IS  NOT AN ERROR  == in general we use this for turn on and off some templates 
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type; 
	};

	/* is_integral */
	template <class T>
	struct is_integral { static const bool value = false; };
	template <>
	struct is_integral<bool> { static const bool value = true; };
	template <>
	struct is_integral<char> { static const bool value = true; };
	template <>
	struct is_integral<wchar_t> { static const bool value = true; };
	template <>
	struct is_integral<char16_t> { static const bool value = true; };
	template <>
	struct is_integral<char32_t> { static const bool value = true; };
	template <>
	struct is_integral<signed char> { static const bool value = true; };
	template <>
	struct is_integral<short int> { static const bool value = true; };
	template <>
	struct is_integral<int> { static const bool value = true; };
	template <>
	struct is_integral<long int> { static const bool value = true; };
	template <>
	struct is_integral<long long int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned char> { static const bool value = true; };
	template <>
	struct is_integral<unsigned short int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long int> { static const bool value = true; };
	template <>
	struct is_integral<unsigned long long int> { static const bool value = true; };
	
}

#endif