extern "C" void func_00114D48(void* self);

struct Obj_00114D28 {
    char pad[0xB0];
    float m_B0;
    void Set(float f);
};

void Obj_00114D28::Set(float f)
{
    m_B0 = f;
    func_00114D48(this);
}
