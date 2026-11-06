extern "C" void func_00167A50(void* self);

class Obj_00168560 {
public:
    char pad[0x54];
    int m_54;
    void Set(int v);
};

void Obj_00168560::Set(int v)
{
    m_54 = v;
    func_00167A50(this);
}
