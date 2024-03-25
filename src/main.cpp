/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:55:10 by ryoshio-          #+#    #+#             */
/*   Updated: 2024/03/25 10:27:21 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Parser.hpp"
#include "Server.hpp"
#include <csignal>

Server server;

void handleSignal(int signal)
{
    if (signal == SIGINT) {
        std::cout << std::endl;
        Logs::printLog(Logs::INFO, 1, "Stop Server!");
        server.closeServer();
        std::exit(0);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        Logs::printLog(Logs::ERROR, 1, "Invalid number of arguments");
        return (1);
    }
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (arg == "-a") {
            server.setVerbose(true);
            break;
        }
    }
    signal(SIGINT, handleSignal);
    server.initParser(argv[1]);
    server.initSockets();
    server.initPoll();
    return (server.run());
}
