extern "C" void func_001307E0(void* menu, void* params, int a);

class Elem_00126218;
extern "C" void func_00124868(Elem_00126218* self, void* params);

class Elem_00126218 {
public:
    char pad0[0x1B8];
    void* m_menu;
    void SetProps(void* params);
};

void Elem_00126218::SetProps(void* params)
{
    if (m_menu) {
        func_001307E0(m_menu, params, 0);
    }
    func_00124868(this, params);
}
