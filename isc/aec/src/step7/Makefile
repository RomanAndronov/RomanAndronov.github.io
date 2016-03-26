MF = /tmp/aecManifest

AEC = aec.jar
SRCDIR = aec

JFLAGS = -g
JAVAC = javac -cp ./$(SRCDIR):${CLASSPATH}

.SUFFIXES: .java .class
.java.class:
	$(JAVAC) $(JFLAGS) $<

_AEC_SRC = Aec.java \
	AecImpl.java \
	AeNotation.java \
	AeItem.java \
	IReader.java \
	Postfix.java \
	Prefix.java

AEC_SRC = $(_AEC_SRC:%=$(SRCDIR)/%)

AEC_CLASSES = $(AEC_SRC:.java=.class)

$(AEC):	$(AEC_SRC) $(AEC_CLASSES)
	rm -f $(MF)
	echo "Main-Class: $(SRCDIR)/Aec" > $(MF)
	jar cmf $(MF) $@ $(SRCDIR)/*.class
	rm -f $(MF)

clean:
	rm -f $(AEC) $(SRCDIR)/*.class
