include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsService -I../Linux_DnsAddressMatchList -I../CIM_ConcreteJob -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsServiceSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsBlackholeACLForServiceInstanceName.o \
        Linux_DnsBlackholeACLForServiceInstance.o \
        Linux_DnsBlackholeACLForServiceExternal.o \
        Linux_DnsBlackholeACLForServiceRepositoryInstance.o \
        Linux_DnsBlackholeACLForServiceRepositoryExternal.o \
        Linux_DnsBlackholeACLForServiceManualInstance.o \
        Linux_DnsBlackholeACLForServiceDefaultImplementation.o

FAKEFACTORY= Linux_DnsBlackholeACLForServiceFakeFactory.o

NORMALFACTORY= Linux_DnsBlackholeACLForServiceFactory.o

RESOURCEOBJECT= Linux_DnsBlackholeACLForServiceResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsBlackholeACLForServiceProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsBlackholeACLForServiceSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsBlackholeACLForServiceSupport.so \
      libLinux_DnsBlackholeACLForService.so

libLinux_DnsBlackholeACLForServiceSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsBlackholeACLForServiceSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsBlackholeACLForService.so: LDFLAGS+=-lLinux_DnsBlackholeACLForServiceSupport
libLinux_DnsBlackholeACLForService.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsBlackholeACLForServiceSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsBlackholeACLForServiceSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsBlackholeACLForService.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsBlackholeACLForService*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsBlackholeACLForService*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsBlackholeACLForServiceSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsBlackholeACLForService.so
