OBJS=51_proctrl.o camera.o imgpro.o sport.o main.o findcolor.o

FLAG=`pkg-config  opencv --libs  --cflags`

TARGET=main

all:$(TARGET)

$(TARGET): $(OBJS)
	g++ $(OBJS) $(FLAG) -o $@
	
51_proctrl.o: 51_proctrl.cpp
	g++ -c  $< $(FLAG)
	
camera.o: camera.cpp
	g++ -c  $< $(FLAG)
	
imgpro.o: imgpro.cpp
	g++ -c  $< $(FLAG)
	
sport.o:sport.cpp
	g++ -c  $< $(FLAG)
	
findcolor.o:findcolor.cpp
	g++ -c  $< $(FLAG)
	
main.o:main.cpp
	g++ -c  $< $(FLAG)
	
clean:
	rm *.o
