struct Script_002218E0 {
    char pad0[0x18];
    void* m18;
};

extern void* D_0038FC78;
extern "C" int func_001E7DE8(void* params, unsigned int crc, int* out, int a);
extern "C" char* func_0022E3C8(void* game, int i);
extern "C" int func_001E8398(void* params, unsigned int crc, unsigned int* out, int a);
extern "C" void* func_0011FE68(void* p, unsigned int crc);
extern "C" void func_001E6AC8(void* s, void* p);

bool Cmd_002218E0(void* params, Script_002218E0* script)
{
    int idx = 0;
    func_001E7DE8(params, 0x67E6859A, &idx, 0);
    void* p = func_0022E3C8(D_0038FC78, idx) + 4;
    unsigned int crc;
    if (func_001E8398(params, 0xB6F08F39, &crc, 0)) {
        void* r = func_0011FE68(p, crc);
        if (r) {
            func_001E6AC8(script->m18, r);
            return true;
        }
    }
    return false;
}
