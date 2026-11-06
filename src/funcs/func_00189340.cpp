struct Voice_00189340 {
    void* m_owner;
    int m4;
    int m8;
    Voice_00189340* m_next;
    int m10;
    int m_lock;
};

extern "C" void func_00187E98(Voice_00189340* v, int arg);

class Mgr_00189340 {
public:
    char pad0[0x14];
    Voice_00189340* m_voices;

    void Notify(int arg, void* owner);
};

void Mgr_00189340::Notify(int arg, void* owner)
{
    for (Voice_00189340* v = m_voices; v; v = v->m_next) {
        v->m_lock++;
        if (!owner || v->m_owner == owner) {
            func_00187E98(v, arg);
        }
        v->m_lock--;
    }
}
