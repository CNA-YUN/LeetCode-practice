#include <stdio.h>
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    int k, b;
    if (coordinatesSize <= 2)return true;
    if (coordinates[0][0] == coordinates[1][0]) {
        for (int i = 2;i < coordinatesSize;i++) {
            if (coordinates[i][0] != coordinates[0][0])return false;
        }
        return true;
    }
    else {
        int dx1 = coordinates[1][0] - coordinates[0][0];
        int dy1 = coordinates[1][1] - coordinates[0][1];
        k = (coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]);
        b = coordinates[0][1] - k * coordinates[0][0];
        for (int i = 2;i < coordinatesSize;i++) {
            int dx2 = coordinates[i][0] - coordinates[0][0];
            int dy2 = coordinates[i][1] - coordinates[0][1];
            if (dy2*dx1!=dx2*dy1)return false;
        }
        return true;
    }

}
void problem1232() {
    int colsize = 2;
    int* coordinatesColSize = &colsize;
    int coordinates[][2] = {{2,1},{4,2},{6,3}};
    int* coords[3];
    for (int i = 0; i < 3; i++) {
        coords[i] = coordinates[i];
    }
    printf("%d\n", checkStraightLine(coords, 3, coordinatesColSize));
}