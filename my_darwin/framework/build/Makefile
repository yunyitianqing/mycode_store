OBJS= CM730.o \
		LinuxCM730.o \
		MX28.o \
		WitEngine.o \
		WitManager.o \
		WitModule.o
		
SOURCE=	../src/CM730.cpp \
		../src/LinuxCM730.cpp \
		../src/MX28.cpp \
		../src/WitEngine.cpp \
		../src/WitManager.cpp \
		../src/WitModule.cpp
		
INCLUDEDIR= -I../include

TARGET = libframework.so

all: ${TARGET}

${TARGET}:${SOURCE}
	g++ -c ${SOURCE} ${INCLUDEDIR} -lpthread 
	g++ -shared ${OBJS} -o ../../lib/${TARGET}
clean:
	rm *.o
	rm ../../lib/${TARGET}
