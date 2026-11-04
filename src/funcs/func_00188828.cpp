struct Script_00188828 {
    char pad0[0xC];
    unsigned int mC;
};

struct Thing_00188828 {
    char pad0[0xBC];
    Script_00188828* mBC;
};

struct E_00188828 {
    int m_key;
    unsigned int m_id;
    unsigned int m8;
    int m_used;
    int m10;
    int m14;
    void* m_obj;
};

struct Ev_00188828 {
    int m_key;
    int m4;
    int m8;
    int mC;
    void* m10;
};

struct L_00188828 {
    E_00188828* m_items;
    int m_count;
    int m_alive;
    int m_changed;
    int m_lock;
    ~L_00188828();
    void Fire(Ev_00188828* ev, Thing_00188828* th);
};

extern "C" void* func_001190D0(int size);
extern "C" void func_00183C98(void* obj, void* ref);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00187D28(Ev_00188828* ev, int a, unsigned int id);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E6A50(void* dst, void* src);
extern "C" void func_001E6AE8(void* s, int flags);
extern "C" void func_001E7A68(void* s, unsigned int name, int type, int value);
extern "C" void func_001EE8C8(Thing_00188828* th, unsigned int id, void* params, Script_00188828* s);
extern "C" void func_001EEF18(Thing_00188828* th, unsigned int id, void* params);
extern "C" int func_001EFDC0(Thing_00188828* th);
extern "C" Thing_00188828* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                         int d, int e, int f, int g, int h);
extern "C" void func_001F1230(Thing_00188828* th, int v);
extern "C" unsigned int func_001F1238(Thing_00188828* th);

static inline void SetRef(Script_00188828** ref, Script_00188828* const& obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (*ref) {
        func_00183C98(*ref, ref);
    }
}

void L_00188828::Fire(Ev_00188828* ev, Thing_00188828* th)
{
    int changed = m_changed;
    m_changed = 0;
    m_lock++;
    E_00188828* e = m_items;
    for (int i = 0; i < m_count; i++) {
        int key = ev->m_key;
        if (e->m_key == key && e->m_id != 0xC377C572 && e->m_used) {
            void* tmp = 0;
            void* params;
            if (ev->m10) {
                tmp = func_001E6978(func_001190D0(8));
                if (e->m_obj) {
                    func_001E6A50(tmp, e->m_obj);
                }
                func_001E6A50(tmp, ev->m10);
                params = tmp;
            } else {
                params = e->m_obj;
            }
            if (e->m10) {
                if (func_001F1238(th)) {
                    void* s = func_001E6978(func_001190D0(8));
                    func_001E7A68(s, 0, 0xD, e->m10);
                    unsigned int id = func_001F1238(th);
                    func_001F1230(th, 0);
                    func_001EEF18(th, id, s);
                    if (s) {
                        func_001E6AE8(s, 3);
                    }
                }
                if (e->m_id != 0xC377C572) {
                    func_001EE8C8(th, e->m_id, params, th->mBC);
                    func_001EFDC0(th);
                }
            } else if (th->mBC && (th->mBC->mC & 0x10000)) {
                Thing_00188828* t = func_001F0750(e->m_id, params, 0, 0, -1, 0, 0, 0, 0, 0);
                SetRef(&t->mBC, th->mBC);
                func_001EFDC0(t);
            } else {
                func_001EEF18(th, e->m_id, params);
            }
            if (tmp) {
                func_001E6AE8(tmp, 3);
            }
            func_00187D28(ev, 0, e->m_id);
        }
        e++;
        if (!m_alive) {
            if (--m_lock == 0) {
                delete this;
            }
            return;
        }
        if (m_changed) {
            break;
        }
    }
    m_changed = m_changed || changed;
    m_lock--;
}
