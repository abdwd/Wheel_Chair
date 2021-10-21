#ifndef LDR_H_
#define LDR_H_

#include "ADC_interface.h"
#include <stdint.h>

typedef struct {
	u8 pin;
}LDR;

void LDR_init();
u16 LDR_read(LDR* ldr);





#endif /* LDR_H_ */