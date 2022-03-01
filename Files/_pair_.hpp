/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pair_.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:25:01 by abdait-m          #+#    #+#             */
/*   Updated: 2022/02/18 22:16:02 by abdait-m         ###   ########.fr       */
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
			
			_firstType		_first;
			_secondType		_second;

			// Constructors:
			pair() : _first(), _second() { }
			
			pair(const _firstType& f, const _secondType& s) : _first(f), _second(s) { }
			
			template<typename X, typename Y>
			pair(const pair<X, Y>& _pair) : _first(_pair._first), _second(_pair._second) { }

			pair&	operator = (const pair& _pair)
			{
				if (this != &_pair)
				{
					this->_first = _pair._first;
					this->_second = _pair._second;
				}
				return (*this);
			}
			
			~pair() { }

	}; // END! class pair 

	// Relational operators :
	
	template<typename _Key, typename _MappedV>
	bool	operator == (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (_right._first == _left._first && _right._second == _left._second);
	}
	
	template<typename _Key, typename _MappedV>
	bool	operator != (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (!(_right == _left));
	}

	template<typename _Key, typename _MappedV>
	bool	operator < (const pair<_Key, _MappedV>& _right, const pair<_Key, _MappedV>& _left)
	{
		return (_right._first < _left._second || (!(_left._first < _right._first) && _right._second < _left._second));
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
	pair<_Key, _MappedV>	make_pair(_Key _first, _MappedV _second)
	{
		return (pair<_Key, _MappedV>(_first, _second));
	}
	
};


#endif
