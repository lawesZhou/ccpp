#include "apue.h"
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iconv.h>

#define MAXADDRLEN	256
#define BUFLEN		1280

void
print(int sockfd)
{
	int		n;
	char	buf[BUFLEN];

	const char *s = "GET /rn=142269938300&list=s_sh600277 HTTP/1.0\r\n\r\n";
	write(sockfd, s, strlen(s));

	iconv_t cd = iconv_open("utf-8", "GBK");
	if (cd == (iconv_t)-1) {
		perror("create cd failed");
		exit(-1);
	}
	while ((n = recv(sockfd, buf, BUFLEN, 0)) > 0) {
//		printf("%s\n", buf);

		char *inbuf = buf;
		char obuf[4096];
		char *outbuf = obuf;
		size_t lenout = 4096;
		size_t lenin = strlen(buf);
		printf("length of inbuf = %d %lu\n", n, lenin); //n == lenin
		iconv(cd, &inbuf, &lenin, &outbuf, &lenout);
		printf("length of obuf = %lu\n", 4096 - lenout);

		write(STDOUT_FILENO, obuf, 4096-lenout);
	}
	iconv_close(cd);
	if (n < 0)
		err_sys("recv error");
}

int
main(int argc, char *argv[])
{
	struct addrinfo	*ailist, *aip;
	struct addrinfo	hint;
	int				sockfd, err;

	if (argc != 1)
		err_quit("usage: ruptime hostname");
	hint.ai_flags = 0;
	hint.ai_family = 0;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_protocol = 0;
	hint.ai_addrlen = 0;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;
	const char *host = "hq.sinajs.cn";
	if ((err = getaddrinfo(host, "http", &hint, &ailist)) != 0)
		err_quit("getaddrinfo error: %s", gai_strerror(err));

	for (aip = ailist; aip != NULL; aip = aip->ai_next) {
		struct sockaddr_in *ipv4addr = (struct sockaddr_in *)aip->ai_addr;
		printf("%u\n", ipv4addr->sin_addr.s_addr);
		in_addr_t addr = ipv4addr->sin_addr.s_addr;//ipv4地址的网咯字节序
		printf("%u\n", ntohl(addr));//将网络字节序改换成主机字节序
		printf("%s\n", inet_ntoa(ipv4addr->sin_addr));//将网络主机ipv4地址转换成*.*.*.*字符串格式
		if ((sockfd = socket(aip->ai_family, SOCK_STREAM, 0)) < 0) {
			err = errno;
		} else {
			if (connect(sockfd, aip->ai_addr, 
				    aip->ai_addrlen) == 0) {
				printf("connect successfully\n");
				print(sockfd);
				exit(0);
			} else {
				printf("connect failed\n");
			}
		}
	}
	return 0;
}
