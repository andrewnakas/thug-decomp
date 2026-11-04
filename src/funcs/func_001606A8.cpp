struct Box_001606A8 {
    unsigned char min[4];
    unsigned char max[4];
};

struct Stats_001606A8 {
    float m[8];
};

struct Quant_001606A8 {
    char pad0[4];
    Stats_001606A8 Sum(Box_001606A8* box);
    int Split(Box_001606A8* box, Box_001606A8* out);
};

extern "C" float func_00160168(Quant_001606A8* self, Box_001606A8* box, int dim, int* cut, Stats_001606A8* s);

int Quant_001606A8::Split(Box_001606A8* box, Box_001606A8* out)
{
    Stats_001606A8 s = Sum(box);
    int c0, c1, c2, c3;
    float a = func_00160168(this, box, 1, &c0, &s);
    float b = func_00160168(this, box, 2, &c1, &s);
    float c = func_00160168(this, box, 3, &c2, &s);
    float d = func_00160168(this, box, 4, &c3, &s);
    if (a == 0.0f && b == 0.0f && c == 0.0f && d == 0.0f)
        return 0;
    *out = *box;
    if (b <= a) {
        if (c <= a) {
            if (d <= a) {
                out->min[0] = c0;
                box->max[0] = c0;
            } else {
                out->min[3] = c3;
                box->max[3] = c3;
            }
        } else {
            if (d <= c) {
                out->min[2] = c2;
                box->max[2] = c2;
            } else {
                out->min[3] = c3;
                box->max[3] = c3;
            }
        }
    } else {
        if (c <= b) {
            if (d <= b) {
                out->min[1] = c1;
                box->max[1] = c1;
            } else {
                out->min[3] = c3;
                box->max[3] = c3;
            }
        } else {
            if (d <= c) {
                out->min[2] = c2;
                box->max[2] = c2;
            } else {
                out->min[3] = c3;
                box->max[3] = c3;
            }
        }
    }
    return 1;
}
