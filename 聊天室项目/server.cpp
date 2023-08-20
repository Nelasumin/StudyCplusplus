#include "server.h"

vector<bool> server::sock_arr(10000,false);

server::server(int port,string ip):server_port(port),server_ip(ip){}
server::~server(){
    for(int i=0;i<sock_arr.size();i++){
        if(sock_arr[i])
            close(i);
    }
    close(server_sockfd);
}
void server::run(){
    //定义sockfd
    server_sockfd = socket(AF_INET,SOCK_STREAM, 0);

    //定义sockaddr_in
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;//TCP/IP协议族
    server_sockaddr.sin_port = htons(server_port);//server_port;//端口号
    server_sockaddr.sin_addr.s_addr = inet_addr(server_ip.c_str());//ip地址，127.0.0.1是环回地址，相当于本机ip

    //bind，成功返回0，出错返回-1
    if(bind(server_sockfd,(struct sockaddr *)&server_sockaddr,sizeof(server_sockaddr))==-1)
    {
        perror("bind");//输出错误原因
        exit(1);//结束程序
    }

    //listen，成功返回0，出错返回-1
    if(listen(server_sockfd,20) == -1)
    {
        perror("listen");//输出错误原因
        exit(1);//结束程序
    }

    //客户端套接字
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);

    //成功返回非负描述字，出错返回-1
    while(1){
        int conn = accept(server_sockfd, (struct sockaddr*)&client_addr, &length);
        if(conn<0)
        {
            perror("connect");//输出错误原因
            exit(1);//结束程序
        }
        cout<<"文件描述符为"<<conn<<"的客户端成功连接\n";
        sock_arr[conn]=true;
        thread t(server::RecvMsg,conn);
        t.detach();
    }
}
//注意，前面不用加static！
void server::RecvMsg(int conn){
    //接收缓冲区
    char buffer[1000];
    //不断接收数据
    while(1)
    {
        memset(buffer,0,sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer),0);
        //客户端发送exit或者异常结束时，退出
        if(strcmp(buffer,"exit")==0 || len<=0){
            close(conn);
            sock_arr[conn]=false;
            break;
        }
        cout<<"收到套接字描述符为"<<conn<<"发来的信息："<<buffer<<endl;
        string str(buffer);        
        HandleRequest(conn,str);
    }
}
void server::HandleRequest(int conn,string str){
    char buffer[1000];
    string name,pass;
    // bool if_login=false;//记录当前服务对象是否成功登录
    //string login_name;//记录当前服务对象的名字
    //string target_name;//记录发送信息时目标用户的名字
    //int group_num;//记录群号
    
    
    //连接MYSQL数据库
    MYSQL *con=mysql_init(NULL);
    mysql_real_connect(con,"127.0.0.1","root","","ChatProject",0,NULL,CLIENT_MULTI_STATEMENTS);

    if(str.find("name:")!=str.npos){
        int p1=str.find("name:"),p2=str.find("pass:");
        name=str.substr(p1+5,p2-5);
        pass=str.substr(p2+5,str.length()-p2-4);
        string search="INSERT INTO USER VALUES (\"";
        search+=name;
        search+="\",\"";
        search+=pass;
        search+="\");";
        cout<<"sql语句:"<<search<<endl<<endl;
        mysql_query(con,search.c_str());
    } 
}