struct Entry_0011DE18 {
    int m_key;
    int m4;
    int m8;
    unsigned int m_flags;
};

class Table_0011DE18;
extern "C" Entry_0011DE18* func_0011D4F0(Table_0011DE18* self, int key);

class Table_0011DE18 {
public:
    bool SetEnabled(int key, int on);
};

bool Table_0011DE18::SetEnabled(int key, int on)
{
    Entry_0011DE18* e = func_0011D4F0(this, key);
    if (e) {
        e->m_flags &= ~0x40000000;
        unsigned int f = e->m_flags;
        if (!on) {
            f |= 0x40000000;
        }
        e->m_flags = f;
    }
    return e != 0;
}
