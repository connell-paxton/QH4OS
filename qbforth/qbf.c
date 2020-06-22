#include "qbf.h"

void QBF_DebugPrint(qbf_head_t a) {
	uint8_t sign, size;
	switch(QBF_GET(a, TYPE)){
		case QBF_TYPE_NUM:
			sign = QBF_GET(a, NUM_SIGNED);
			size = 1 << (3 + QBF_GET(a, NUM_SIZE));
			printf("number is a %s %d-bit integer\n", (sign)?"signed":"unsigned", size);
		break;
		case QBF_TYPE_WORD:
			printf("WORD\n");
		break;
        default:
            printf("Other\n");
        break;
	}
}