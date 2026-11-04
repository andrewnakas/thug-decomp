extern "C" int func_001E8708(void* p, unsigned int key);

struct Obj_00245DE8 {
    char pad[0x20];
    void* m_p;
    int Lookup();
};

int Obj_00245DE8::Lookup()
{
    return func_001E8708(m_p, 0xB394C01C);
}
