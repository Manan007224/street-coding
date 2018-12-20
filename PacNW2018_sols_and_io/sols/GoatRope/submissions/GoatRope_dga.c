/* Goat Rope */
/* Ad hoc math */

#include <stdio.h>
#include <math.h>
#include <assert.h>

int main()
{
    double x, y, x1, y1, x2, y2, dx, dy;

    /* TODO: input format? */
    assert(scanf(" %lf %lf %lf %lf %lf %lf", &x, &y, &x1, &y1, &x2, &y2) == 6);
    assert(x1 < x2);
    assert(y1 < y2);
    assert(!(x1 <= x && x <= x2 && y1 <= y && y <= y2));

    dx = dy = 0;

    if (x < x1)
	dx = x1 - x;
    else if (x > x2)
	dx = x - x2;

    if (y < y1)
	dy = y1 - y;
    else if (y > y2)
	dy = y - y2;

    printf("%.03lf\n", hypot(dx, dy));
    return 0;
}
