/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:54:01 by lucasmar          #+#    #+#             */
/*   Updated: 2024/04/05 10:49:53 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Libs.hpp"

class Webserv{

	private:
		std::map<int, Data>	_mapServer;
		Socket				_sockets;
		std::vector<int>	clientListSockets;
		std::vector<int>*	listSocketsPoint;
		//struct timeval	timeout;
		//fd_set			readFdsCopy;
		//fd_set			writeFdsCopy;

	public:
		Webserv(void);
		~Webserv(void);
		bool	setDataServer(std::string pathConf);
		int		start(void);
		void	stop(void);
};