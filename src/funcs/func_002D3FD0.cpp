struct Obj_002D3FD0 {
    char pad[8];
    int m8;
    char padC[0x1C - 0xC];
    int m1C;
};

extern "C" int func_0010FC30();

extern "C" void func_002D3FD0(void* a0, int type, int a2, int a3, int done, int total, Obj_002D3FD0* o)
{
    if (type == 7 || type == 3) {
        if (total > 0)
            o->m8 = (int)((float)done / (float)total * 100.0f);
    }
    o->m1C = func_0010FC30();
}
