APP:= calculator-app

TARGET_DEVICE = $(shell g++ -dumpmachine | cut -f1 -d -)

ifeq ($(TARGET_DEVICE), aarch64)
	CFLAGS:= -DPLATFORM_TERGA
endif

SRCS:= $(wildcard ./thrift/gen-cpp/*.cpp)
OBJS+= $(SRCS:cpp=.o)

CFLAGS+= -I/usr/local/include/thrift -I./thrift/gen-cpp
LIBS+= -L/usr/local/lib -lthrift

CFLAGS+= `pkg-config --cflags $(PKGS)`
LIBS+= `pkg-config --libs $(PKGS)`

all: $(APP)

%.o: %.c $(INCS) Makefile
	$(CXX) -o $@ $(CFLAGS) -g $<

$(APP): $(OBJS) Makefile
	$(CXX) -o $(APP) $(OBJS) $(LIBS)

clean:
	rm -rf $(OBJS) $(APP)
