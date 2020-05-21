NAME = platform
objs := $(NAME).o crt0.o 
out :=	$(NAME).nes

all: $(out)
clean:
	rm -f $(objs)
	rm -f $(NAME).s

.PHONY: all clean

$(NAME).s:
	cc65 -Oi $(NAME).c -o $(NAME).s --add-source

%.o: %.s
	ca65	-g $< -o $@

$(NAME).nes: $(objs)
	ld65 -C nrom_32k_vert.cfg -o rom/$(NAME).nes $(objs) nes.lib
