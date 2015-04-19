OBJS= ./engines_control.o
		
SOURCE=	./engines_control.cpp

INCLUDEDIR= -I../../framework/include

TARGET = libM_engines_control.so

LIBIARY_DIR = -L../../lib

LIBIARY = -lpthread -lframework

all: ${TARGET}

${TARGET}:${SOURCE}
	g++ -c ${SOURCE} ${INCLUDEDIR} ${LIBIARY_DIR} ${LIBIARY}
	g++ -shared ${OBJS} -o ../../lib/${TARGET}
clean:
	rm *.o
	rm ../../lib/${TARGET}
