// ============================================================================
// (C) Copyright IBM Corp. 2005
//
// THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
// ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
// CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
//
// You can obtain a current copy of the Eclipse Public License from
// http://opensource.org/licenses/eclipse-1.0.txt
//
// Authors:       Dr. Gareth S. Bestor, <bestorga@us.ibm.com>
// Contributors:
// Description:
// ============================================================================

/* Include the required CMPI data types, function headers, and macros */
#include <cmpidt.h>
#include <cmpift.h>
#include <cmpimacs.h>
#include <stdio.h>

#ifdef CMPI_VER_100
#define Linux_DnsRegisteredProfile_SetInstance Linux_DnsRegisteredProfile_ModifyInstance 
#endif


// ----------------------------------------------------------------------------
// COMMON GLOBAL VARIABLES
// ----------------------------------------------------------------------------

/* Handle to the CIM broker. Initialized when the provider lib is loaded. */
static const CMPIBroker *_BROKER;


// ============================================================================
// CMPI INSTANCE PROVIDER FUNCTION TABLE
// ============================================================================

// ----------------------------------------------------------------------------
// Info for the class supported by the instance provider
// ----------------------------------------------------------------------------

/* Name of the class implemented by this instance provider. */
/*** CUSTOMIZE FOR EACH PROVIDER ***/
static const char * _CLASSNAME    = "Linux_DnsRegisteredProfile";

/* Profile information */
static int _PROFILE_REGISTERED_ORGANIZATION          = 1; /* other */
static char * _PROFILE_OTHER_REGISTERED_ORGANIZATION = "IBM";
static char * _PROFILE_REGISTERED_NAME               = "DNS Profile";
static char * _PROFILE_RGISTERED_VERSION             = "0.2.3";
static int _PROFILE_ADVERTISE_TYPE                   = 3; /* SLP */

/* NULL terminated list of key properties of this class. */
static const char * _KEYNAMES[] = {"InstanceID", NULL};


//----------------------------------------------------------------------------
// Helper function to set the instance properties
//----------------------------------------------------------------------------
static void setInstanceData(const CMPIBroker * broker, const CMPIInstance * instance) {
   /* Set the CMPIInstance properties from the resource data. */
   CMSetProperty(instance, "RegisteredName",(CMPIValue *)_PROFILE_REGISTERED_NAME, CMPI_chars);
   CMSetProperty(instance, "RegisteredVersion",(CMPIValue *)_PROFILE_RGISTERED_VERSION, CMPI_chars);

   CMPIArray * advertisetypes = CMNewArray(broker, 1, CMPI_uint16, NULL);
   CMSetArrayElementAt(advertisetypes, 0, (CMPIValue *)&_PROFILE_ADVERTISE_TYPE, CMPI_uint16);
   CMSetProperty(instance, "AdvertiseTypes",(CMPIValue *)&advertisetypes, CMPI_uint16A);

   CMSetProperty(instance, "RegisteredOrganization",(CMPIValue *)&_PROFILE_REGISTERED_ORGANIZATION, CMPI_uint16);
   CMSetProperty(instance, "OtherRegisteredOrganization",(CMPIValue *)_PROFILE_OTHER_REGISTERED_ORGANIZATION, CMPI_chars);

   char instanceid[1024];
   sprintf(instanceid, "%s:%s-%s", _PROFILE_OTHER_REGISTERED_ORGANIZATION, _PROFILE_REGISTERED_NAME, _PROFILE_RGISTERED_VERSION); 
   CMSetProperty(instance, "InstanceID",(CMPIValue *)instanceid, CMPI_chars);	
};

// ----------------------------------------------------------------------------
// EnumInstanceNames()
// Return a list of all the instances names (return their object paths only).
// ----------------------------------------------------------------------------
CMPIStatus Linux_DnsRegisteredProfile_EnumInstanceNames(
		CMPIInstanceMI * self,
		const CMPIContext * context,
		const CMPIResult * results,
		const CMPIObjectPath * reference)
{
   CMPIStatus status = {CMPI_RC_OK, NULL};	/* Return status of CIM operations. */
   CMPIInstance * instance = NULL;
   CMPIObjectPath * op = NULL;
   char * lnamespace = CMGetCharPtr(CMGetNameSpace(reference, &status)); /* Target namespace. */

   /* Create a new CMPIObjectPath to store this resource. */
  op = CMNewObjectPath( _BROKER, lnamespace, _CLASSNAME, &status);
  if( CMIsNullObject(op) ) { 
    CMSetStatusWithChars( _BROKER, &status, CMPI_RC_ERR_FAILED, "Create CMPIObjectPath failed." ); 
    goto exit; 
  }

   /* Create a new CMPIInstance to store this resource. */
  instance = CMNewInstance( _BROKER, op, &status);
  if( CMIsNullObject(instance) ) {
    CMSetStatusWithChars( _BROKER, &status, CMPI_RC_ERR_FAILED, "Create CMPIInstance failed." ); 
    goto exit; 
  }

   setInstanceData(_BROKER, instance);

   /* Return the CMPIObjectPath for this instance. */
   CMPIObjectPath * objectpath = CMGetObjectPath(instance, &status);
   if ((status.rc != CMPI_RC_OK) || CMIsNullObject(objectpath)) {
      CMSetStatusWithChars(_BROKER, &status, CMPI_RC_ERR_FAILED, "Cannot get CMPIObjectPath for instance");
      goto exit;
   }
   CMSetNameSpace(objectpath, lnamespace); /* Note - CMGetObjectPath() does not preserve the namespace! */
     
   CMReturnObjectPath(results, objectpath);

   CMReturnDone(results);

exit:
  
   return status;
}

