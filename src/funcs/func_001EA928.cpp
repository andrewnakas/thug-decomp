struct Vec_001EA928 {
    int m_0;
    float x;
    float y;
    float z;
};

union Val_001EA928 {
    int i;
    float f;
    char* s;
    void* p;
    Vec_001EA928* v;
};

extern "C" void func_001EA8C0(void* src, int* type, Val_001EA928* value);
extern "C" int func_00331950(char* a, char* b);
extern "C" bool func_001E8E30(void* a, void* b);

extern "C" bool func_001EA928(void* a, void* b)
{
    int ta;
    Val_001EA928 va;
    int tb;
    Val_001EA928 vb;
    func_001EA8C0(a, &ta, &va);
    func_001EA8C0(b, &tb, &vb);
    switch (ta) {
    case 0:
        break;
    case 1:
        if (tb == 2) {
            return vb.f == (float)va.i;
        }
        if (tb == 1) {
            return va.i == vb.i;
        }
        break;
    case 2:
        if (tb == 1) {
            return va.f == (float)vb.i;
        }
        if (tb == 2) {
            return va.f == vb.f;
        }
        break;
    case 3:
        if (tb != 3) {
            return false;
        }
        return func_00331950(va.s, vb.s) == 0;
    case 4:
        if (tb != 4) {
            return false;
        }
        return func_00331950(va.s, vb.s) == 0;
    case 13:
        if (tb == 13) {
            return va.i == vb.i;
        }
        break;
    case 5:
        if (tb == 5) {
            return va.v->x == vb.v->x && va.v->y == vb.v->y;
        }
        break;
    case 6:
        if (tb == 6) {
            return va.v->x == vb.v->x && va.v->y == vb.v->y && va.v->z == vb.v->z;
        }
        break;
    case 7:
        if (tb == 7) {
            return va.i == vb.i;
        }
        break;
    case 10:
        if (tb == 10) {
            if (va.p == vb.p) {
                return true;
            }
        }
        break;
    case 12:
        if (tb == 12) {
            if (va.p == vb.p) {
                return true;
            }
            return func_001E8E30(va.p, vb.p);
        }
        break;
    }
    return false;
}
