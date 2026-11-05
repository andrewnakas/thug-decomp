struct Obj_00233788 {
    signed char* m_data;
    int m4;
    int m8;
    int mC;
    int* m10;
    int m14;
    int m18;
    void* m1C;
};

extern "C" void* func_0022E040(void* p);
extern "C" void* func_00187B48(void* p, int id);
extern "C" void* func_00185578(void* obj, unsigned int crc);
extern "C" void func_001A2610(void* c, int a, bool b, int d, int e);

extern "C" bool func_00233788(Obj_00233788* o)
{
    signed char* d = o->m_data;
    void* x = func_00187B48(func_0022E040(o->m1C), d[0]);
    if (x) {
        void* c = func_00185578(x, 0x72AD7B23);
        if (c)
            func_001A2610(c, d[0], d[1] != 0, *o->m10, 0);
    }
    return true;
}
