struct Col_00130C18 {
    unsigned char r, g, b, a;
    Col_00130C18() {}
};

struct Arr_00130C18 {
    char pad[0xC];
    int mC;
};

extern char D_0035D388[];
extern char D_0035D398[];
extern char D_0035D3A8[];
extern char D_0035D3B8[];
extern char D_0035D3C8[];

extern "C" int func_001E87B8(void* params, const char* name);
extern "C" int func_001E8870(void* params, unsigned int name, const char** out, int req);
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" int func_001E7F50(void* params, const char* name, float* out, int req);
extern "C" int func_001E82B8(void* params, const char* name, Arr_00130C18** out, int req);
extern "C" Arr_00130C18* func_001E93A0(Arr_00130C18* arr, int i);
extern "C" int func_001E9270(Arr_00130C18* arr, int i);
extern "C" void func_00130918(const char* name, int a, int b, Col_00130C18* cols, int flag);

bool Cmd_00130C18(void* params, void* script)
{
    int flag = func_001E87B8(params, D_0035D388);
    const char* name;
    func_001E8870(params, 0, &name, 0);
    if (flag)
        name = D_0035D398;
    func_0010BFC0(name);
    float x = 0.0f;
    func_001E7F50(params, D_0035D3A8, &x, 0);
    float y = 0.0f;
    func_001E7F50(params, D_0035D3B8, &y, 0);
    Col_00130C18 cols[16];
    Col_00130C18* pc = cols;
    Arr_00130C18* arr;
    if (func_001E82B8(params, D_0035D3C8, &arr, 0)) {
        for (int i = 0; i < arr->mC; i++) {
            if (i >= 16)
                break;
            Arr_00130C18* sub = func_001E93A0(arr, i);
            unsigned int v = 0;
            int n = sub->mC;
            for (int j = 0; j < n; j++)
                v |= (unsigned char)func_001E9270(sub, j) << (j * 8);
            pc[i] = *(Col_00130C18*)&v;
        }
    }
    func_00130918(name, (int)x, (int)y, pc, flag);
    func_0010BFC8();
    return true;
}
