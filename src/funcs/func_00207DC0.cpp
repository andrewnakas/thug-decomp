struct Obj_00207DC0 {
    char pad[0x20];
    int m20;
    int m24;
    int m28;
    int m2C;
};

extern "C" void func_001022D8(void* p);

extern "C" Obj_00207DC0* func_00207DC0(Obj_00207DC0* p)
{
    func_001022D8(p);
    p->m20 = 0;
    p->m24 = 0;
    p->m28 = 0;
    p->m2C = 0;
    return p;
}
