typedef int qword __attribute__((mode(TI)));

union Vec_0029ABB8 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Grp_0029ABB8 {
    int m0;
    Grp_0029ABB8* next;
    char pad[0x10 - 0x8];
    int id;
};

extern "C" bool func_002998D0(Grp_0029ABB8* g, Vec_0029ABB8* p, Vec_0029ABB8* out, float* dist, int* idx, int skip);

struct Obj_0029ABB8 {
    char pad[0x24];
    Grp_0029ABB8* m24;
    bool FindNearest(Vec_0029ABB8* p, Vec_0029ABB8* out, float* outDist, int* outId, int* outIdx, int skipId, int skipIdx);
};

bool Obj_0029ABB8::FindNearest(Vec_0029ABB8* p, Vec_0029ABB8* out, float* outDist, int* outId, int* outIdx, int skipId, int skipIdx)
{
    bool found = false;
    float best = 100000000.0f;
    for (Grp_0029ABB8* g = m24; g; g = g->next) {
        Vec_0029ABB8 v;
        float d;
        int idx = 0;
        if (func_002998D0(g, p, &v, &d, &idx, g->id == skipId ? skipIdx : -1) && d < best) {
            best = d;
            found = true;
            out->q = v.q;
            *outDist = best;
            *outId = g->id;
            *outIdx = idx;
        }
    }
    return found;
}
