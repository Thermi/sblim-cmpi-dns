include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsService -I../Linux_DnsAddressMatchList -I../CIM_ConcreteJob -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsServiceSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsAddressMatchListOfServiceInstanceName.o \
        Linux_DnsAddressMatchListOfServiceInstance.o \
        Linux_DnsAddressMatchListOfServiceExternal.o \
        Linux_DnsAddressMatchListOfServiceRepositoryInstance.o \
        Linux_DnsAddressMatchListOfServiceRepositoryExternal.o \
        Linux_DnsAddressMatchListOfServiceManualInstance.o \
        Linux_DnsAddressMatchListOfServiceDefaultImplementation.o

FAKEFACTORY= Linux_DnsAddressMatchListOfServiceFakeFactory.o

NORMALFACTORY= Linux_DnsAddressMatchListOfServiceFactory.o

RESOURCEOBJECT= Linux_DnsAddressMatchListOfServiceResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsAddressMatchListOfServiceProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsAddressMatchListOfServiceSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsAddressMatchListOfServiceSupport.so \
      libLinux_DnsAddressMatchListOfService.so

libLinux_DnsAddressMatchListOfServiceSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsAddressMatchListOfServiceSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsAddressMatchListOfService.so: LDFLAGS+=-lLinux_DnsAddressMatchListOfServiceSupport
libLinux_DnsAddressMatchListOfService.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsAddressMatchListOfServiceSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsAddressMatchListOfServiceSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsAddressMatchListOfService.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsAddressMatchListOfService*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsAddressMatchListOfService*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsAddressMatchListOfServiceSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsAddressMatchListOfService.so
