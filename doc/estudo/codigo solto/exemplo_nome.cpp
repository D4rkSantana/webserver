/*
 codigo do video
https://www.youtube.com/watch?v=VlUO6ERf1TQ

*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <iostream>



#include <winSock2.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <string>

int main(){
    std::cout << "Attemping to create a server" << std::endl;

    SOCKET wsocket;
    SOCKET new_wsocket;
    WSADATA wsaData;

    struct sockaddr_in server;
    int server_len;
    int BUFFER_SIZE = 30720;

    //initialize
    if(WSAStartup(MAKEWORD(2,2), &wsaData) !=0){
        std::cout << "Not inicialize" <<std::endl;
    }

    // create socket 
    wsocket =  socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)
    if (wsocket == INVALID_SOCKET){
        std::cout << "Could not " <<std::endl;
    }

    //bind socket to adress 
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);
    server_len  = sizeof(server);

    if (bind(wsocket, (SOCKADDR *)&server, server_len) != 0){
        std::cout << "could not bind socket" ;
    }

    // listen to address
    if (listen(wsocket, 20) != 0){
        std::cout << "could not listen ";
    }

    std::cout << "Listening on 127.0.0.1:8080" <<std::endl;

    int bytes = 0;
    while(true){
        // accept client  request
        new_wsocket = accept(wsocket, (SOCKADDR*)&server, &server_len);
        if(new_wsocket == INVALID_SOCKET){
            std::cout << "could not accept" << std::endl;
        }

        //read request
        char buff[30720] = {0};
        bytes = recv(new_wsocket, buff, BUFFER_SIZE, 0);
        if(bytes){
            std::cout << "Could not read client request";
        }
        std::string serverMensagem = "HTTP/1.1 200 ok\nContent-Type: text-/html\nContent-Length";
        std::string response = "<html><h1>Ola, mundo!</h1> </html>";
        serverMensagem.append(std::to_string(response.size()));
        serverMensagem.append("\n\n");
        serverMensagem.append(response);

        int bytesSent = 0;
        int totalBytesSent = 0;
        while(totalBytesSent < serverMensagem.size()){
            bytesSent =  send(new_wsocket, serverMensagem.c_str(), serverMensagem.size(), 0);
            if(bytesSent < 0){
                std::cout << "could not send response";
            }
            totalBytesSent += bytesSent;
        }
        std::cout << "sent response to client";
        closesocket(new_wsocket);    
    }
    closesocket(wsocket);
    WSACleanup(); 


    return 0;
}