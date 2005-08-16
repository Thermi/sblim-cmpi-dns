include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsConfigurationInstanceName.o \
        Linux_DnsConfigurationInstance.o \
        Linux_DnsConfigurationExternal.o \
        Linux_DnsConfigurationRepositoryInstance.o \
        Linux_DnsConfigurationRepositoryExternal.o \
        Linux_DnsConfigurationManualInstance.o \
        Linux_DnsConfigurationDefaultImplementation.o

FAKEFACTORY= Linux_DnsConfigurationFakeFactory.o

NORMALFACTORY= Linux_DnsConfigurationFactory.o

RESOURCEOBJECT= Linux_DnsConfigurationResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsConfigurationProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsConfigurationSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsConfigurationSupport.so \
      libLinux_DnsConfiguration.so

libLinux_DnsConfigurationSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsConfigurationSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsConfiguration.so: LDFLAGS+=-lLinux_DnsConfigurationSupport
libLinux_DnsConfiguration.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsConfigurationSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsConfigurationSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsConfiguration.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsConfiguration*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsConfiguration*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsConfigurationSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsConfiguration.so
