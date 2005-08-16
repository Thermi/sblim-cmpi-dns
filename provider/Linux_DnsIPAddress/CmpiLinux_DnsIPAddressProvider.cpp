 /**
 * CmpiLinux_DnsIPAddressProvider.cpp
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * author:     Murillo Bernardes <bernarde@br.ibm.com>
 *
 * Contributors:
 *
 */
#include "CmpiLinux_DnsIPAddressProvider.h"
#include "ArrayConverter.h"
#include "Linux_DnsIPAddressManualInstance.h"
#include "Linux_DnsIPAddressRepositoryInstance.h"

#include <iostream>
#include <strings.h>

using namespace std;

namespace genProvider {

  CmpiLinux_DnsIPAddressProvider::
   CmpiLinux_DnsIPAddressProvider (
   const CmpiBroker &mbp, const CmpiContext& ctx):
    CmpiBaseMI(mbp, ctx), CmpiInstanceMI(mbp,ctx),
    CmpiMethodMI(mbp,ctx), cppBroker(mbp) {
      
      interfaceP=Linux_DnsIPAddressFactory::getImplementation();           
      cout<<"Provider was constructed"<<endl;
  };
    
        
  const char * CmpiLinux_DnsIPAddressProvider::
   shadowNameSpaceP="IBMShadow/cimv2";
        
  CmpiLinux_DnsIPAddressProvider::
   ~CmpiLinux_DnsIPAddressProvider(){
	  delete interfaceP;
  };
  
  int CmpiLinux_DnsIPAddressProvider::isUnloadable() const{
    return 0;
  }
	
  /* -----------------------------------------------------------------------*/
  /*                       Adding shadow properties                         */
  /* -----------------------------------------------------------------------*/

  void CmpiLinux_DnsIPAddressProvider::completeInstance(
   const Linux_DnsIPAddressInstanceName& instanceName,
   CmpiInstance& target, const CmpiContext& ctx){
	  	
    Linux_DnsIPAddressInstanceName shadowInstanceName(instanceName);
    shadowInstanceName.setNamespace(shadowNameSpaceP);
    CmpiObjectPath cmpiObjectPath=shadowInstanceName.getObjectPath();
	  
    try{
      const char* propertiesP=0;
      CmpiInstance shadowInstance=cppBroker.getInstance (
       ctx, cmpiObjectPath,&propertiesP);
      copyShadowData(&shadowInstance,&target);
    }catch(const CmpiStatus& rc){};                             
  };
	
	
  void CmpiLinux_DnsIPAddressProvider::copyShadowData (
   const CmpiInstance* source, CmpiInstance* target){
    
	  
  };
    
  /* -----------------------------------------------------------------------*/
  /*                       Extracting shadow instance                         */
  /* -----------------------------------------------------------------------*/

  CmpiInstance* CmpiLinux_DnsIPAddressProvider::
   getShadowInstance (const CmpiInstance& original,
   const Linux_DnsIPAddressInstanceName& instanceName){
     
    Linux_DnsIPAddressInstanceName shadowInstanceName(instanceName);
    shadowInstanceName.setNamespace(shadowNameSpaceP);
    CmpiObjectPath cmpiObjectPath=shadowInstanceName.getObjectPath();
      
    CmpiInstance* targetP=new CmpiInstance(cmpiObjectPath);
      
    copyShadowData(&original,targetP);
      
    if(targetP->getPropertyCount()==0)
      return 0;
    else
      return targetP;
  }

  /* -----------------------------------------------------------------------*/
  /*                          House keeping                              */
  /* -----------------------------------------------------------------------*/

  void CmpiLinux_DnsIPAddressProvider::removeDanglingShadowInstances (
   const Linux_DnsIPAddressInstanceNameEnumeration& dinInsNames){
	
    //TODO: enumerate shadow instance names and remove those not included
	// in dinInsNames
	
  };	 	
	
