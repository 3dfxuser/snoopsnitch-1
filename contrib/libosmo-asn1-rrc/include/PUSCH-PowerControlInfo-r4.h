/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_PUSCH_PowerControlInfo_r4_H_
#define	_PUSCH_PowerControlInfo_r4_H_


#include <asn_application.h>

/* Including external dependencies */
#include "UL-TargetSIR.h"
#include <NULL.h>
#include "TPC-StepSizeTDD.h"
#include <constr_SEQUENCE.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PUSCH_PowerControlInfo_r4__tddOption_PR {
	PUSCH_PowerControlInfo_r4__tddOption_PR_NOTHING,	/* No components present */
	PUSCH_PowerControlInfo_r4__tddOption_PR_tdd384,
	PUSCH_PowerControlInfo_r4__tddOption_PR_tdd128
} PUSCH_PowerControlInfo_r4__tddOption_PR;

/* PUSCH-PowerControlInfo-r4 */
typedef struct PUSCH_PowerControlInfo_r4 {
	UL_TargetSIR_t	 ul_TargetSIR;
	struct PUSCH_PowerControlInfo_r4__tddOption {
		PUSCH_PowerControlInfo_r4__tddOption_PR present;
		union PUSCH_PowerControlInfo_r4__tddOption_u {
			NULL_t	 tdd384;
			struct PUSCH_PowerControlInfo_r4__tddOption__tdd128 {
				TPC_StepSizeTDD_t	*tpc_StepSize	/* OPTIONAL */;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} tdd128;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} tddOption;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PUSCH_PowerControlInfo_r4_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PUSCH_PowerControlInfo_r4;

#ifdef __cplusplus
}
#endif

#endif	/* _PUSCH_PowerControlInfo_r4_H_ */
#include <asn_internal.h>