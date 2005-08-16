include ../setting.cmpi
include setting.provider

CPPFLAGS=$(CPPFLAGS.provider) -I. -I$(CIMOMINC) -I$(COMMONINC) -I$(CIMOMINC)/cpp -I../CIM_CollectionOfMSEs -I../CIM_ManagedSystemElement -D_COMPILE_UNIX -DCMPI_STANDALONE

CXXFLAGS=-Wall -g -fPIC -fno-implicit-templates
LDFLAGS=-L. -L$(COMMONLIB) -L$(COMMONLIB_OUT) -shared -lCIM_CollectionOfMSEsSupport -lCIM_ManagedSystemElementSupport -lcmpiCppImpl -lIBM_ProviderTooling

OBJECTS=Linux_DnsResourceRecordInstanceName.o \
        Linux_DnsResourceRecordInstance.o \
        Linux_DnsResourceRecordExternal.o \
        Linux_DnsResourceRecordRepositoryInstance.o \
        Linux_DnsResourceRecordRepositoryExternal.o \
        Linux_DnsResourceRecordManualInstance.o \
        Linux_DnsResourceRecordDefaultImplementation.o

FAKEFACTORY= Linux_DnsResourceRecordFakeFactory.o

NORMALFACTORY= Linux_DnsResourceRecordFactory.o

RESOURCEOBJECT= Linux_DnsResourceRecordResourceAccess.o

PROVIDEROBJECT=CmpiLinux_DnsResourceRecordProvider.o 

all: testfiles preinstall install

buildall: clean all

#------------------------------------------------------------------------------#

compile: $(OBJECTS) $(FAKEFACTORY) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)

#------------------------------------------------------------------------------#

prelink: $(OBJECTS) $(FAKEFACTORY)
	$(LINK.cpp) -o libLinux_DnsResourceRecordSupport.so $^
	
link: deleteFakeLib \
      libLinux_DnsResourceRecordSupport.so \
      libLinux_DnsResourceRecord.so

libLinux_DnsResourceRecordSupport.so: LDFLAGS+=$(LDFLAGS.provider)
libLinux_DnsResourceRecordSupport.so: $(OBJECTS) $(NORMALFACTORY) $(RESOURCEOBJECT) $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

libLinux_DnsResourceRecord.so: LDFLAGS+=-lLinux_DnsResourceRecordSupport
libLinux_DnsResourceRecord.so: $(PROVIDEROBJECT)
	$(LINK.cpp) -o $@ $^

deleteFakeLib:
	$(RM) *.so

#------------------------------------------------------------------------------#

preinstall: prelink
	install libLinux_DnsResourceRecordSupport.so $(COMMONLIB_OUT)

#------------------------------------------------------------------------------#

install: link
	install libLinux_DnsResourceRecordSupport.so $(COMMONLIB_OUT)	
	install libLinux_DnsResourceRecord.so $(CIMOMLIB_OUT)
#	install -m 644 Linux_DnsResourceRecord*.h $(COMMONINC)
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
#	$(RM) $(COMMONINC)/Linux_DnsResourceRecord*.h \
	$(RM) $(COMMONLIB)/libLinux_DnsResourceRecordSupport.so \
	$(RM) $(CIMOMLIB)/libLinux_DnsResourceRecord.so
