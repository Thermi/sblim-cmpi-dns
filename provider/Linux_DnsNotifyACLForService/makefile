include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsService -I../Linux_DnsAddressMatchList -I../CIM_ConcreteJob -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsServiceSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsNotifyACLForServiceInstanceName.o \
        Linux_DnsNotifyACLForServiceInstance.o \
        Linux_DnsNotifyACLForServiceExternal.o \
        Linux_DnsNotifyACLForServiceRepositoryInstance.o \
        Linux_DnsNotifyACLForServiceRepositoryExternal.o \
        Linux_DnsNotifyACLForServiceManualInstance.o \
        Linux_DnsNotifyACLForServiceDefaultImplementation.o

FAKEFACTORY= Linux_DnsNotifyACLForServiceFakeFactory.o

NORMALFACTORY= Linux_DnsNotifyACLForServiceFactory.o

RESOURCEOBJECT= Linux_DnsNotifyACLForServiceResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsNotifyACLForServiceProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsNotifyACLForServiceSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsNotifyACLForServiceSupport.so \
      libLinux_DnsNotifyACLForService.so

libLinux_DnsNotifyACLForServiceSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsNotifyACLForServiceSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsNotifyACLForService.so: LDFLAGS+=-lLinux_DnsNotifyACLForServiceSupport
libLinux_DnsNotifyACLForService.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsNotifyACLForServiceSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsNotifyACLForServiceSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsNotifyACLForService.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsNotifyACLForService*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsNotifyACLForService*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsNotifyACLForServiceSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsNotifyACLForService.so
