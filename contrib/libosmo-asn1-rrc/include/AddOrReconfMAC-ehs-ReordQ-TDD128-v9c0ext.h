/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_AddOrReconfMAC_ehs_ReordQ_TDD128_v9c0ext_H_
#define	_AddOrReconfMAC_ehs_ReordQ_TDD128_v9c0ext_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MAC_ehs_AddReconfReordQ_List_TDD128_v9c0ext;

/* AddOrReconfMAC-ehs-ReordQ-TDD128-v9c0ext */
typedef struct AddOrReconfMAC_ehs_ReordQ_TDD128_v9c0ext {
	struct MAC_ehs_AddReconfReordQ_List_TDD128_v9c0ext	*mac_ehs_AddReconfQueue_List	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AddOrReconfMAC_ehs_ReordQ_TDD128_v9c0ext_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AddOrReconfMAC_ehs_ReordQ_TDD128_v9c0ext;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MAC-ehs-AddReconfReordQ-List-TDD128-v9c0ext.h"

#endif	/* _AddOrReconfMAC_ehs_ReordQ_TDD128_v9c0ext_H_ */
#include <asn_internal.h>
