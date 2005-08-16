include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsService -I../Linux_DnsAddressMatchList -I../CIM_ConcreteJob -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsServiceSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsQueryACLForServiceInstanceName.o \
        Linux_DnsQueryACLForServiceInstance.o \
        Linux_DnsQueryACLForServiceExternal.o \
        Linux_DnsQueryACLForServiceRepositoryInstance.o \
        Linux_DnsQueryACLForServiceRepositoryExternal.o \
        Linux_DnsQueryACLForServiceManualInstance.o \
        Linux_DnsQueryACLForServiceDefaultImplementation.o

FAKEFACTORY= Linux_DnsQueryACLForServiceFakeFactory.o

NORMALFACTORY= Linux_DnsQueryACLForServiceFactory.o

RESOURCEOBJECT= Linux_DnsQueryACLForServiceResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsQueryACLForServiceProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsQueryACLForServiceSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsQueryACLForServiceSupport.so \
      libLinux_DnsQueryACLForService.so

libLinux_DnsQueryACLForServiceSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsQueryACLForServiceSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsQueryACLForService.so: LDFLAGS+=-lLinux_DnsQueryACLForServiceSupport
libLinux_DnsQueryACLForService.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsQueryACLForServiceSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsQueryACLForServiceSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsQueryACLForService.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsQueryACLForService*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsQueryACLForService*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsQueryACLForServiceSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsQueryACLForService.so
