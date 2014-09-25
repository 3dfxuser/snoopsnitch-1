/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "Internode-definitions"
 * 	found in "../asn/Internode-definitions.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_CipheringInfoPerRB_r4_H_
#define	_CipheringInfoPerRB_r4_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RB-Identity.h"
#include <BIT_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CipheringInfoPerRB-r4 */
typedef struct CipheringInfoPerRB_r4 {
	RB_Identity_t	 rb_Identity;
	BIT_STRING_t	 dl_HFN;
	BIT_STRING_t	*dl_UM_SN	/* OPTIONAL */;
	BIT_STRING_t	 ul_HFN;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CipheringInfoPerRB_r4_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CipheringInfoPerRB_r4;

#ifdef __cplusplus
}
#endif

#endif	/* _CipheringInfoPerRB_r4_H_ */
#include <asn_internal.h>