 10 #include <stdio.h>                                 |    main
 11 #include <stdlib.h>                                |~                        
 12 #include <unistd.h>                                |~                        
 13 #include<sys/epoll.h>                              |~                        
 14                                                    |~                        
 15                                                    |~                        
 16 int main(){                                        |~                        
 17     int epfd = epoll_create(1);                    |~                        
 18     if(epfd<0){                                    |~                        
 19         perror("epoll create error\n");            |~                        
 20         return-1;                                  |~                        
 21     }                                              |~                        
 22     struct epoll_event ev;                         |~                        
 23     ev.events = EPOLLIN;                           |~                        
 24     ev.data.fd = 0;                                |~                        
 25                                                    |~                        
 26     epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &ev);        |~                        
 27     while(1){                                      |~                        
 28         struct epoll_event evs[10];                |~                        
 29         int efds = epoll_wait(epfd, evs, 10, 3000);|~                        
 30         if(efds < 0){                              |~                        
 31             perror("epoll_wait error\n");          |~                        
 32             continue;                              |~                        
 33         }else if (efds == 0){                      |~                        
 34             printf("epoll_wait timeout\n");        |~                        
 35             continue;                              |~                        
 36         }                                          |~                        
 37         int i;                                     |~                        
 38         for(i = 0;i< efds; i++){                   |~                        
 39             char buf[1024]={0};                    |~                        
 40             read(evs[i].data.fd,buf,1023);         |~                        
 41             printf("BUF[%s]\n",buf);               |~                        
 42         }                                          |~                        
 43     }                                              |~                        
 44     return 0;                                      |~                        
 45 }                                                  
