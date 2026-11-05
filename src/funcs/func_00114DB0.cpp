extern "C" void func_00114D48(void* self);

struct Obj_00114DB0 {
    char pad[0xB4];
    float m_B4;
    float Get();
};

float Obj_00114DB0::Get()
{
    func_00114D48(this);
    return m_B4;
}
