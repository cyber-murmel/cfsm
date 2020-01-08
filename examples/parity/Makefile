APPNAME = parity
BUILDDIR = build

CC = gcc
LD = gcc

INCDIRS  =  inc/
INCDIRS  += $(wildcard lib/*/inc/)
HEADERS  =  $(wildcard $(addsuffix *.h,$(INCDIRS)))
SRCDIRS  =  src/
SRCDIRS  += $(wildcard lib/*/src/)
CFILES   =  $(wildcard $(addsuffix *.c,$(SRCDIRS)))
OBJECTS  =  ${CFILES:%.c=$(BUILDDIR)/%.o}

SHAREDFLAGS = -std=c99 -Os -Wall -Wextra -pedantic
CFLAGS += $(SHAREDFLAGS) -c $(addprefix -I, ${INCDIRS})
LDFLAGS += $(SHAREDFLAGS) -lm

all: $(BUILDDIR) $(APPNAME)

$(BUILDDIR):
	mkdir -p $(addprefix $(BUILDDIR)/, /${SRCDIRS})

${BUILDDIR}/%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -o $@ $<

$(APPNAME): ${OBJECTS}
	${LD} ${LDFLAGS} -o $@ $^

clean:
	rm -rf $(BUILDDIR)
	rm -f $(APPNAME)

.PHONY: all clean