  /* -----------------------------------------------------------------------*/
  /*                          Provider Factory                              */
  /* -----------------------------------------------------------------------*/

  CMProviderBase(CmpiLinux_DnsIPAddressProvider);

  CMInstanceMIFactory(
   CmpiLinux_DnsIPAddressProvider, CmpiLinux_DnsIPAddressProvider);

  CMMethodMIFactory(
   CmpiLinux_DnsIPAddressProvider, CmpiLinux_DnsIPAddressProvider);

	
	
  /* -----------------------------------------------------------------------*/
  /*                      Instance Provider Interface                       */
  /* -----------------------------------------------------------------------*/

  //enumInstanceNames
	
  CmpiStatus CmpiLinux_DnsIPAddressProvider::enumInstanceNames (
   const CmpiContext& ctx, CmpiResult& rslt,
   const CmpiObjectPath& cop){
      
    cout<<"enumerating instanceNames"<<endl;
    CmpiString nameSpace=cop.getNameSpace();
    const char* nameSpaceP=nameSpace.charPtr();

    Linux_DnsIPAddressInstanceNameEnumeration enumeration;
    interfaceP->enumInstanceNames(ctx, cppBroker, nameSpaceP, enumeration);
                   
    while ( enumeration.hasNext() ){
      const Linux_DnsIPAddressInstanceName& instanceName=
      enumeration.getNext();
        
      CmpiObjectPath objectPath=instanceName.getObjectPath();
        
      rslt.returnData(objectPath);
    }
      
    //we make housekeeping
    removeDanglingShadowInstances(enumeration);
      
    rslt.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  };
     
     
  //enumInstances
     
  CmpiStatus CmpiLinux_DnsIPAddressProvider::enumInstances (
   const CmpiContext& ctx, CmpiResult& rslt,
   const CmpiObjectPath& cop, const char* *properties){
     
    cout<<"enumerating instances"<<endl;
    CmpiString nameSpace=cop.getNameSpace();
    const char* nameSpaceP=nameSpace.charPtr();
      
    Linux_DnsIPAddressManualInstanceEnumeration enumeration;
    interfaceP->enumInstances(ctx, cppBroker, nameSpaceP, properties, enumeration);
      
    cout<<"enumerated"<<endl;
      
    while ( enumeration.hasNext() ){
      	
   	  const Linux_DnsIPAddressManualInstance& instance=
       enumeration.getNext();
      	
      cout<<"enumerating getNext"<<endl;
      	
      CmpiInstance cmpiInstance=instance.getCmpiInstance(properties);
      cout<<"transformed"<<endl;
      	
      //add the static data
      completeInstance(instance.getInstanceName(),cmpiInstance,ctx);
      	
      rslt.returnData(cmpiInstance);
    }
      
    rslt.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  };
    
    
  //getInstance
    
