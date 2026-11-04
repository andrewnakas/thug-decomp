extern "C" void func_00134F60(void* p);

struct Obj_002993D8 {
    char pad0[0x34];
    void* m34;
    void* m38;
    void Reset();
};

void Obj_002993D8::Reset()
{
    if (m38)
        func_00134F60(m38);
    if (m34)
        func_00134F60(m34);
}
