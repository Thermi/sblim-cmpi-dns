include ../setting.cmpi

CPPFLAGS=-I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=CIM_CollectionOfMSEsInstanceName.o \
        CIM_CollectionOfMSEsInstance.o \
        CIM_CollectionOfMSEsExternal.o

all: clean testfiles prelink install

#------------------------------------------------------------------------------#

compile: $(OBJECTS)

prelink: libCIM_CollectionOfMSEsSupport.so

libCIM_CollectionOfMSEsSupport.so: $(OBJECTS)
	$(LINK.cpp) -o $@ $^

link:
	#nothing to here

#------------------------------------------------------------------------------#

preinstall: prelink
	install libCIM_CollectionOfMSEsSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libCIM_CollectionOfMSEsSupport.so $(COMMONLIB_OUT)	
#	install -m 644 CIM_CollectionOfMSEs*.h $(COMMONINC)
	$(MAKE) -C mof -f $(MOFMAKEFILE) install

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
	$(MAKE) -C mof -f $(MOFMAKEFILE) uninstall;
#	$(RM) $(COMMONINC)/CIM_CollectionOfMSEs*.h \
	$(RM) $(COMMONLIB)/libCIM_CollectionOfMSEsSupport.so
