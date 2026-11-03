union Val_001EACB0 {
    int i;
    float f;
    char* s;
};

extern "C" void func_001EA8C0(void* src, int* type, Val_001EACB0* value);
extern "C" unsigned int func_00331BB8(char* s);

extern "C" bool func_001EACB0(void* a, void* b)
{
    int ta;
    Val_001EACB0 va;
    int tb;
    Val_001EACB0 vb;
    func_001EA8C0(a, &ta, &va);
    func_001EA8C0(b, &tb, &vb);
    switch (ta) {
    case 1:
        if (tb == 2) {
            return (float)va.i > vb.f;
        }
        if (tb == 1) {
            return va.i > vb.i;
        }
        return false;
    case 2:
        if (tb == 1) {
            return va.f > (float)vb.i;
        }
        if (tb == 2) {
            return va.f > vb.f;
        }
        return false;
    case 3:
        if (tb != ta) {
            return false;
        }
        return func_00331BB8(va.s) > func_00331BB8(vb.s);
    case 4:
        if (tb != ta) {
            return false;
        }
        return func_00331BB8(va.s) > func_00331BB8(vb.s);
    }
    return false;
}
