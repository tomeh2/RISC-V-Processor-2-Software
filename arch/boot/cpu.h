#pragma once

#define CSRR_READ(v, csr)                       \
__asm__ __volatile__ ("csrr %0, %1"             \
              : "=r" (v)                        \
              : "n" (csr)                       \
              : /* clobbers: none */ );
			  