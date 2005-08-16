include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsService -I../CIM_ConcreteJob -I../Linux_DnsSetting -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsServiceSupport -lLinux_DnsSettingSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsElementSettingInstanceName.o \
        Linux_DnsElementSettingInstance.o \
        Linux_DnsElementSettingExternal.o \
        Linux_DnsElementSettingRepositoryInstance.o \
        Linux_DnsElementSettingRepositoryExternal.o \
        Linux_DnsElementSettingManualInstance.o \
        Linux_DnsElementSettingDefaultImplementation.o

FAKEFACTORY= Linux_DnsElementSettingFakeFactory.o

NORMALFACTORY= Linux_DnsElementSettingFactory.o

RESOURCEOBJECT= Linux_DnsElementSettingResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsElementSettingProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsElementSettingSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsElementSettingSupport.so \
      libLinux_DnsElementSetting.so

libLinux_DnsElementSettingSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsElementSettingSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsElementSetting.so: LDFLAGS+=-lLinux_DnsElementSettingSupport
libLinux_DnsElementSetting.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsElementSettingSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsElementSettingSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsElementSetting.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsElementSetting*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsElementSetting*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsElementSettingSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsElementSetting.so
