extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" void* func_00139468(void* mgr, int id);
extern "C" void func_00138830(void* o, unsigned short a, int b, int c);

extern void* D_00393EF4;

bool func_0013A2C8(void* params)
{
    int id;
    func_001E8398(params, 0, &id, 0);
    void* o = func_00139468(D_00393EF4, id);
    if (o) {
        int a = 0;
        int b = 0;
        int c = 0;
        func_001E7DE8(params, 0x485A0CDB, &a, 0);
        func_001E7DE8(params, 0x7AF07905, &b, 0);
        func_001E7DE8(params, 0x88CF948C, &c, 0);
        func_00138830(o, a, b, c);
    }
    return true;
}
