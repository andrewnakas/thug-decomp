struct Obj_0017E158 {
    int m0;
    char pad4[8];
    unsigned int* mC;
    char pad10[0x30];
    unsigned short m40;
    unsigned short m42;
};

extern "C" void func_0017E1F0(Obj_0017E158* obj, void* data, int a, int b, int c, int d, int e, void* arg);

extern "C" void func_0017E158(Obj_0017E158* obj, void* arg)
{
    unsigned int* p = obj->mC;
    unsigned int ver = *p++;
    obj->m0 = *p++;
    int a = *p++;
    int b = *p++;
    int c = *p++;
    int d = *p++;
    int e = 0;
    if (ver >= 2) {
        e = *p++;
    }
    obj->m40 = *(unsigned short*)p;
    p = (unsigned int*)((char*)p + 2);
    obj->m42 = *(unsigned short*)p;
    p = (unsigned int*)((char*)p + 2);
    func_0017E1F0(obj, (void*)(((unsigned int)p + 15) & 0xFFFFFFF0), a, b, c, d, e, arg);
}
