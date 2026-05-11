#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

//初始化socket套接字
int init_socket(uint16_t *port)
{
    int serven_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if((serven_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket fail");
        exit(EXIT_FAILURE);
    }

    //设置地址结构
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(*port);

    if(bind(serven_socket, (struct sockaddr *)&address, addrlen) < 0)
    {
        perror("bind fail");
        close(serven_socket);
        exit(EXIT_FAILURE);
    };

    //监听
    if(listen(serven_socket, 3) < 0)
    {
        perror("listen fail");
        close(serven_socket);
        exit(EXIT_FAILURE);
    }

    return serven_socket;
}

int main()
{

}