/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "Internode-definitions"
 * 	found in "../asn/Internode-definitions.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_CodeChangeStatusList_H_
#define	_CodeChangeStatusList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CodeChangeStatus;

/* CodeChangeStatusList */
typedef struct CodeChangeStatusList {
	A_SEQUENCE_OF(struct CodeChangeStatus) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CodeChangeStatusList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CodeChangeStatusList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CodeChangeStatus.h"

#endif	/* _CodeChangeStatusList_H_ */
#include <asn_internal.h>
