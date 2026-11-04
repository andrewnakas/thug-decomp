extern "C" void func_001048F0(void* p);

struct Obj_00253EE8 {
    char m_pad[0x1C];
    void* m_data;
    void Free();
};

void Obj_00253EE8::Free()
{
    func_001048F0(m_data);
}
