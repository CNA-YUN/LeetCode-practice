#include <stdio.h>
void 百鸡问题() {
	for (int x = 0; x <= 20; x++) { // 公鸡
		for (int y = 0; y <= 33; y++) { // 母鸡
			int z = 100 - x - y; // 小鸡
			if (z % 3 == 0) { // 小鸡必须是3的倍数
				if (5 * x + 3 * y + z / 3 == 100) {
					printf("公鸡: %d只, 母鸡: %d只, 小鸡: %d只\n", x, y, z);
				}
			}
		}
	}
}