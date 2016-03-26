MF = /tmp/beefsManifest

BEEFS = beefs.jar
SRCDIR = beefs

JFLAGS = -g
JAVAC = javac -cp ./$(SRCDIR):${CLASSPATH}

.SUFFIXES: .java .class
.java.class:
	$(JAVAC) $(JFLAGS) $<

_BEEFS_SRC = Beefs.java \
	BeefsImpl.java \
	BeNotation.java \
	BeItem.java \
	IReader.java \
	Postfix.java \
	Prefix.java

BEEFS_SRC = $(_BEEFS_SRC:%=$(SRCDIR)/%)

BEEFS_CLASSES = $(BEEFS_SRC:.java=.class)

$(BEEFS):	$(BEEFS_SRC) $(BEEFS_CLASSES)
	rm -f $(MF)
	echo "Main-Class: $(SRCDIR)/Beefs" > $(MF)
	jar cmf $(MF) $@ $(SRCDIR)/*.class
	rm -f $(MF)

clean:
	rm -f $(BEEFS) $(SRCDIR)/*.class
