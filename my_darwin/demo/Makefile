OBJS= main.o
		
SOURCE=	main.cpp
		
INCLUDEDIR= -I../framework/include -I../modules/include

LIBIARY= -lpthread -lframework -lM_engines_control

LIBIARY_DIR= -L../lib

TARGET = demo.exe

all: ${TARGET}

${TARGET}:${SOURCE}
	make -C ../framework/build
	make -C ../modules/engines_control 
	g++  -o ../${TARGET} ${SOURCE} ${INCLUDEDIR} ${LIBIARY_DIR} ${LIBIARY} -Wl,-rpath=./lib
clean:
	make clean -C ../modules/engines_control 
	make clean -C ../framework/build
	rm ../${TARGET}
