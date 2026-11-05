extern "C" void* func_00185578(void* p, unsigned int id);

struct Obj_00290400 {
    char pad[0xC];
    void* mC;
    char pad10[0x1C - 0x10];
    void* m1C;
    void Bind();
};

void Obj_00290400::Bind()
{
    m1C = func_00185578(mC, 0x43686585);
}
