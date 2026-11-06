struct Obj_001F7C18 {
    int m_state;
    char pad4[0x44 - 4];
    int m_base;
    int m_size;
    int m4C;
    int m_offset;
    void Start();
};
extern "C" void func_001F7A00(Obj_001F7C18* self);
extern "C" int func_0031AF08(int a, int cmd, int b, int c, int base, int size, int addr);

void Obj_001F7C18::Start()
{
    func_001F7A00(this);
    func_0031AF08(1, 0x80E0, 0, 0x13, m_base, m_size / 1024 * 1024, m_base + m_offset);
    m_state = 2;
}
