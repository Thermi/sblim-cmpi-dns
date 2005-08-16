include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsSetting -I../Linux_DnsConfiguration -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsSettingSupport -lLinux_DnsConfigurationSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsSettingContextInstanceName.o \
        Linux_DnsSettingContextInstance.o \
        Linux_DnsSettingContextExternal.o \
        Linux_DnsSettingContextRepositoryInstance.o \
        Linux_DnsSettingContextRepositoryExternal.o \
        Linux_DnsSettingContextManualInstance.o \
        Linux_DnsSettingContextDefaultImplementation.o

FAKEFACTORY= Linux_DnsSettingContextFakeFactory.o

NORMALFACTORY= Linux_DnsSettingContextFactory.o

RESOURCEOBJECT= Linux_DnsSettingContextResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsSettingContextProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsSettingContextSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsSettingContextSupport.so \
      libLinux_DnsSettingContext.so

libLinux_DnsSettingContextSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsSettingContextSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsSettingContext.so: LDFLAGS+=-lLinux_DnsSettingContextSupport
libLinux_DnsSettingContext.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsSettingContextSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsSettingContextSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsSettingContext.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsSettingContext*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsSettingContext*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsSettingContextSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsSettingContext.so
