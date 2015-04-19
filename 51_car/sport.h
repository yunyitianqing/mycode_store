#ifndef _SPORT_
#define _SPORT_

class S_port
{
protected:
	int m_Socket_fd;
public:
	S_port(){};
	int open();
	unsigned char read_byte();
	unsigned char write_byte(unsigned char);
	void close();
	
};

#endif
