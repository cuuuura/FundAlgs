FLAGS = -Wextra -Werror -Wall -Wfloat-equal -pedantic -Iinclude
LIBS = -lm

SRCDIR = src
BUILDDIR = build

PROGS_SRCS = $(wildcard $(SRCDIR)/prog*.c)
PROGS = $(patsubst $(SRCDIR)/%.c, %.out, $(PROGS_SRCS)) 

ALL_SRCS = $(wildcard $(SRCDIR)/*.c)
COMMON_SRCS = $(filter-out $(PROGS_SRCS), $(ALL_SRCS))

PROGS_OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(PROGS_SRCS))
COMMON_OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(COMMON_SRCS))

all: $(BUILDDIR) $(PROGS)

$(BUILDDIR):
	mkdir -p $@

$(PROGS): %.out: $(BUILDDIR)/%.o $(COMMON_OBJS)
	gcc $^ -o $@ $(LIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	gcc $(FLAGS) -c $< -o $@ 

clean:
	rm -rf $(BUILDDIR) $(PROGS)