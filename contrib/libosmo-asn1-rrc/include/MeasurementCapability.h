/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_MeasurementCapability_H_
#define	_MeasurementCapability_H_


#include <asn_application.h>

/* Including external dependencies */
#include "CompressedModeMeasCapability.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MeasurementCapability */
typedef struct MeasurementCapability {
	CompressedModeMeasCapability_t	 downlinkCompressedMode;
	CompressedModeMeasCapability_t	 uplinkCompressedMode;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasurementCapability_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MeasurementCapability;

#ifdef __cplusplus
}
#endif

#endif	/* _MeasurementCapability_H_ */
#include <asn_internal.h>
