extern "C" int func_001E8398(void* params, unsigned int crc, unsigned int* out, int a);
extern "C" int func_001E8708(void* params, unsigned int crc);
extern "C" void* func_00240850();
extern "C" void func_0023F560(void* mgr, unsigned int crc, int mode);

bool Cmd_00242F48(void* params, void* script)
{
    unsigned int crc;
    func_001E8398(params, 0xA1DC81F9, &crc, 1);
    int mode = 1;
    if (func_001E8708(params, 0x54585419))
        mode = 0;
    else if (!func_001E8708(params, 0xE022C12C) && func_001E8708(params, 0x806FFF30))
        mode = 2;
    func_0023F560(func_00240850(), crc, mode);
    return true;
}
