#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct circle {
    double xpos; // 원의 중심 - x좌표
    double ypos; // 원의 중심 - y좌표
    double radius; // 원의 반지름
}circle;

double getDistance(double x1, double y1, double x2, double y2);
int getNumberIntersections(circle cir1, circle cir2);

int main(void)
{
    int count;
    int* arr;
    scanf("%d", &count);
    arr = (int*)malloc(sizeof(int) * count);

    circle cir1, cir2;

    for (int i = 0; i < count; i++) {
        scanf("%lf %lf %lf %lf %lf %lf", &cir1.xpos, &cir1.ypos, &cir1.radius, &cir2.xpos, &cir2.ypos, &cir2.radius);
        arr[i] = getNumberIntersections(cir1, cir2);
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}

double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
int getNumberIntersections(circle cir1, circle cir2) {
    int num;
    double distance = getDistance(cir1.xpos, cir1.ypos, cir2.xpos, cir2.ypos);

    if (abs(cir1.radius - cir2.radius) > distance) {
        num = 0;
    }
    else if (abs(cir1.radius - cir2.radius) == distance) {
        num = 1;
        if (cir1.radius == cir2.radius) {
            num = -1; // 무한대
        }
    }
    else if (abs(cir1.radius - cir2.radius) < distance && distance < (cir1.radius + cir2.radius)) {
        num = 2;
    }
    else if (distance == (cir1.radius + cir2.radius)) {
        num = 1;
    }
    else if (distance > (cir1.radius + cir2.radius)) {
        num = 0;
    }

    return num;
}
