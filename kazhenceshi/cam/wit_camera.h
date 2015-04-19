#ifndef _VISION_MODULE_H_
#define _VISION_MODULE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <getopt.h>			/** getopt_long() */

#include <fcntl.h>			/** low-level i/o */

#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#include <linux/videodev2.h>

#include <libv4lconvert.h>

namespace WIT
{
	static struct v4l2_format fmt;
	
	enum io_method{
		IO_METHOD_READ, 
		IO_METHOD_MMAP, 
		IO_METHOD_USERPTR, 
	};
	
	struct buffer {
		void *start; 
		size_t length;
	};
	
	static char 			*dev_name;
	static enum io_method	io = IO_METHOD_MMAP;
	static int 				fd = -1;
	static struct buffer	*buffers;
	static unsigned int 	n_buffers; 
	static int 				out_buf;
	static int 				force_format;
	static int				isRemote = 1;
}



class CamModule
{
public:
	CamModule();
	~CamModule();
	void get_frame(unsigned char *src);
private:
	void open_device(void);
	void close_device(void);
	void init_device(void);
	void init_userp(unsigned int buffer_size);
	void init_mmap(void);
	void init_read(unsigned int buffer_size);
	void uninit_device(void);
	void start_capturing(void);
	void stop_capturing(void);
	void mainloop(unsigned char *src);
	int read_frame();
	void process_image(const void *p, int size);
	int xioctl(int fh, unsigned long int request, void *arg);
	void errno_exit(const char *s);
	unsigned char *imgData;
	void Img_Attribute();
/*	
	void *context;
	void *responder;
protected:*/
	
};

#endif // _VISION_MODULE_H_
