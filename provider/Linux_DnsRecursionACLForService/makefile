include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsService -I../Linux_DnsAddressMatchList -I../CIM_ConcreteJob -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsServiceSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsRecursionACLForServiceInstanceName.o \
        Linux_DnsRecursionACLForServiceInstance.o \
        Linux_DnsRecursionACLForServiceExternal.o \
        Linux_DnsRecursionACLForServiceRepositoryInstance.o \
        Linux_DnsRecursionACLForServiceRepositoryExternal.o \
        Linux_DnsRecursionACLForServiceManualInstance.o \
        Linux_DnsRecursionACLForServiceDefaultImplementation.o

FAKEFACTORY= Linux_DnsRecursionACLForServiceFakeFactory.o

NORMALFACTORY= Linux_DnsRecursionACLForServiceFactory.o

RESOURCEOBJECT= Linux_DnsRecursionACLForServiceResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsRecursionACLForServiceProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsRecursionACLForServiceSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsRecursionACLForServiceSupport.so \
      libLinux_DnsRecursionACLForService.so

libLinux_DnsRecursionACLForServiceSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsRecursionACLForServiceSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsRecursionACLForService.so: LDFLAGS+=-lLinux_DnsRecursionACLForServiceSupport
libLinux_DnsRecursionACLForService.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsRecursionACLForServiceSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsRecursionACLForServiceSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsRecursionACLForService.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsRecursionACLForService*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsRecursionACLForService*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsRecursionACLForServiceSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsRecursionACLForService.so
