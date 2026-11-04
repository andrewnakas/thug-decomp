extern void* D_00393EF4;
extern "C" int func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" int func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" void* func_00139468(void* dict, unsigned int key);
extern "C" int func_00138920(void* tex);
extern "C" int func_00138948(void* tex);
extern "C" void func_001387F0(void* tex, unsigned short x, unsigned short y, unsigned short w, unsigned short h,
                              int a, unsigned short b, unsigned short c);

extern "C" int func_0013A180(void* params)
{
    unsigned int name;
    func_001E8398(params, 0, &name, 0);
    void* tex = func_00139468(D_00393EF4, name);
    if (tex) {
        int x = 0;
        int y = 0;
        int w = func_00138920(tex);
        int h = func_00138948(tex);
        int a = 0;
        int b = 0;
        int c = 0;
        func_001E7DE8(params, 0x0FA8972E, &x, 0);
        func_001E7DE8(params, 0xB714F04B, &y, 0);
        func_001E7DE8(params, 0x73E5BAD0, &w, 0);
        func_001E7DE8(params, 0x0AB21AF0, &h, 0);
        func_001E7DE8(params, 0xE679982E, &a, 0);
        func_001E7DE8(params, 0x3D0F162A, &b, 0);
        func_001E7DE8(params, 0x39C54BDE, &c, 0);
        func_001387F0(tex, x, y, w, h, a, b, c);
    }
    return 1;
}
