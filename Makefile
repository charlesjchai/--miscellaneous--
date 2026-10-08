SUBDIRS := crasher nul

TOPTARGETS := all link unlink clean
$(TOPTARGETS): $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all link unlink clean $(TOPTARGETS) $(SUBDIRS)
