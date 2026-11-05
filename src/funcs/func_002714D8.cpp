extern void* D_0038FC78;
extern "C" void* func_00230628(void* p);
extern "C" void func_0026D318(void* p);
extern "C" bool func_00263C78(void* p, int id);
extern "C" bool func_002637D0(void* p);
extern "C" void* func_001F0750(unsigned int script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);

struct Game_002714D8 {
    char pad[0x24];
    void* m24;
};

void Run_002714D8()
{
    func_0026D318(func_00230628(D_0038FC78));
    void* s = ((Game_002714D8*)D_0038FC78)->m24;
    if (func_00263C78(s, 0x195)) return;
    if (func_002637D0(s)) {
        func_001F0750(0xCC74CC2E, 0, 0, 0, -1, 0, 0, 0, 0, 0);
    }
}
