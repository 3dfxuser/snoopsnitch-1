/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_AzimuthAndElevation_va40ext_H_
#define	_AzimuthAndElevation_va40ext_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* AzimuthAndElevation-va40ext */
typedef struct AzimuthAndElevation_va40ext {
	long	 azimuthLSB;
	long	 elevationLSB;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AzimuthAndElevation_va40ext_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AzimuthAndElevation_va40ext;

#ifdef __cplusplus
}
#endif

#endif	/* _AzimuthAndElevation_va40ext_H_ */
#include <asn_internal.h>
