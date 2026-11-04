struct Stats_00146610 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

extern void* D_00388A70;
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00131E48();
extern "C" void* func_0014C1B8(void* p);
extern "C" void func_00170838(void* p, Stats_00146610* out);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E78A8(void* s, unsigned int name, void* sub);
extern "C" void func_0010A8D8(void* pool, void* p);

void func_00146610(void* params)
{
    void* s = func_001E6978(func_001190D0(8));
    Stats_00146610* st = (Stats_00146610*)func_001046B0(0x18);
    void* obj = func_00131E48();
    if (func_0014C1B8(obj)) {
        func_00170838(func_0014C1B8(obj), st);
        func_001E7200(s, 0xD55CD658, 0);
    } else {
        func_001E7200(s, 0xD55CD658, 1);
    }
    func_001E7200(s, 0x3DD01EA1, st->m4);
    func_001E7200(s, 0x3960FF18, st->m8);
    func_001E7200(s, 0x4DE5330C, st->mC);
    func_001E7200(s, 0x94927839, st->m10);
    func_001E7200(s, 0x169EE151, st->m14);
    func_001E72B0(s, 0x58785E10, (float)st->m10 / (float)st->m14);
    func_001E72B0(s, 0x3B75D7CC, (float)st->m14 / (float)st->mC);
    func_001E72B0(s, 0xBC56249D, (float)st->m14 / (float)st->m8);
    func_001E78A8(params, 0x26861025, s);
    func_0010A8D8(D_00388A70, st);
}
