/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poll.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:29:55 by esilva-s          #+#    #+#             */
/*   Updated: 2024/04/28 13:57:09 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Poll_HPP
#define Poll_HPP

#include "./Libs.hpp"

class Poll
{
    private:
        std::vector<int>           _sockets;
        std::vector<struct pollfd> _pollFds;
        std::vector<int>           _fdToClose;

    public:
        Poll(void);
        ~Poll(void);

        void    init(int fd);
        int     execute(void);
        bool    waitMatch(size_t i);
        int     getPollFd(size_t i) const;
        bool    isRead(size_t i) const;
        size_t  getSize(void) const;
        void    addPoll(int socketFd, short events);
        bool    isSocketServer(size_t i);
        void    addFdToClose(int fd);
        void    removeMarkedElements(void);
        void    removeListeningSocket(int fd);
        void    removePollFd(int fd);
};

#endif
