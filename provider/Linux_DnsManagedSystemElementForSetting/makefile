include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../Linux_DnsZone -I../Linux_DnsAddressMatchList -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lLinux_DnsZoneSupport -lLinux_DnsAddressMatchListSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsManagedSystemElementForSettingInstanceName.o \
        Linux_DnsManagedSystemElementForSettingInstance.o \
        Linux_DnsManagedSystemElementForSettingExternal.o \
        Linux_DnsManagedSystemElementForSettingRepositoryInstance.o \
        Linux_DnsManagedSystemElementForSettingRepositoryExternal.o \
        Linux_DnsManagedSystemElementForSettingManualInstance.o \
        Linux_DnsManagedSystemElementForSettingDefaultImplementation.o

FAKEFACTORY= Linux_DnsManagedSystemElementForSettingFakeFactory.o

NORMALFACTORY= Linux_DnsManagedSystemElementForSettingFactory.o

RESOURCEOBJECT= Linux_DnsManagedSystemElementForSettingResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsManagedSystemElementForSettingProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsManagedSystemElementForSettingSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsManagedSystemElementForSettingSupport.so \
      libLinux_DnsManagedSystemElementForSetting.so

libLinux_DnsManagedSystemElementForSettingSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsManagedSystemElementForSettingSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsManagedSystemElementForSetting.so: LDFLAGS+=-lLinux_DnsManagedSystemElementForSettingSupport
libLinux_DnsManagedSystemElementForSetting.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsManagedSystemElementForSettingSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsManagedSystemElementForSettingSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsManagedSystemElementForSetting.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsManagedSystemElementForSetting*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsManagedSystemElementForSetting*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsManagedSystemElementForSettingSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsManagedSystemElementForSetting.so
