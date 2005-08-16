include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_ConcreteJob -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_ConcreteJobSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsServiceInstanceName.o \
        Linux_DnsServiceInstance.o \
        Linux_DnsServiceExternal.o \
        Linux_DnsServiceRepositoryInstance.o \
        Linux_DnsServiceRepositoryExternal.o \
        Linux_DnsServiceManualInstance.o \
        Linux_DnsServiceDefaultImplementation.o

FAKEFACTORY= Linux_DnsServiceFakeFactory.o

NORMALFACTORY= Linux_DnsServiceFactory.o

RESOURCEOBJECT= Linux_DnsServiceResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsServiceProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsServiceSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsServiceSupport.so \
      libLinux_DnsService.so

libLinux_DnsServiceSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsServiceSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsService.so: LDFLAGS+=-lLinux_DnsServiceSupport
libLinux_DnsService.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsServiceSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsServiceSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsService.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsService*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsService*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsServiceSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsService.so
