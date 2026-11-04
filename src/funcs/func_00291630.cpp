extern "C" void* func_00185578(void* p, unsigned int id);

struct Obj_00291630 {
    char pad[0xC];
    void* mC;
    char pad10[0x2C - 0x10];
    void* m2C;
    void* m30;
    void* m34;
    void Bind();
};

void Obj_00291630::Bind()
{
    m34 = func_00185578(mC, 0x5BD63B29);
    m30 = func_00185578(mC, 0x286A8D26);
    m2C = func_00185578(mC, 0x72AD7B23);
}
