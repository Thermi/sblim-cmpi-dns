include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsAddressMatchListInstanceName.o \
        Linux_DnsAddressMatchListInstance.o \
        Linux_DnsAddressMatchListExternal.o \
        Linux_DnsAddressMatchListRepositoryInstance.o \
        Linux_DnsAddressMatchListRepositoryExternal.o \
        Linux_DnsAddressMatchListManualInstance.o \
        Linux_DnsAddressMatchListDefaultImplementation.o

FAKEFACTORY= Linux_DnsAddressMatchListFakeFactory.o

NORMALFACTORY= Linux_DnsAddressMatchListFactory.o

RESOURCEOBJECT= Linux_DnsAddressMatchListResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsAddressMatchListProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsAddressMatchListSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsAddressMatchListSupport.so \
      libLinux_DnsAddressMatchList.so

libLinux_DnsAddressMatchListSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsAddressMatchListSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsAddressMatchList.so: LDFLAGS+=-lLinux_DnsAddressMatchListSupport
libLinux_DnsAddressMatchList.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsAddressMatchListSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsAddressMatchListSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsAddressMatchList.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsAddressMatchList*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsAddressMatchList*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsAddressMatchListSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsAddressMatchList.so
