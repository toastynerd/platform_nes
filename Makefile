NAME = platform
files := background vrambuf
cfiles := $(NAME).c src/background.c
cobjs := $(NAME).s src/background.s
objs := $(NAME).o crt0.o src/background.o
out :=	$(NAME).nes

all: $(out)
clean:
	rm -f $(objs)
	rm -f $(cobjs)
	rm -f $(NAME).s

.PHONY: all clean

%.s: %.c
	cc65	-Oi $< -o $@ --add-source

%.o: %.s 
	ca65	-g $< -o $@

$(NAME).nes: $(cobjs) $(objs)
	ld65 -C nrom_32k_horz.cfg -o rom/$(NAME).nes $(objs) nes.lib
