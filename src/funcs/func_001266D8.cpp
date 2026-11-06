class Elem_001266D8;
extern "C" void func_00126F28(Elem_001266D8* self, int a);
extern "C" void func_00126E18(Elem_001266D8* self, int a, int b);

class Elem_001266D8 {
public:
    char pad0[0x1B4];
    int m1B4;
    void* m_menu;
    int m_open;
    void SetOpen(int on);
};

void Elem_001266D8::SetOpen(int on)
{
    if (on) {
        if (!m_open) {
            m_open = 1;
            func_00126E18(this, m1B4, 1);
        }
    } else {
        if (m_open) {
            m_open = 0;
            func_00126F28(this, 1);
        }
    }
}
