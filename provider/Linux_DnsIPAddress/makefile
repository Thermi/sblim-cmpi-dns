include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates 
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsIPAddressInstanceName.o \
        Linux_DnsIPAddressInstance.o \
        Linux_DnsIPAddressExternal.o \
        Linux_DnsIPAddressRepositoryInstance.o \
        Linux_DnsIPAddressRepositoryExternal.o \
        Linux_DnsIPAddressManualInstance.o \
        Linux_DnsIPAddressDefaultImplementation.o

FAKEFACTORY= Linux_DnsIPAddressFakeFactory.o

NORMALFACTORY= Linux_DnsIPAddressFactory.o

RESOURCEOBJECT= Linux_DnsIPAddressResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsIPAddressProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsIPAddressSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsIPAddressSupport.so \
      libLinux_DnsIPAddress.so

libLinux_DnsIPAddressSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsIPAddressSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsIPAddress.so: LDFLAGS+=-lLinux_DnsIPAddressSupport
libLinux_DnsIPAddress.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsIPAddressSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsIPAddressSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsIPAddress.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsIPAddress*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsIPAddress*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsIPAddressSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsIPAddress.so
