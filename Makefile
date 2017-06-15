CC := gcc
C_FILES := $(wildcard src/*.c)
OBJ_FILES := $(addprefix obj/,$(notdir $(C_FILES:.c=.o)))
CFLAGS := -c -std=c99 -Wall -pedantic
LDFLAGS :=
OPTIMIZATION := -O3 -fomit-frame-pointer
RM := rm -f
NAME := mos6502

$(NAME): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $(OPTIMIZATION) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) obj/*.o $(NAME)

