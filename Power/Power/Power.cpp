#include <stdio.h>
typedef  unsigned long long ULONG;

/**
 * base °öÇØÁú¼ö
 * exponent Áö¼ö
*/
ULONG Power( int base, int exponent) {

	if (exponent == 1)
		return base;
	else if (base == 0)
		return 1;

	if (exponent % 2 == 0) {//Â¦¼ö
		ULONG newBase = Power(base, exponent / 2);
		return newBase*newBase;
	}
	else {
		ULONG newBase = Power(base, (exponent - 1) / 2);
		return (newBase*newBase) * base;
	}
};

void main() {
	int base = 2;
	int exponent = 30;
	printf("%lld\n", Power(base, exponent));
}