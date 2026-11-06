extern "C" void func_00124C40(void* e);

class Mgr_0012DCD0;
extern "C" void func_0012DDE8(Mgr_0012DCD0* self, int lock);

class Mgr_0012DCD0 {
public:
    char pad0[0x4C];
    void* m_root;
    void Refresh();
};

void Mgr_0012DCD0::Refresh()
{
    if (m_root) {
        func_0012DDE8(this, 1);
        func_00124C40(m_root);
        func_0012DDE8(this, 0);
    }
}
