extern "C" int func_00170548(void* self);

class Obj_001707A0 {
public:
    char pad[0x3C];
    unsigned int m_color;
    unsigned int GetColor();
};

unsigned int Obj_001707A0::GetColor()
{
    if (func_00170548(this))
        return m_color;
    return 0x80808080;
}
