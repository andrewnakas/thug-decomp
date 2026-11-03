typedef int qword __attribute__((mode(TI)));

struct Vec {
    union {
        float v[4];
        qword q;
    };
};

struct Box {
    Vec min;
    Vec max;
};

extern "C" int func_001023F0(Box* box, Vec* p, int* mask);

extern "C" void func_00102E58(Box* box, Vec* p, Vec* out)
{
    int mask;
    if (func_001023F0(box, p, &mask) == 3) {
        float best = -1.0f;
        float bestv = 0.0f;
        int besti = -1;
        for (int i = 0; i < 3; i++) {
            float dmin = p->v[i] - box->min.v[i];
            float dmax = box->max.v[i] - p->v[i];
            float d;
            float f;
            if (dmin < dmax) {
                d = dmin;
                f = box->min.v[i];
            } else {
                d = dmax;
                f = box->max.v[i];
            }
            if (i == 0 || d < best) {
                best = d;
                bestv = f;
                besti = i;
            }
        }
        out->q = p->q;
        out->v[besti] = bestv;
    } else {
        out->v[3] = 1.0f;
        for (int i = 0; i < 3; i++) {
            int bit = 1 << i;
            if (mask & bit) {
                out->v[i] = p->v[i];
            } else if (p->v[i] <= box->min.v[i]) {
                out->v[i] = box->min.v[i];
            } else {
                out->v[i] = box->max.v[i];
            }
        }
    }
}
