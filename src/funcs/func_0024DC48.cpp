class Ptr_0024DC48;

extern "C" void func_00183CB8(void* p, Ptr_0024DC48* ref);

class Ret_0024DC48 {
public:
    void* m_ptr;
    Ptr_0024DC48* m_prev;
    Ptr_0024DC48* m_next;

    Ret_0024DC48(const Ret_0024DC48& other);
    ~Ret_0024DC48()
    {
        if (m_ptr) {
            func_00183CB8(m_ptr, (Ptr_0024DC48*)this);
            m_ptr = 0;
        }
    }
    operator void*() const { return m_ptr; }
};

struct Slot_0024DC48 {
    unsigned int m0;
    unsigned int m4;
    unsigned int m8;
    int m_id;
    int m_done;
    int m14;
    int m18;
    int m1C;
    int m20;
};

struct Game_0024DC48 {
    char pad[0x20];
    void* m_params;
    char pad24[0xA4 - 0x24];
    Slot_0024DC48 m_slots[30];
    void Update();
};

extern void* D_0038FC78;
extern void* D_00389A30;

extern "C" int func_001E7DE8(void* self, unsigned int name, int* out, int assert_);
extern "C" void* func_0022DD38(void* self);
extern "C" void* func_00203360(void* p);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" Ret_0024DC48 func_0012DB48(void* mgr, int id, int v);
extern "C" int func_0023A278(void* self, unsigned int name, int a, int b, int c);
extern "C" int func_0023A168(void* self, unsigned int name, int a, int b, int c);
extern "C" void func_00123EB0(void* o, float a, int f);

void Game_0024DC48::Update()
{
    int flag;
    bool has = func_001E7DE8(m_params, 0x60B827D5, &flag, 0);
    void* x = func_00203360(func_0022DD38(D_0038FC78));
    void* mgr = D_00389A30;
    float on = func_001E5318(0x855E6DA4, 1);
    float off = func_001E5318(0xDBE5B19E, 1);
    for (int i = 0; i < 30; i++) {
        if (m_slots[i].m_done)
            continue;
        void* o = func_0012DB48(mgr, m_slots[i].m_id, 1);
        bool vis = false;
        if (has && !flag)
            vis = false;
        else {
            if (m_slots[i].m8) {
                if (func_0023A278(x, m_slots[i].m8, m_slots[i].m1C, m_slots[i].m14, m_slots[i].m20) > 0)
                    vis = true;
            } else if (m_slots[i].m0) {
                if (func_0023A168(x, m_slots[i].m0, m_slots[i].m1C, m_slots[i].m14, 1) > 0)
                    vis = true;
                else if (m_slots[i].m4 && func_0023A168(x, m_slots[i].m4, m_slots[i].m1C, m_slots[i].m14, 1) > 0)
                    vis = true;
            }
        }
        if (vis)
            func_00123EB0(o, on, 1);
        else
            func_00123EB0(o, off, 1);
    }
}
