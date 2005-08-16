 /**
 * Linux_DnsHintZoneDefaultImplementation.cpp
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
#include "Linux_DnsHintZoneDefaultImplementation.h"
#include <iostream>

using namespace std;

namespace genProvider {

  /* intrinsic methods */
  void Linux_DnsHintZoneDefaultImplementation::enumInstanceNames(
   const CmpiContext& ctx, const CmpiBroker &mbp, const char *nsp,
   Linux_DnsHintZoneInstanceNameEnumeration& instnames){
   	cout<<"enumInstances not supported for Linux_DnsHintZone"<<endl;
   	throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "enumInstances not implemented for Linux_DnsHintZone");   
  }
  	
  void Linux_DnsHintZoneDefaultImplementation::enumInstances(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char *nsp,
   const char* *properties,
   Linux_DnsHintZoneManualInstanceEnumeration& instances){
    
    cout<<"Using default enumInstances implementation for Linux_DnsHintZone"<<endl;
    cout<<"LetŽs get the instanceNames"<<endl;
    Linux_DnsHintZoneInstanceNameEnumeration namesEnumeration;
    enumInstanceNames(ctx, mbp,nsp,namesEnumeration);
    cout<<"Getting each instance"<<endl;
    while(namesEnumeration.hasNext()){
      Linux_DnsHintZoneInstanceName name=
    	  namesEnumeration.getNext();
    	cout<<"Getting an instance for instanceName"<<endl;
    	Linux_DnsHintZoneManualInstance instance=
    	  getInstance(ctx, mbp, properties, name);
    	cout<<"adding instance to enum"<<endl;
    	instances.addElement(instance);
    	cout<<"Added!"<<endl;
    };
  }
  	
  Linux_DnsHintZoneManualInstance 
   Linux_DnsHintZoneDefaultImplementation::getInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsHintZoneInstanceName&){
    cout<<"getInstance not supported for Linux_DnsHintZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "getInstance not implemented for Linux_DnsHintZone");
  }
  	
  void Linux_DnsHintZoneDefaultImplementation::setInstance(
   const CmpiContext& ctx,
   const CmpiBroker &mbp,
   const char* *properties,
   const Linux_DnsHintZoneManualInstance&){
   	cout<<"setInstance not supported for Linux_DnsHintZone"<<endl;
     throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "setInstance not implemented for Linux_DnsHintZone");
  }
  	
  void Linux_DnsHintZoneDefaultImplementation::
   createInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsHintZoneManualInstance&){
   	cout<<"createInstance not supported for Linux_DnsHintZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "createInstance not implemented for Linux_DnsHintZone");
  }
  	
  void Linux_DnsHintZoneDefaultImplementation::
   deleteInstance(const CmpiContext& ctx, const CmpiBroker &mbp,
   const Linux_DnsHintZoneInstanceName&){
   	cout<<"deleteInstance not supported for Linux_DnsHintZone"<<endl;
    throw CmpiErrorFormater::getErrorException(
   	 CmpiErrorFormater::NOT_IMPLEMENTED,
   	 "deleteInstance not implemented for Linux_DnsHintZone");
  }
	
  
  /* extrinsic methods */

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::ApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean &ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize){
      cout<<"ApplyIncrementalChangeToCollection() not supported in Linux_DnsHintZone"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "ApplyIncrementalChangeToCollection() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::ApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent){
      cout<<"ApplyIncrementalChangeToMSE() not supported in Linux_DnsHintZone"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "ApplyIncrementalChangeToMSE() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::ApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CMPIBoolean &ContinueOnError,
      int isContinueOnErrorPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize){
      cout<<"ApplyToCollection() not supported in Linux_DnsHintZone"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "ApplyToCollection() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::ApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent){
      cout<<"ApplyToMSE() not supported in Linux_DnsHintZone"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "ApplyToMSE() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::VerifyOKToApplyIncrementalChangeToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize){
      cout<<"VerifyOKToApplyIncrementalChangeToCollection() not supported in Linux_DnsHintZone"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "VerifyOKToApplyIncrementalChangeToCollection() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::VerifyOKToApplyIncrementalChangeToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      const char** PropertiesToApply,
      const CMPICount PropertiesToApplySize,
      int isPropertiesToApplyPresent){
      cout<<"VerifyOKToApplyIncrementalChangeToMSE() not supported in Linux_DnsHintZone"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "VerifyOKToApplyIncrementalChangeToMSE() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::VerifyOKToApplyToCollection(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_CollectionOfMSEsInstanceName &Collection,
      int isCollectionPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent,
      char** &CanNotApply,
      CMPICount &CanNotApplySize){
      cout<<"VerifyOKToApplyToCollection() not supported in Linux_DnsHintZone"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "VerifyOKToApplyToCollection() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::VerifyOKToApplyToMSE(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&,
      const CIM_ManagedSystemElementInstanceName &MSE,
      int isMSEPresent,
      const CmpiDateTime &TimeToApply,
      int isTimeToApplyPresent,
      const CmpiDateTime &MustBeCompletedBy,
      int isMustBeCompletedByPresent){
      cout<<"VerifyOKToApplyToMSE() not supported in Linux_DnsHintZone"<<endl;
   	  throw CmpiErrorFormater::getErrorException(
   	   CmpiErrorFormater::NOT_IMPLEMENTED,
   	   "VerifyOKToApplyToMSE() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::disable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&){
      cout<<"disable() not supported in Linux_DnsHintZone"<<endl;
          throw CmpiErrorFormater::getErrorException(
           CmpiErrorFormater::NOT_IMPLEMENTED,
           "disable() not implemented in Linux_DnsHintZone");
    };

    CMPIUint32 Linux_DnsHintZoneDefaultImplementation::enable(
     const CmpiContext& ctx, const CmpiBroker &mbp,
     const Linux_DnsHintZoneInstanceName&){
      cout<<"enable() not supported in Linux_DnsHintZone"<<endl;
          throw CmpiErrorFormater::getErrorException(
           CmpiErrorFormater::NOT_IMPLEMENTED,
           "enable() not implemented in Linux_DnsHintZone");
    };

}

