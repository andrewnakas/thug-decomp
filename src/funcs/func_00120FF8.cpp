struct Obj_00120FF8;

extern Obj_00120FF8* D_00389520;
extern void* D_00389518;

extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" void* func_0011FE68(Obj_00120FF8* o, unsigned int id);
extern "C" void* func_0011FE18(Obj_00120FF8* o, unsigned int id);
extern "C" int func_001E8618(void* params, unsigned int id);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E88D8(void* params, unsigned int id, int* out, int req);
extern "C" void func_0013E278(void* o, void* params, float a, float b, float c);
extern "C" void func_0013E660(void* o, void* params);

int func_00120FF8(void* script, void* params)
{
    unsigned int id;
    func_001E8398(params, 0xB6F08F39, &id, 1);
    void* o = func_0011FE68(D_00389520, id);
    if (!o)
        return 1;
    int flag = 0;
    if (!func_001E8618(o, 0x97DBDDE6))
        flag = 1;
    else
        func_001E7DE8(o, 0x97DBDDE6, &flag, 0);
    if (flag) {
        void* d = func_0011FE18(D_00389520, id);
        int a;
        int b;
        int c;
        if (d && func_001E7DE8(d, 0xC6CC7F7F, &a, 0) && func_001E7DE8(d, 0x4CA9B693, &b, 0)
            && func_001E7DE8(d, 0x3CC3421C, &c, 0)) {
            float fb = b * 0.01f;
            func_0013E278(D_00389518, params, a, fb, c * 0.01f);
            return 0;
        }
        func_0013E660(D_00389518, params);
        return 0;
    }
    int r;
    int g;
    int b;
    if (func_001E88D8(o, 0x6E94F918, &r, 0) && func_001E88D8(o, 0xE4F130F4, &g, 0)
        && func_001E88D8(o, 0x949BC47B, &b, 0))
        func_0013E278(D_00389518, params, r, g * 0.01f, b * 0.01f);
    return 1;
}
