EE_BIN = hello.elf
EE_OBJS =  me_timer.o benchmark.o main.o
EE_LIBS = -ldebug -lc -lpad

all: $(EE_BIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS)

run: $(EE_BIN)
	ps2client execee host:$(EE_BIN)

reset:
	ps2client reset

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal