target =libneural_net.so

objs = ../nerve_base.o \
		../nerve_sig.o \
		../nerve_sec.o \
		../nerve_step.o

include_dirs = -I..

lib += -lm

flags += -shared

$(target):$(objs)
	g++ $(flags) -o $(target) $(objs) $(include_dirs) $(lib)

clean:
	rm $(objs) $(target)