  CmpiStatus CmpiLinux_DnsIPAddressProvider::getInstance (
   const CmpiContext& ctx, CmpiResult& rslt,
   const CmpiObjectPath& cop, const char* *properties){
     	
    //covert to instanceName
    Linux_DnsIPAddressInstanceName instanceName(cop);
      
    //get instance for instanceName
    Linux_DnsIPAddressManualInstance instance;
    instance=interfaceP->getInstance(ctx, cppBroker, properties, instanceName);
      
    //we convert the instance in a cmpiInstance
    CmpiInstance cmpiInstance=instance.getCmpiInstance(properties);
      
    //add the static data
    completeInstance(instance.getInstanceName(), cmpiInstance, ctx);
      
    rslt.returnData(cmpiInstance);
      
    rslt.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  };
    
    
  CmpiStatus CmpiLinux_DnsIPAddressProvider::createInstance (
   const CmpiContext& ctx, CmpiResult& rslt,
   const CmpiObjectPath& cop,const CmpiInstance& inst){
   	
   	Linux_DnsIPAddressManualInstance instance (
     inst,cop.getNameSpace().charPtr());
    
    //REPOSITORY DATA    
    CmpiInstance* backupShadowInstance=0;
   	CmpiInstance shadowInstance=
     Linux_DnsIPAddressRepositoryInstance(inst,shadowNameSpaceP)
     .getCmpiInstance(0);     
     
   	//We keep a backup of the existing data for recovering previous
   	//state if the resource access raise an exception
   	CmpiObjectPath shadowOp=shadowInstance.getObjectPath();
    try{
   	  backupShadowInstance=new CmpiInstance(
   	   cppBroker.getInstance (ctx, shadowOp,0));
   	  //if the shadow instance exist we delete it
   	  cppBroker.deleteInstance(ctx, shadowOp);   	    
   	}catch(CmpiStatus& rc){};   	
    
    cppBroker.createInstance(ctx, shadowOp,shadowInstance);     
         	
    
    //RESOURCE ACCESS DATA   
    try{
      interfaceP->createInstance(ctx, cppBroker, instance);
    }catch(CmpiStatus& rc){
      //If something went wrong we recover the previous state
      cppBroker.deleteInstance(ctx, shadowOp);
      if(backupShadowInstance){
        cppBroker.createInstance(ctx, shadowOp,*backupShadowInstance);
      }
      throw rc;
    }
    // ---- temp fix ?? for problem: ecute creteInstance does not return op

/*    const char * nsp="root/cimv2";
    CmpiObjectPath op(nsp,"Linux_DnsIPAddress");
    op.setKey("ZoneName","r1company");
	op.setKey("IPAddress","10.0.0.1");
    rslt.returnData(op); */

    rslt.returnData( instance.getInstanceName().getObjectPath() );
    //
 
    if(backupShadowInstance)
      delete(backupShadowInstance);
    
    rslt.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  };
    
    
  CmpiStatus CmpiLinux_DnsIPAddressProvider::setInstance (
   const CmpiContext& ctx, CmpiResult& rslt,
   const CmpiObjectPath& cop, const CmpiInstance& inst,
   const char* *properties){
   	
   	Linux_DnsIPAddressManualInstance instance (
     inst,cop.getNameSpace().charPtr());
    
    //REPOSITORY DATA    
    CmpiInstance* backupShadowInstance=0;
    CmpiInstance shadowInstance=
     Linux_DnsIPAddressRepositoryInstance(inst,shadowNameSpaceP)
     .getCmpiInstance(0);     
     
   	//We keep a backup of the existing data for recovering previous
   	//state if the resource access raise an exception
   	CmpiObjectPath shadowOp=shadowInstance.getObjectPath();
    try{
   	  backupShadowInstance=new CmpiInstance(
   	   cppBroker.getInstance (ctx, shadowOp,0));
   	}catch(CmpiStatus& rc){};   	
    
    //if the instance existed before we delete it
    //(setInstance is buggy in Pegasus)
    if(backupShadowInstance)
      cppBroker.setInstance(ctx, shadowOp,shadowInstance,properties);
    else
      cppBroker.createInstance(ctx, shadowOp,shadowInstance);      
    
    
    //RESOURCE ACCESS DATA   
    try{
      interfaceP->setInstance(ctx, cppBroker, properties, instance);
    }catch(CmpiStatus& rc){
      //If something went wrong we recover the previous state
      cppBroker.deleteInstance(ctx, shadowOp);
      if(backupShadowInstance){
        cppBroker.createInstance(ctx, shadowOp,*backupShadowInstance);
      }
      throw rc;
    };
      
    if(backupShadowInstance)
      delete(backupShadowInstance);
        
    rslt.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  };
    
    
  CmpiStatus CmpiLinux_DnsIPAddressProvider::deleteInstance (
   const CmpiContext& ctx, CmpiResult& rslt,
   const CmpiObjectPath& cop){
      
    Linux_DnsIPAddressInstanceName instanceName=
     Linux_DnsIPAddressInstanceName(cop);
    interfaceP->deleteInstance(ctx, cppBroker, instanceName);

    instanceName.setNamespace(shadowNameSpaceP);
    CmpiObjectPath op=instanceName.getObjectPath();
      
    try{  //The instance could not have static data
      cppBroker.deleteInstance(ctx, op);
    }catch(CmpiStatus& rc){};
      
    rslt.returnDone();
    return CmpiStatus(CMPI_RC_OK);
  };
    
    
  CmpiStatus CmpiLinux_DnsIPAddressProvider::invokeMethod (
   const CmpiContext& ctx, CmpiResult& rslt,
   const CmpiObjectPath& ref, const char* methodName,
   const CmpiArgs& in, CmpiArgs& out){
     	
    Linux_DnsIPAddressInstanceName instanceName=
     Linux_DnsIPAddressInstanceName(ref);
     
    if (strcasecmp(methodName,"ApplyIncrementalChangeToCollection")==0){
        cout<<"executing method ApplyIncrementalChangeToCollection"<<endl;
        
        int isCollectionPresent=0;
        CIM_CollectionOfMSEsInstanceName  Collection;
        try{
        CmpiData CollectionCmpiData=in.getArg("Collection");
        isCollectionPresent=!CollectionCmpiData.isNullValue();
        CmpiObjectPath CollectionCmpi=CollectionCmpiData;
        Collection=CIM_CollectionOfMSEsInstanceName(CollectionCmpi);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isTimeToApplyPresent=0;
        CmpiDateTime TimeToApply;
        try{
        CmpiData TimeToApplyCmpiData=in.getArg("TimeToApply");
        isTimeToApplyPresent=!TimeToApplyCmpiData.isNullValue();
         TimeToApply=TimeToApplyCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isContinueOnErrorPresent=0;
        CMPIBoolean ContinueOnError;
        try{
        CmpiData ContinueOnErrorCmpiData=in.getArg("ContinueOnError");
        isContinueOnErrorPresent=!ContinueOnErrorCmpiData.isNullValue();
         ContinueOnError=ContinueOnErrorCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isMustBeCompletedByPresent=0;
        CmpiDateTime MustBeCompletedBy;
        try{
        CmpiData MustBeCompletedByCmpiData=in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent=!MustBeCompletedByCmpiData.isNullValue();
         MustBeCompletedBy=MustBeCompletedByCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isPropertiesToApplyPresent=0;
        char** PropertiesToApply=0;
        CMPICount PropertiesToApplySize;
        try{
        CmpiData PropertiesToApplyCmpiData=in.getArg("PropertiesToApply");
        isPropertiesToApplyPresent=!PropertiesToApplyCmpiData.isNullValue();
        CmpiArray PropertiesToApplyCmpi=PropertiesToApplyCmpiData;
        PropertiesToApplySize=PropertiesToApplyCmpi.size();
        ArrayConverter::makeArray(PropertiesToApplyCmpi,
         &PropertiesToApply, PropertiesToApplySize);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };char** CanNotApply;
        CMPICount CanNotApplySize;
                
        rslt.returnData(CmpiData(interfaceP->ApplyIncrementalChangeToCollection(
         ctx,
         cppBroker,
         instanceName,
         Collection,
         isCollectionPresent,
         TimeToApply,
         isTimeToApplyPresent,
         ContinueOnError,
         isContinueOnErrorPresent,
         MustBeCompletedBy,
         isMustBeCompletedByPresent,
         (const char**) PropertiesToApply,
         PropertiesToApplySize,
         isPropertiesToApplyPresent,
         CanNotApply,
         CanNotApplySize)));
        out.setArg("CanNotApply", CmpiData(ArrayConverter::makeCmpiArray((const char**) CanNotApply, CanNotApplySize)));
        if(PropertiesToApply)
          ArrayConverter::destructArray(PropertiesToApply, PropertiesToApplySize);
        if(CanNotApply)
          ArrayConverter::destructArray(CanNotApply, CanNotApplySize);
        cout<<"end of method ApplyIncrementalChangeToCollection"<<endl;     
      }else if (strcasecmp(methodName,"ApplyIncrementalChangeToMSE")==0){
        cout<<"executing method ApplyIncrementalChangeToMSE"<<endl;
        
        int isMSEPresent=0;
        CIM_ManagedSystemElementInstanceName  MSE;
        try{
        CmpiData MSECmpiData=in.getArg("MSE");
        isMSEPresent=!MSECmpiData.isNullValue();
        CmpiObjectPath MSECmpi=MSECmpiData;
        MSE=CIM_ManagedSystemElementInstanceName(MSECmpi);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isTimeToApplyPresent=0;
        CmpiDateTime TimeToApply;
        try{
        CmpiData TimeToApplyCmpiData=in.getArg("TimeToApply");
        isTimeToApplyPresent=!TimeToApplyCmpiData.isNullValue();
         TimeToApply=TimeToApplyCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isMustBeCompletedByPresent=0;
        CmpiDateTime MustBeCompletedBy;
        try{
        CmpiData MustBeCompletedByCmpiData=in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent=!MustBeCompletedByCmpiData.isNullValue();
         MustBeCompletedBy=MustBeCompletedByCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isPropertiesToApplyPresent=0;
        char** PropertiesToApply=0;
        CMPICount PropertiesToApplySize;
        try{
        CmpiData PropertiesToApplyCmpiData=in.getArg("PropertiesToApply");
        isPropertiesToApplyPresent=!PropertiesToApplyCmpiData.isNullValue();
        CmpiArray PropertiesToApplyCmpi=PropertiesToApplyCmpiData;
        PropertiesToApplySize=PropertiesToApplyCmpi.size();
        ArrayConverter::makeArray(PropertiesToApplyCmpi,
         &PropertiesToApply, PropertiesToApplySize);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };        
        rslt.returnData(CmpiData(interfaceP->ApplyIncrementalChangeToMSE(
         ctx,
         cppBroker,
         instanceName,
         MSE,
         isMSEPresent,
         TimeToApply,
         isTimeToApplyPresent,
         MustBeCompletedBy,
         isMustBeCompletedByPresent,
         (const char**) PropertiesToApply,
         PropertiesToApplySize,
         isPropertiesToApplyPresent)));
        if(PropertiesToApply)
          ArrayConverter::destructArray(PropertiesToApply, PropertiesToApplySize);
        cout<<"end of method ApplyIncrementalChangeToMSE"<<endl;     
      }else if (strcasecmp(methodName,"ApplyToCollection")==0){
        cout<<"executing method ApplyToCollection"<<endl;
        
        int isCollectionPresent=0;
        CIM_CollectionOfMSEsInstanceName  Collection;
        try{
        CmpiData CollectionCmpiData=in.getArg("Collection");
        isCollectionPresent=!CollectionCmpiData.isNullValue();
        CmpiObjectPath CollectionCmpi=CollectionCmpiData;
        Collection=CIM_CollectionOfMSEsInstanceName(CollectionCmpi);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isTimeToApplyPresent=0;
        CmpiDateTime TimeToApply;
        try{
        CmpiData TimeToApplyCmpiData=in.getArg("TimeToApply");
        isTimeToApplyPresent=!TimeToApplyCmpiData.isNullValue();
         TimeToApply=TimeToApplyCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isContinueOnErrorPresent=0;
        CMPIBoolean ContinueOnError;
        try{
        CmpiData ContinueOnErrorCmpiData=in.getArg("ContinueOnError");
        isContinueOnErrorPresent=!ContinueOnErrorCmpiData.isNullValue();
         ContinueOnError=ContinueOnErrorCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isMustBeCompletedByPresent=0;
        CmpiDateTime MustBeCompletedBy;
        try{
        CmpiData MustBeCompletedByCmpiData=in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent=!MustBeCompletedByCmpiData.isNullValue();
         MustBeCompletedBy=MustBeCompletedByCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };char** CanNotApply;
        CMPICount CanNotApplySize;
                
        rslt.returnData(CmpiData(interfaceP->ApplyToCollection(
         ctx,
         cppBroker,
         instanceName,
         Collection,
         isCollectionPresent,
         TimeToApply,
         isTimeToApplyPresent,
         ContinueOnError,
         isContinueOnErrorPresent,
         MustBeCompletedBy,
         isMustBeCompletedByPresent,
         CanNotApply,
         CanNotApplySize)));
        out.setArg("CanNotApply", CmpiData(ArrayConverter::makeCmpiArray((const char**) CanNotApply, CanNotApplySize)));
        if(CanNotApply)
          ArrayConverter::destructArray(CanNotApply, CanNotApplySize);
        cout<<"end of method ApplyToCollection"<<endl;     
      }else if (strcasecmp(methodName,"ApplyToMSE")==0){
        cout<<"executing method ApplyToMSE"<<endl;
        
        int isMSEPresent=0;
        CIM_ManagedSystemElementInstanceName  MSE;
        try{
        CmpiData MSECmpiData=in.getArg("MSE");
        isMSEPresent=!MSECmpiData.isNullValue();
        CmpiObjectPath MSECmpi=MSECmpiData;
        MSE=CIM_ManagedSystemElementInstanceName(MSECmpi);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isTimeToApplyPresent=0;
        CmpiDateTime TimeToApply;
        try{
        CmpiData TimeToApplyCmpiData=in.getArg("TimeToApply");
        isTimeToApplyPresent=!TimeToApplyCmpiData.isNullValue();
         TimeToApply=TimeToApplyCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isMustBeCompletedByPresent=0;
        CmpiDateTime MustBeCompletedBy;
        try{
        CmpiData MustBeCompletedByCmpiData=in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent=!MustBeCompletedByCmpiData.isNullValue();
         MustBeCompletedBy=MustBeCompletedByCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };        
        rslt.returnData(CmpiData(interfaceP->ApplyToMSE(
         ctx,
         cppBroker,
         instanceName,
         MSE,
         isMSEPresent,
         TimeToApply,
         isTimeToApplyPresent,
         MustBeCompletedBy,
         isMustBeCompletedByPresent)));
        cout<<"end of method ApplyToMSE"<<endl;     
      }else if (strcasecmp(methodName,"VerifyOKToApplyIncrementalChangeToCollection")==0){
        cout<<"executing method VerifyOKToApplyIncrementalChangeToCollection"<<endl;
        
        int isCollectionPresent=0;
        CIM_CollectionOfMSEsInstanceName  Collection;
        try{
        CmpiData CollectionCmpiData=in.getArg("Collection");
        isCollectionPresent=!CollectionCmpiData.isNullValue();
        CmpiObjectPath CollectionCmpi=CollectionCmpiData;
        Collection=CIM_CollectionOfMSEsInstanceName(CollectionCmpi);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isTimeToApplyPresent=0;
        CmpiDateTime TimeToApply;
        try{
        CmpiData TimeToApplyCmpiData=in.getArg("TimeToApply");
        isTimeToApplyPresent=!TimeToApplyCmpiData.isNullValue();
         TimeToApply=TimeToApplyCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isMustBeCompletedByPresent=0;
        CmpiDateTime MustBeCompletedBy;
        try{
        CmpiData MustBeCompletedByCmpiData=in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent=!MustBeCompletedByCmpiData.isNullValue();
         MustBeCompletedBy=MustBeCompletedByCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isPropertiesToApplyPresent=0;
        char** PropertiesToApply=0;
        CMPICount PropertiesToApplySize;
        try{
        CmpiData PropertiesToApplyCmpiData=in.getArg("PropertiesToApply");
        isPropertiesToApplyPresent=!PropertiesToApplyCmpiData.isNullValue();
        CmpiArray PropertiesToApplyCmpi=PropertiesToApplyCmpiData;
        PropertiesToApplySize=PropertiesToApplyCmpi.size();
        ArrayConverter::makeArray(PropertiesToApplyCmpi,
         &PropertiesToApply, PropertiesToApplySize);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };char** CanNotApply;
        CMPICount CanNotApplySize;
                
        rslt.returnData(CmpiData(interfaceP->VerifyOKToApplyIncrementalChangeToCollection(
         ctx,
         cppBroker,
         instanceName,
         Collection,
         isCollectionPresent,
         TimeToApply,
         isTimeToApplyPresent,
         MustBeCompletedBy,
         isMustBeCompletedByPresent,
         (const char**) PropertiesToApply,
         PropertiesToApplySize,
         isPropertiesToApplyPresent,
         CanNotApply,
         CanNotApplySize)));
        out.setArg("CanNotApply", CmpiData(ArrayConverter::makeCmpiArray((const char**) CanNotApply, CanNotApplySize)));
        if(PropertiesToApply)
          ArrayConverter::destructArray(PropertiesToApply, PropertiesToApplySize);
        if(CanNotApply)
          ArrayConverter::destructArray(CanNotApply, CanNotApplySize);
        cout<<"end of method VerifyOKToApplyIncrementalChangeToCollection"<<endl;     
      }else if (strcasecmp(methodName,"VerifyOKToApplyIncrementalChangeToMSE")==0){
        cout<<"executing method VerifyOKToApplyIncrementalChangeToMSE"<<endl;
        
        int isMSEPresent=0;
        CIM_ManagedSystemElementInstanceName  MSE;
        try{
        CmpiData MSECmpiData=in.getArg("MSE");
        isMSEPresent=!MSECmpiData.isNullValue();
        CmpiObjectPath MSECmpi=MSECmpiData;
        MSE=CIM_ManagedSystemElementInstanceName(MSECmpi);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isTimeToApplyPresent=0;
        CmpiDateTime TimeToApply;
        try{
        CmpiData TimeToApplyCmpiData=in.getArg("TimeToApply");
        isTimeToApplyPresent=!TimeToApplyCmpiData.isNullValue();
         TimeToApply=TimeToApplyCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isMustBeCompletedByPresent=0;
        CmpiDateTime MustBeCompletedBy;
        try{
        CmpiData MustBeCompletedByCmpiData=in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent=!MustBeCompletedByCmpiData.isNullValue();
         MustBeCompletedBy=MustBeCompletedByCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isPropertiesToApplyPresent=0;
        char** PropertiesToApply=0;
        CMPICount PropertiesToApplySize;
        try{
        CmpiData PropertiesToApplyCmpiData=in.getArg("PropertiesToApply");
        isPropertiesToApplyPresent=!PropertiesToApplyCmpiData.isNullValue();
        CmpiArray PropertiesToApplyCmpi=PropertiesToApplyCmpiData;
        PropertiesToApplySize=PropertiesToApplyCmpi.size();
        ArrayConverter::makeArray(PropertiesToApplyCmpi,
         &PropertiesToApply, PropertiesToApplySize);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };        
        rslt.returnData(CmpiData(interfaceP->VerifyOKToApplyIncrementalChangeToMSE(
         ctx,
         cppBroker,
         instanceName,
         MSE,
         isMSEPresent,
         TimeToApply,
         isTimeToApplyPresent,
         MustBeCompletedBy,
         isMustBeCompletedByPresent,
         (const char**) PropertiesToApply,
         PropertiesToApplySize,
         isPropertiesToApplyPresent)));
        if(PropertiesToApply)
          ArrayConverter::destructArray(PropertiesToApply, PropertiesToApplySize);
        cout<<"end of method VerifyOKToApplyIncrementalChangeToMSE"<<endl;     
      }else if (strcasecmp(methodName,"VerifyOKToApplyToCollection")==0){
        cout<<"executing method VerifyOKToApplyToCollection"<<endl;
        
        int isCollectionPresent=0;
        CIM_CollectionOfMSEsInstanceName  Collection;
        try{
        CmpiData CollectionCmpiData=in.getArg("Collection");
        isCollectionPresent=!CollectionCmpiData.isNullValue();
        CmpiObjectPath CollectionCmpi=CollectionCmpiData;
        Collection=CIM_CollectionOfMSEsInstanceName(CollectionCmpi);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isTimeToApplyPresent=0;
        CmpiDateTime TimeToApply;
        try{
        CmpiData TimeToApplyCmpiData=in.getArg("TimeToApply");
        isTimeToApplyPresent=!TimeToApplyCmpiData.isNullValue();
         TimeToApply=TimeToApplyCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isMustBeCompletedByPresent=0;
        CmpiDateTime MustBeCompletedBy;
        try{
        CmpiData MustBeCompletedByCmpiData=in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent=!MustBeCompletedByCmpiData.isNullValue();
         MustBeCompletedBy=MustBeCompletedByCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };char** CanNotApply;
        CMPICount CanNotApplySize;
                
        rslt.returnData(CmpiData(interfaceP->VerifyOKToApplyToCollection(
         ctx,
         cppBroker,
         instanceName,
         Collection,
         isCollectionPresent,
         TimeToApply,
         isTimeToApplyPresent,
         MustBeCompletedBy,
         isMustBeCompletedByPresent,
         CanNotApply,
         CanNotApplySize)));
        out.setArg("CanNotApply", CmpiData(ArrayConverter::makeCmpiArray((const char**) CanNotApply, CanNotApplySize)));
        if(CanNotApply)
          ArrayConverter::destructArray(CanNotApply, CanNotApplySize);
        cout<<"end of method VerifyOKToApplyToCollection"<<endl;     
      }else if (strcasecmp(methodName,"VerifyOKToApplyToMSE")==0){
        cout<<"executing method VerifyOKToApplyToMSE"<<endl;
        
        int isMSEPresent=0;
        CIM_ManagedSystemElementInstanceName  MSE;
        try{
        CmpiData MSECmpiData=in.getArg("MSE");
        isMSEPresent=!MSECmpiData.isNullValue();
        CmpiObjectPath MSECmpi=MSECmpiData;
        MSE=CIM_ManagedSystemElementInstanceName(MSECmpi);
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isTimeToApplyPresent=0;
        CmpiDateTime TimeToApply;
        try{
        CmpiData TimeToApplyCmpiData=in.getArg("TimeToApply");
        isTimeToApplyPresent=!TimeToApplyCmpiData.isNullValue();
         TimeToApply=TimeToApplyCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };
        int isMustBeCompletedByPresent=0;
        CmpiDateTime MustBeCompletedBy;
        try{
        CmpiData MustBeCompletedByCmpiData=in.getArg("MustBeCompletedBy");
        isMustBeCompletedByPresent=!MustBeCompletedByCmpiData.isNullValue();
         MustBeCompletedBy=MustBeCompletedByCmpiData;
        }catch(const CmpiStatus& rc){
        //parameter not present
          
        };        
        rslt.returnData(CmpiData(interfaceP->VerifyOKToApplyToMSE(
         ctx,
         cppBroker,
         instanceName,
         MSE,
         isMSEPresent,
         TimeToApply,
         isTimeToApplyPresent,
         MustBeCompletedBy,
         isMustBeCompletedByPresent)));
        cout<<"end of method VerifyOKToApplyToMSE"<<endl;     
      }else {
     rslt.returnDone();
      return CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::METHOD_NOT_FOUND,
   	   "Method not available");
    }
      
    rslt.returnDone();
    return CmpiStatus(CMPI_RC_OK);      
  };
 
}	

