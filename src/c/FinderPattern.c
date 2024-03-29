#include "../c/FinderPattern.h"
#include "./math.h"

float FinderPattern_distance(struct FinderPattern *p1, struct FinderPattern *p2)
{
    float dx = p1->posX - p2->posX;
    float dy = p1->posY - p2->posY;
    return (float)math_fsqrt(dx * dx + dy * dy);
}

float get_posX(struct FinderPattern *pat)
{
    return pat->posX;
}
float get_posY(struct FinderPattern *pat)
{
    return pat->posY;
}
float get_estimatedModuleSize(struct FinderPattern *pat)
{
    return pat->estimatedModuleSize;
}
int get_count(struct FinderPattern *pat)
{
    return pat->count;
}

void createFinderPattern(struct FinderPattern *pat, float posX, float posY, float estimatedModuleSize, int count)
{
    pat->posX = posX;
    pat->posY = posY;
    pat->estimatedModuleSize = estimatedModuleSize;
    pat->count = count;
}

struct FinderPattern combineEstimate(struct FinderPattern *from, float i, float j, float newModuleSize)
{
    struct FinderPattern to;
    to.count = from->count + 1;
    to.posX = (from->count * from->posX + j) / to.count;
    to.posY = (from->count * from->posY + i) / to.count;
    to.estimatedModuleSize = (from->count * from->estimatedModuleSize + newModuleSize) / to.count;
    return to;
}

bool aboutEquals(struct FinderPattern *pat, float moduleSize, float i, float j)
{
    if (math_fabs(i - pat->posY) <= moduleSize && math_fabs(j - pat->posX) <= moduleSize)
    {
        float moduleSizeDiff = math_fabs(moduleSize - pat->estimatedModuleSize);
        return moduleSizeDiff <= 1.0f || moduleSizeDiff <= pat->estimatedModuleSize;
    }
    return false;
}