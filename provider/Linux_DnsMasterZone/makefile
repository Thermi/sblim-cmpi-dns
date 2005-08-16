include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsMasterZoneInstanceName.o \
        Linux_DnsMasterZoneInstance.o \
        Linux_DnsMasterZoneExternal.o \
        Linux_DnsMasterZoneRepositoryInstance.o \
        Linux_DnsMasterZoneRepositoryExternal.o \
        Linux_DnsMasterZoneManualInstance.o \
        Linux_DnsMasterZoneDefaultImplementation.o

FAKEFACTORY= Linux_DnsMasterZoneFakeFactory.o

NORMALFACTORY= Linux_DnsMasterZoneFactory.o

RESOURCEOBJECT= Linux_DnsMasterZoneResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsMasterZoneProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsMasterZoneSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsMasterZoneSupport.so \
      libLinux_DnsMasterZone.so

libLinux_DnsMasterZoneSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsMasterZoneSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsMasterZone.so: LDFLAGS+=-lLinux_DnsMasterZoneSupport
libLinux_DnsMasterZone.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsMasterZoneSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsMasterZoneSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsMasterZone.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsMasterZone*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsMasterZone*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsMasterZoneSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsMasterZone.so
