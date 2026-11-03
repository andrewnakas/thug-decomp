extern "C" int func_001E8708(void* p, unsigned int key);

struct Obj_00246D70 {
    char pad[0x20];
    void* m_p;
    int Lookup();
};

int Obj_00246D70::Lookup()
{
    return func_001E8708(m_p, 0x8CFEE956);
}
