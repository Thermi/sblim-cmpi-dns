include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsService -I../Linux_DnsAddressMatchList -I../CIM_ConcreteJob -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsServiceSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsTransferACLForServiceInstanceName.o \
        Linux_DnsTransferACLForServiceInstance.o \
        Linux_DnsTransferACLForServiceExternal.o \
        Linux_DnsTransferACLForServiceRepositoryInstance.o \
        Linux_DnsTransferACLForServiceRepositoryExternal.o \
        Linux_DnsTransferACLForServiceManualInstance.o \
        Linux_DnsTransferACLForServiceDefaultImplementation.o

FAKEFACTORY= Linux_DnsTransferACLForServiceFakeFactory.o

NORMALFACTORY= Linux_DnsTransferACLForServiceFactory.o

RESOURCEOBJECT= Linux_DnsTransferACLForServiceResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsTransferACLForServiceProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsTransferACLForServiceSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsTransferACLForServiceSupport.so \
      libLinux_DnsTransferACLForService.so

libLinux_DnsTransferACLForServiceSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsTransferACLForServiceSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsTransferACLForService.so: LDFLAGS+=-lLinux_DnsTransferACLForServiceSupport
libLinux_DnsTransferACLForService.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsTransferACLForServiceSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsTransferACLForServiceSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsTransferACLForService.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsTransferACLForService*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsTransferACLForService*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsTransferACLForServiceSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsTransferACLForService.so
