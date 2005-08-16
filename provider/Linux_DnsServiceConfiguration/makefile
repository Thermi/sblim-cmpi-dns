include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../Linux_DnsService -I../CIM_ConcreteJob -I../Linux_DnsConfiguration -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsServiceSupport -lLinux_DnsConfigurationSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsServiceConfigurationInstanceName.o \
        Linux_DnsServiceConfigurationInstance.o \
        Linux_DnsServiceConfigurationExternal.o \
        Linux_DnsServiceConfigurationRepositoryInstance.o \
        Linux_DnsServiceConfigurationRepositoryExternal.o \
        Linux_DnsServiceConfigurationManualInstance.o \
        Linux_DnsServiceConfigurationDefaultImplementation.o

FAKEFACTORY= Linux_DnsServiceConfigurationFakeFactory.o

NORMALFACTORY= Linux_DnsServiceConfigurationFactory.o

RESOURCEOBJECT= Linux_DnsServiceConfigurationResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsServiceConfigurationProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsServiceConfigurationSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsServiceConfigurationSupport.so \
      libLinux_DnsServiceConfiguration.so

libLinux_DnsServiceConfigurationSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsServiceConfigurationSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsServiceConfiguration.so: LDFLAGS+=-lLinux_DnsServiceConfigurationSupport
libLinux_DnsServiceConfiguration.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsServiceConfigurationSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsServiceConfigurationSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsServiceConfiguration.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsServiceConfiguration*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsServiceConfiguration*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsServiceConfigurationSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsServiceConfiguration.so
