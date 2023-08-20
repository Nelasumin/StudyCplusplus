#ifndef SERVER_H
#define SERVER_H

#include "global.h"

class server{
    private:
        int server_port;
        int server_sockfd;
        string server_ip;
        static vector<bool> sock_arr;
    public:
        server(int port,string ip);
        ~server();
        void run();
        static void RecvMsg(int conn);
        static void HandleRequest(int conn,string str);
};
#endif
