extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_0029D030 {
    char pad0[0xC];
    void* mC;
    char pad10[0x9C - 0x10];
    void* m9C;
    void Bind();
};

void Obj_0029D030::Bind()
{
    m9C = func_00185578(mC, 0x27D7CD28);
}
