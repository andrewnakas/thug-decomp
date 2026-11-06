/* sym: _$_13Menu_00126678 = 0x001304E0 */
class Menu_00126678 {
public:
    int m0;
    ~Menu_00126678();
};

class Elem_00126678;
extern "C" void func_00126F28(Elem_00126678* self, int a);
extern "C" void func_00126E18(Elem_00126678* self, int a, int b);

class Elem_00126678 {
public:
    char pad0[0x1B8];
    Menu_00126678* m_menu;
    void Close();
};

void Elem_00126678::Close()
{
    if (m_menu) {
        func_00126F28(this, 0);
        if (m_menu) {
            delete m_menu;
        }
        m_menu = 0;
        func_00126E18(this, 1, 0);
    }
}
