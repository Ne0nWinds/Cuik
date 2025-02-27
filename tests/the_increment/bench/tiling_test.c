#include <stddef.h>

#if 1
int test(int a, int b) {
    int x, y, z;

    if(a > 3) {
        x = 4;
        y = 1;
        z = b & 0xFF00;
    }
    else {
        x = 9;
        y = 2;
        z = b << 8;
    }

    int p = (x * y) * 4;
    int q = z & 0xF;
    return p >= 16 && q == 0;
}

#else
size_t foo(size_t* a, size_t n) {
	size_t b = 0;
	for (size_t i = 0; i < n; i++) {
		b += a[i];
	}
    return b;
}

static size_t bar(size_t a) {
    return a % 2 != 0 ? 4 : 2;
}

size_t foo(size_t a) {
    return a % 2 != 0 ? 4 : 2;
}

void foo(size_t* a, size_t* b, size_t c) {
	a[c] += 16;
	b[c] += 16;
}

void foo(size_t* a, size_t b) {
	a[b] += 16;
}
#endif
