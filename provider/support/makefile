include ../setting.cmpi

CPPFLAGS=-I. -I$(CIMOMINC) -I$(COMMONINC) -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC
LDFLAGS=-L. -L$(CIMOMLIB) -L$(COMMONLIB) -shared -lpthread -lcmpiCppImpl

OBJECTS=ArrayConverter.o \
	CmpiErrorFormater.cpp DnsArray.o

all: clean link testfiles install

#------------------------------------------------------------------------------#

compile: $(OBJECTS)

link: libIBM_ProviderTooling.so

libIBM_ProviderTooling.so: $(OBJECTS)
	$(LINK.cpp) -o $@ $^


#------------------------------------------------------------------------------#

install:
	install libIBM_ProviderTooling.so $(CIMOMLIB_OUT) 
	#install -m 644 *.h $(COMMONINC)

#------------------------------------------------------------------------------#

testfiles:	
	@[ -d $(CIMOMLIB) ] || ( echo directory $(CIMOMLIB) does not exist && false)
	@[ -d $(CIMOMINC) ] || ( echo directory $(CIMOMINC) does not exist - please create manually && false)
	@[ -d $(CIMOMMOF) ] || ( echo directory $(CIMOMMOF) does not exist - please create manually && false)
	@[ -d $(COMMONINC) ] || ( echo directory $(COMMONINC) does not exist - please create manually && false)
	@[ -d $(COMMONLIB) ] || ( echo directory $(COMMONLIB) does not exist - please create manually && false)

#------------------------------------------------------------------------------#

clean:
	$(RM) *.so *.o *~

#------------------------------------------------------------------------------#

uninstall: 
	$(RM) $(COMMONLIB)/libIBM_ProviderTooling.so
