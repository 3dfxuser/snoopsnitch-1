/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext_H_
#define	_UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>
#include <NativeEnumerated.h>
#include "GanssRequestedGenericAssistanceDataList-v860ext.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext__ganssEOPreq {
	UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext__ganssEOPreq_true	= 0
} e_UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext__ganssEOPreq;

/* UE-Positioning-GANSS-AdditionalAssistanceDataRequest-v860ext */
typedef struct UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext {
	BIT_STRING_t	*ganssAddIonoModelReq	/* OPTIONAL */;
	long	*ganssEOPreq	/* OPTIONAL */;
	GanssRequestedGenericAssistanceDataList_v860ext_t	 ganssRequestedGenericAssistanceDataList;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_ganssEOPreq_3;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext;

#ifdef __cplusplus
}
#endif

#endif	/* _UE_Positioning_GANSS_AdditionalAssistanceDataRequest_v860ext_H_ */
#include <asn_internal.h>
