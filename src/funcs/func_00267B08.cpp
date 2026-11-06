struct Obj_00267B08 {
    int m0;
    int m4;
    int m8;
    int m_flags;
};

extern "C" void* func_00185578(Obj_00267B08* o, unsigned int crc);
extern "C" int func_001A9E60(void* c);
extern "C" int func_001A9E98(void* c, int a);
extern "C" int func_00256BA0(Obj_00267B08* o);
extern "C" void func_00266CB8(Obj_00267B08* o);
extern "C" void func_00267538(Obj_00267B08* o);

extern "C" void func_00267B08(Obj_00267B08* o)
{
    if (func_001A9E60(func_00185578(o, 0xCE0CA665)))
        return;
    if (o->m_flags & 1)
        return;
    if (!func_001A9E98(func_00185578(o, 0xCE0CA665), 0))
        return;
    if (!func_00256BA0(o))
        return;
    func_00266CB8(o);
    func_00267538(o);
}
