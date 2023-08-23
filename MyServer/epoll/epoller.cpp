#include "epoller.h"
#include <sys/epoll.h>
#include <unistd.h>

// 创建epoll对象 epoll_create(512)
Epoller::Epoller(int maxEvents) : epollFd_(epoll_create(512)), events_(maxEvents) {
    assert(epollFd_ >= 0 && events_.size() > 0);
}

Epoller::~Epoller()
{
    close(epollFd_);
}

bool Epoller::AddFd(int fd,uint32_t events)
{
    if (fd < 0) return false;
    epoll_event ev = {0};
    ev.data.fd = fd;
    ev.events = events;
    return 0 == epoll_ctl(epollFd_,EPOLL_CTL_ADD,fd,&ev);
}