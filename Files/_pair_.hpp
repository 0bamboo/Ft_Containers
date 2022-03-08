/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pair_.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:25:01 by abdait-m          #+#    #+#             */
/*   Updated: 2022/03/08 01:00:35 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR__HPP
#define _PAIR__HPP

namespace ft{
	
	template<typename _Key, typename _MappedV>
	class pair{
		
		public:
			
			typedef _Key			_firstType;
			typedef _MappedV		_secondType;
			
			_firstType		first;
			_secondType		second;

			// Constructors:
			pair() : first(), second() { }
			
			pair(const _firstType& f, const _secondType& s) : first(f), second(s) { }
			
			template<typename X, typename Y>
			pair(const pair<X, Y>& _pair) : first(_pair.first), second(_pair.second) { }

			pair&	operator = (const pair& _pair)
			{
				if (this != &_pair)
				{
					this->first = _pair.first;
					this->second = _pair.second;
				}
				return (*this);
			}
			
			~pair() { }

	}; // END! class pair 

	// Relational operators :
	
	template<typename _Key, typename _MappedV>
	bool	operator == (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (_right.first == _left.first && _right.second == _left.second);
	}
	
	template<typename _Key, typename _MappedV>
	bool	operator != (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (!(_right == _left));
	}

	template<typename _Key, typename _MappedV>
	bool	operator < (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (_right.first < _left.second || (!(_left.first < _right.first) && _right.second < _left.second));
	}

	template<typename _Key, typename _MappedV>
	bool	operator <= (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (!(_left < _right));
	}

	template<typename _Key, typename _MappedV>
	bool	operator > (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (_left < _right);
	}

	template<typename _Key, typename _MappedV>
	bool	operator >= (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (!(_right < _left));
	}
	
	// make_pair :
	template<typename _Key, typename _MappedV>
	pair<_Key, _MappedV>	make_pair(_Key first, _MappedV second)
	{
		return (pair<_Key, _MappedV>(first, second));
	}
	
};


#endif
