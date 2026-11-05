extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_00260590 {
    int m0;
    void* m4;
    void* m8;
    void* mC;
    void* m10;
    void Fn(void* obj);
};

void Obj_00260590::Fn(void* obj)
{
    m4 = obj;
    m8 = func_00185578(obj, 0x589E5FB3);
    mC = func_00185578(m4, 0xD262802F);
    m10 = func_00185578(m4, 0x27D7CD28);
}
