#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PI
#define PI 3.14159265359
#endif 

#ifndef FX_PRECISION
#define FX_PRECISION 16
#endif  



void jaguar_n_tbl_init_int(int64_t n_tbl[4]) {

	n_tbl[0] = (int64_t)((1 / cos(4 * PI / 16)) * (1 << FX_PRECISION)); // 1.4142;
	n_tbl[1] = (int64_t)((cos(2 * PI / 16) + cos(6 * PI / 16)) * (1 << FX_PRECISION)); // 1.3066;
	n_tbl[2] = (int64_t)((cos(2 * PI / 16) - cos(6 * PI / 16)) * (1 << FX_PRECISION));// 0.5412;
	n_tbl[3] = (int64_t)(cos(6 * PI / 16) * (1 << FX_PRECISION)); // 0.3827;

}


void jaguar_qq_tbl_init_fp(double qq_tbl[8][8]) {

	unsigned x, y;
	double tmp;

	for (y = 0; y < 8; y++) {
		for (x = 0; x < 8; x++) {
			if (x == 0) tmp = 4 / sqrt(2.0);
			else tmp = (4 * cos(x * PI / 16.0));
			if (y == 0) tmp = tmp * 4 / sqrt(2.0);
			else tmp = tmp * (4 * cos(y * PI / 16.0));
			qq_tbl[y][x] = 1 * tmp;
		}
	}
}


