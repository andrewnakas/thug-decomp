extern "C" int func_001E8398(void* params, unsigned int crc, int* out, int req);
extern "C" void* func_0022E040(int a);
extern "C" void* func_00187B48(void* a, int id);
extern "C" void* func_00185578(void* obj, unsigned int crc);
extern "C" int func_0019EFF8(void* c, int a, float* out);
extern "C" void func_001E72B0(void* s, unsigned int crc, float v);
extern int D_0038FC78;

struct Script_002183D0 {
    char pad0[0x18];
    void* m_18;
};

int Cmd_002183D0(void* params, Script_002183D0* script)
{
    float v[4];
    int id;
    int x;
    int r = 0;
    func_001E8398(params, 0x40C698AF, &id, 1);
    void* o = func_00187B48(func_0022E040(D_0038FC78), id);
    if (o) {
        func_001E8398(params, 0xCAB94088, &x, 1);
        r = func_0019EFF8(func_00185578(o, 0x222756D5), x, v);
    }
    func_001E72B0(script->m_18, 0x7323E97C, v[0]);
    func_001E72B0(script->m_18, 0x0424D9EA, v[1]);
    func_001E72B0(script->m_18, 0x9D2D8850, v[2]);
    return r;
}
