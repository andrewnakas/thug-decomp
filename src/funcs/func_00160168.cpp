struct Range_00160168 {
    unsigned char lo[4];
    unsigned char hi[4];
};

struct Sum_00160168 {
    float n;
    float x, y, z, w;
};

extern "C" void func_001600A0(Sum_00160168* out, void* grid, Range_00160168* range);

extern "C" float func_00160168(void* grid, Range_00160168* range, int axis, int* best_i, Sum_00160168* total)
{
    float best = 0.0f;
    float prev = 0.0f;
    *best_i = -1;
    Range_00160168 r = *range;
    int i;
    Sum_00160168 s;
    Sum_00160168 d;
    switch (axis) {
    case 1:
        for (i = range->lo[0]; i < range->hi[0]; i++) {
            r.hi[0] = i;
            func_001600A0(&s, grid, &r);
            d.x = total->x - s.x;
            d.y = total->y - s.y;
            d.z = total->z - s.z;
            d.w = total->w - s.w;
            d.n = total->n - s.n;
            if (0.0f < s.n && 0.0f < d.n) {
                float v = (s.x * s.x + s.y * s.y + s.z * s.z + s.w * s.w) / s.n;
                v += (d.x * d.x + d.y * d.y + d.z * d.z + d.w * d.w) / d.n;
                if (best < v) {
                    best = v;
                    *best_i = i;
                } else if (v < prev) {
                    break;
                }
                prev = v;
            }
        }
        break;
    case 2:
        for (i = range->lo[1]; i < range->hi[1]; i++) {
            r.hi[1] = i;
            func_001600A0(&s, grid, &r);
            d.x = total->x - s.x;
            d.y = total->y - s.y;
            d.z = total->z - s.z;
            d.w = total->w - s.w;
            d.n = total->n - s.n;
            if (0.0f < s.n && 0.0f < d.n) {
                float v = (s.x * s.x + s.y * s.y + s.z * s.z + s.w * s.w) / s.n;
                v += (d.x * d.x + d.y * d.y + d.z * d.z + d.w * d.w) / d.n;
                if (best < v) {
                    best = v;
                    *best_i = i;
                } else if (v < prev) {
                    break;
                }
                prev = v;
            }
        }
        break;
    case 3:
        for (i = range->lo[2]; i < range->hi[2]; i++) {
            r.hi[2] = i;
            func_001600A0(&s, grid, &r);
            d.x = total->x - s.x;
            d.y = total->y - s.y;
            d.z = total->z - s.z;
            d.w = total->w - s.w;
            d.n = total->n - s.n;
            if (0.0f < s.n && 0.0f < d.n) {
                float v = (s.x * s.x + s.y * s.y + s.z * s.z + s.w * s.w) / s.n;
                v += (d.x * d.x + d.y * d.y + d.z * d.z + d.w * d.w) / d.n;
                if (best < v) {
                    best = v;
                    *best_i = i;
                } else if (v < prev) {
                    break;
                }
                prev = v;
            }
        }
        break;
    case 4:
        for (i = range->lo[3]; i < range->hi[3]; i++) {
            r.hi[3] = i;
            func_001600A0(&s, grid, &r);
            d.x = total->x - s.x;
            d.y = total->y - s.y;
            d.z = total->z - s.z;
            d.w = total->w - s.w;
            d.n = total->n - s.n;
            if (0.0f < s.n && 0.0f < d.n) {
                float v = (s.x * s.x + s.y * s.y + s.z * s.z + s.w * s.w) / s.n;
                v += (d.x * d.x + d.y * d.y + d.z * d.z + d.w * d.w) / d.n;
                if (best < v) {
                    best = v;
                    *best_i = i;
                } else if (v < prev) {
                    break;
                }
                prev = v;
            }
        }
        break;
    }
    return best;
}