void jaguar_idct_int2_8b(int* idct_in, int* idct_out, int64_t qq_tbl[8][8], int64_t n_tbl[4]) {



    printf("UNUTRA\n");

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
            printf("\t%d",idct_out[y * 8 + x]);
		}
        printf("\n");
	}
    printf("UNUTRA\n");




	int64_t out[8][8], tmp, tmp2;
	int64_t inter[64];
	int64_t dctf[64];
	unsigned int u, v, x, y;

	for (y = 0; y < 8; y++) {
		for (x = 0; x < 8; x++) {
			dctf[y * 8 + x] = idct_in[y * 8 + x] * qq_tbl[y][x];
		}
	}

	int64_t a0, a1, a2, a3, a4, a5, a6, a7;
	int64_t b0, b1, b2, b3, b4, b5, b6, b7;
	int64_t c0, c1, c2, c3, c4, c5, c6, c7, c8;
	int64_t d0, d1, d2, d3, d4, d5, d6, d7, d8;
	int64_t e0, e1, e2, e3, e4, e5, e6, e7;
	int64_t bb0, bb1, bb2, bb3, bb4, bb5, bb6, bb7;
	int64_t bbb0, bbb1, bbb2, bbb3, bbb4, bbb5, bbb6, bbb7;


	for (x = 0; x < 8; x++) {

		e0 = dctf[0 * 8 + x];
		e1 = dctf[4 * 8 + x];
		e2 = dctf[2 * 8 + x];
		e3 = dctf[6 * 8 + x];
		e4 = (dctf[5 * 8 + x] - dctf[3 * 8 + x]) / 2;
		e5 = (dctf[1 * 8 + x] + dctf[7 * 8 + x]) / 2;
		e6 = (dctf[1 * 8 + x] - dctf[7 * 8 + x]) / 2;
		e7 = (dctf[5 * 8 + x] + dctf[3 * 8 + x]) / 2;

		d0 = e0;
		d1 = e1;
		d2 = (e2 - e3) / 2;
		d3 = (e2 + e3) / 2;
		d4 = e4;
		d5 = (e5 - e7) / 2;
		d6 = e6;
		d7 = (e5 + e7) / 2;
		d8 = e6 - e4;

		c0 = d0;
		c1 = d1;
		c2 = (d2 * n_tbl[0]) >> FX_PRECISION;
		c3 = d3;
		c4 = (d4 * n_tbl[1]) >> FX_PRECISION;
		c5 = (d5 * n_tbl[0]) >> FX_PRECISION;
		c6 = (d6 * n_tbl[2]) >> FX_PRECISION;
		c7 = d7;
		c8 = (d8 * n_tbl[3]) >> FX_PRECISION;

		b0 = (c0 + c1) / 2;
		b1 = (c0 - c1) / 2;
		b2 = c2 - c3;
		b3 = c3;
		b4 = c4 + c8;
		b5 = c5;
		b6 = c6 + c8;
		b7 = c7;

		bb0 = b0;
		bb1 = b1;
		bb2 = b2;
		bb3 = b3;
		bb4 = b4;
		bb5 = b5;
		bb6 = b6 - b7;
		bb7 = b7;

		bbb0 = bb0;
		bbb1 = bb1;
		bbb2 = bb2;
		bbb3 = bb3;
		bbb4 = bb4;
		bbb5 = bb5 - bb6;
		bbb6 = bb6;
		bbb7 = bb7;

		a0 = (bbb0 + bbb3) / 2;
		a1 = (bbb1 + bbb2) / 2;
		a2 = (bbb1 - bbb2) / 2;
		a3 = (bbb0 - bbb3) / 2;
		a4 = bbb4 - bbb5;
		a5 = bbb5;
		a6 = bbb6;
		a7 = bbb7;

		out[0][x] = (a0 + a7) / 2;
		out[1][x] = (a1 + a6) / 2;
		out[2][x] = (a2 + a5) / 2;
		out[3][x] = (a3 + a4) / 2;
		out[4][x] = (a3 - a4) / 2;
		out[5][x] = (a2 - a5) / 2;
		out[6][x] = (a1 - a6) / 2;
		out[7][x] = (a0 - a7) / 2;
	}

	for (y = 0; y < 8; y++) {

		e0 = out[y][0];
		e1 = out[y][4];
		e2 = out[y][2];
		e3 = out[y][6];
		e4 = (out[y][5] - out[y][3]) / 2;
		e5 = (out[y][1] + out[y][7]) / 2;
		e6 = (out[y][1] - out[y][7]) / 2;
		e7 = (out[y][5] + out[y][3]) / 2;

		d0 = e0;
		d1 = e1;
		d2 = (e2 - e3) / 2;
		d3 = (e2 + e3) / 2;
		d4 = e4;
		d5 = (e5 - e7) / 2;
		d6 = e6;
		d7 = (e5 + e7) / 2;
		d8 = e6 - e4;

		c0 = d0;
		c1 = d1;
		c2 = (d2 * n_tbl[0]) >> FX_PRECISION;
		c3 = d3;
		c4 = (d4 * n_tbl[1]) >> FX_PRECISION;
		c5 = (d5 * n_tbl[0]) >> FX_PRECISION;
		c6 = (d6 * n_tbl[2]) >> FX_PRECISION;
		c7 = d7;
		c8 = (d8 * n_tbl[3]) >> FX_PRECISION;

		b0 = (c0 + c1) / 2;
		b1 = (c0 - c1) / 2;
		b2 = c2 - c3;
		b3 = c3;
		b4 = c4 + c8;
		b5 = c5;
		b6 = c6 + c8;
		b7 = c7;

		bb0 = b0;
		bb1 = b1;
		bb2 = b2;
		bb3 = b3;
		bb4 = b4;
		bb5 = b5;
		bb6 = b6 - b7;
		bb7 = b7;

		bbb0 = bb0;
		bbb1 = bb1;
		bbb2 = bb2;
		bbb3 = bb3;
		bbb4 = bb4;
		bbb5 = bb5 - bb6;
		bbb6 = bb6;
		bbb7 = bb7;

		a0 = (bbb0 + bbb3) / 2;
		a1 = (bbb1 + bbb2) / 2;
		a2 = (bbb1 - bbb2) / 2;
		a3 = (bbb0 - bbb3) / 2;
		a4 = bbb4 - bbb5;
		a5 = bbb5;
		a6 = bbb6;
		a7 = bbb7;

		out[y][0] = (a0 + a7) >> (FX_PRECISION);
		out[y][1] = (a1 + a6) >> (FX_PRECISION);
		out[y][2] = (a2 + a5) >> (FX_PRECISION);
		out[y][3] = (a3 + a4) >> (FX_PRECISION);
		out[y][4] = (a3 - a4) >> (FX_PRECISION);
		out[y][5] = (a2 - a5) >> (FX_PRECISION);
		out[y][6] = (a1 - a6) >> (FX_PRECISION);
		out[y][7] = (a0 - a7) >> (FX_PRECISION);

		// dijeljenje s 2 i zaokruivanje .. ako se izbaci onde gore ide >> (FX_PRECISION + 1)
		out[y][0] = (out[y][0] + 1) >> 1;
		out[y][1] = (out[y][1] + 1) >> 1;
		out[y][2] = (out[y][2] + 1) >> 1;
		out[y][3] = (out[y][3] + 1) >> 1;
		out[y][4] = (out[y][4] + 1) >> 1;
		out[y][5] = (out[y][5] + 1) >> 1;
		out[y][6] = (out[y][6] + 1) >> 1;
		out[y][7] = (out[y][7] + 1) >> 1;

	}
    printf("\n");

	for (y = 0; y < 8; y++) {
		for (x = 0; x < 8; x++) {
			idct_out[y * 8 + x] = out[y][x] + 128;
            printf("\t%d",idct_out[y * 8 + x]);
		}
        printf("\n");
	}
    printf("\n");

}

void main() {
    printf("Yes");
	double qqtbl_f[8][8];
    int idct_in[64];
    int idct_out[64];    
	int64_t ntbl_i[4];

    int* CB = (int*)calloc(64, sizeof(int));

	for (int i = 0; i < 64; i++) {
        idct_in[i]=i;
        idct_out[i]=i;
        CB[i]=i;
    }

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
            qqtbl_f[y][x]=x+y;
		}
	}

    printf("\n");

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
            printf("\t%d",idct_in[y * 8 + x]);
		}
        printf("\n");
	}
    printf("\n");

	jaguar_n_tbl_init_int(ntbl_i);
	jaguar_qq_tbl_init_fp(qqtbl_f[0]);
	jaguar_idct_int2_8b(&idct_in, &idct_out, qqtbl_f, ntbl_i);

    printf("Yes%d",idct_out[0]);


    printf("\n");

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
            printf("\t%d",idct_out[y * 8 + x]);
		}
        printf("\n");
	}
    printf("\n");

}
