include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsSettingInstanceName.o \
        Linux_DnsSettingInstance.o \
        Linux_DnsSettingExternal.o \
        Linux_DnsSettingRepositoryInstance.o \
        Linux_DnsSettingRepositoryExternal.o \
        Linux_DnsSettingManualInstance.o \
        Linux_DnsSettingDefaultImplementation.o

FAKEFACTORY= Linux_DnsSettingFakeFactory.o

NORMALFACTORY= Linux_DnsSettingFactory.o

RESOURCEOBJECT= Linux_DnsSettingResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsSettingProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsSettingSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsSettingSupport.so \
      libLinux_DnsSetting.so

libLinux_DnsSettingSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsSettingSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsSetting.so: LDFLAGS+=-lLinux_DnsSettingSupport
libLinux_DnsSetting.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsSettingSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsSettingSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsSetting.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsSetting*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsSetting*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsSettingSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsSetting.so
