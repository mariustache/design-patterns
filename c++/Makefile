
SUBDIRS = singleton
SUBDIRS += builder
SUBDIRS += visitor

all: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@

.PHONY: all $(SUBDIRS)
