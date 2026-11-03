typedef int qword __attribute__((mode(TI)));

union Vec_002998D0 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Node_002998D0 {
    char pad[0x10];
    Vec_002998D0 pos;
    char pad2[0x2C - 0x20];
    Node_002998D0* next;
};

struct Obj_002998D0 {
    char pad[0xC];
    Node_002998D0* head;
    bool FindNearest(Vec_002998D0* p, Vec_002998D0* out, float* outDist, int* outIdx, int skip);
};

bool Obj_002998D0::FindNearest(Vec_002998D0* p, Vec_002998D0* out, float* outDist, int* outIdx, int skip)
{
    if (!head)
        return false;
    float best = 100000000.0f;
    int i = 0;
    for (Node_002998D0* n = head; n; n = n->next, i++) {
        if (i == skip)
            continue;
        Vec_002998D0 d;
        float x = n->pos.f.x - p->f.x;
        float z = n->pos.f.z - p->f.z;
        float w = n->pos.f.w - p->f.w;
        d.f.x = x;
        d.f.y = 0.0f;
        d.f.z = z;
        d.f.w = w;
        float dist = x * x + z * z;
        if (dist < best) {
            best = dist;
            out->q = n->pos.q;
            *outDist = best;
            *outIdx = i;
        }
    }
    return true;
}
