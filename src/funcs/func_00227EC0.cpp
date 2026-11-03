extern char D_003722F0[];
extern unsigned int D_0038F9D4;

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" bool func_001E8708(void* params, unsigned int name);

bool Cmd_00227EC0(void* params, void* script)
{
    func_00103F28(D_003722F0);
    D_0038F9D4 = 0;
    if (func_001E8708(params, 0x16B506C0))
        D_0038F9D4 |= 8;
    if (func_001E8708(params, 0xDC7EA3CE))
        D_0038F9D4 |= 4;
    if (func_001E8708(params, 0x33EC233F))
        D_0038F9D4 |= 2;
    if (func_001E8708(params, 0xB39D7CC4))
        D_0038F9D4 |= 1;
    if (func_001E8708(params, 0xC4E78E22))
        D_0038F9D4 = 0xFFFFFFFF;
    return true;
}