// ----------------------------------------------------------------------------
// EnumInstances()
// Return a list of all the instances (return all the instance data).
// ----------------------------------------------------------------------------
CMPIStatus Linux_DnsRegisteredProfile_EnumInstances(
		CMPIInstanceMI * self,
		const CMPIContext * context,
		const CMPIResult * results,
		const CMPIObjectPath * reference,
		const char ** properties)
{
   CMPIStatus status = {CMPI_RC_OK, NULL};
   CMPIInstance * instance = NULL;
   CMPIObjectPath * op = NULL;
   char * lnamespace = CMGetCharPtr(CMGetNameSpace(reference, &status));

   /* Create a new CMPIObjectPath to store this resource. */
  op = CMNewObjectPath( _BROKER, lnamespace, _CLASSNAME, &status);
  if( CMIsNullObject(op) ) { 
    CMSetStatusWithChars( _BROKER, &status, CMPI_RC_ERR_FAILED, "Create CMPIObjectPath failed." ); 
    goto exit; 
  }

   /* Create a new CMPIInstance to store this resource. */
  instance = CMNewInstance( _BROKER, op, &status);
  if( CMIsNullObject(instance) ) {
    CMSetStatusWithChars( _BROKER, &status, CMPI_RC_ERR_FAILED, "Create CMPIInstance failed." ); 
    goto exit; 
  }

   /* Setup a filter to only return the desired properties. */
   status = CMSetPropertyFilter(instance, properties, _KEYNAMES);
   if (status.rc != CMPI_RC_OK) {
      CMSetStatusWithChars(_BROKER, &status, CMPI_RC_ERR_FAILED, "Cannot set property filter");
      goto exit;
   }
   
   setInstanceData(_BROKER, instance);
   
   CMReturnInstance(results, instance);

   CMReturnDone(results);

exit:
   return status;
}

// ----------------------------------------------------------------------------
// GetInstance()
// Return the instance data for the specified instance only.
// ----------------------------------------------------------------------------
CMPIStatus Linux_DnsRegisteredProfile_GetInstance(
		CMPIInstanceMI * self,
		const CMPIContext * context,
		const CMPIResult * results,
		const CMPIObjectPath * reference,
		const char ** properties)
{
   CMPIStatus status = {CMPI_RC_OK, NULL};	/* Return status of CIM operations. */
   CMPIInstance * instance = NULL;
   CMPIObjectPath * op = NULL;
   char * lnamespace = CMGetCharPtr(CMGetNameSpace(reference, &status));

   /* Create a new CMPIObjectPath to store this resource. */
  op = CMNewObjectPath( _BROKER, lnamespace, _CLASSNAME, &status);
  if( CMIsNullObject(op) ) { 
    CMSetStatusWithChars( _BROKER, &status, CMPI_RC_ERR_FAILED, "Create CMPIObjectPath failed." ); 
    goto exit; 
  }

   /* Create a new CMPIInstance to store this resource. */
  instance = CMNewInstance( _BROKER, op, &status);
  if( CMIsNullObject(instance) ) {
    CMSetStatusWithChars( _BROKER, &status, CMPI_RC_ERR_FAILED, "Create CMPIInstance failed." ); 
    goto exit; 
  }

   /* Setup a filter to only return the desired properties. */
   status = CMSetPropertyFilter(instance, properties, _KEYNAMES);
   if (status.rc != CMPI_RC_OK) {
      CMSetStatusWithChars(_BROKER, &status, CMPI_RC_ERR_FAILED, "Cannot set property filter");
      goto exit;
   }

   setInstanceData(_BROKER, instance);
   CMReturnInstance(results, instance);
   CMReturnDone(results);
exit:

   return status;
}

// ----------------------------------------------------------------------------
// SetInstance()
// Save modified instance data fir the specified instance.
// ----------------------------------------------------------------------------
CMPIStatus Linux_DnsRegisteredProfile_SetInstance(
		CMPIInstanceMI * self,
		const CMPIContext * context,
		const CMPIResult * results,
		const CMPIObjectPath * reference,
		const CMPIInstance * newinstance,
		const char ** properties)
{
   CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

// ----------------------------------------------------------------------------
// CreateInstance()
// Create a new instance from the specified instance data.
// ----------------------------------------------------------------------------
CMPIStatus Linux_DnsRegisteredProfile_CreateInstance(
		CMPIInstanceMI * self,
		const CMPIContext * context,
		const CMPIResult * results,
		const CMPIObjectPath * reference,
		const CMPIInstance * newinstance)
{
   CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

// ----------------------------------------------------------------------------
// DeleteInstance()
// Delete or remove the specified instance from the system.
// ----------------------------------------------------------------------------
CMPIStatus Linux_DnsRegisteredProfile_DeleteInstance(
		CMPIInstanceMI * self,
		const CMPIContext * context,
		const CMPIResult * results,
		const CMPIObjectPath * reference)
{
   CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}


CMPIStatus Linux_DnsRegisteredProfile_ExecQuery(
		CMPIInstanceMI * self,
		const CMPIContext * context,
		const CMPIResult * results,
		const CMPIObjectPath * reference,
		const char * language,
		const char * query)
{
   CMReturn(CMPI_RC_ERR_NOT_SUPPORTED);
}

CMPIStatus Linux_DnsRegisteredProfile_Cleanup(
		CMPIInstanceMI * mi, 
        const CMPIContext * ctx,
        const CMPIBoolean terminating) { 
  CMReturn(CMPI_RC_OK);
}

// ============================================================================
// CMPI INSTANCE PROVIDER FUNCTION TABLE SETUP
// ============================================================================
CMInstanceMIStub( Linux_DnsRegisteredProfile_, CmpiLinux_DnsRegisteredProfileProvider, _BROKER, CMNoHook);
