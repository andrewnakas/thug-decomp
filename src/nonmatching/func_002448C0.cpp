/* fuzzy: 99.1 */
/* NEAR MISS: 2 words, arg order a0/a1 before func_00244378(this,0,0) (game sets a0 in the beqz delay slot). */
struct Link_002448C0 {
    int m_id;
};

struct Base_002448C0 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual int V17();
};

struct Item_002448C0 : Base_002448C0 {
    char pad18[0x20 - 0x18];
    void* m_20;
    char pad24[0x30 - 0x24];
    Link_002448C0* m_30;
    bool Start(int unused, int flag);
};

extern "C" int func_00245DE8(Item_002448C0* self);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001303B0();
extern "C" void func_002457B8(Item_002448C0* self);
extern "C" void func_002442B8(Item_002448C0* self);
extern "C" int func_00248800(Item_002448C0* self, unsigned int name);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_001E6D18(void* params, unsigned int name);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);
extern "C" void func_00244378(Item_002448C0* self, int a, int b);
extern "C" void* func_00240850();
extern "C" Item_002448C0* func_0023BAD8(void* owner, int id, int create);
extern "C" void func_00243FB0(Item_002448C0* self);

bool Item_002448C0::Start(int unused, int flag)
{
    if (!V3()) {
        return false;
    }
    if (func_00245DE8(this)) {
        func_001E6B90(m_20, 0x79704516);
    }
    func_001303B0();
    V12();
    func_002457B8(this);
    func_002442B8(this);
    func_00248800(this, 0x01C92CAC);
    if (!func_001E8708(m_20, 0x38221DF4)) {
        func_001E6D18(m_20, 0x54D3CAC1);
    }
    if (func_001E8708(m_20, 0xC309CAD1)) {
        return true;
    }
    if (func_001E8708(m_20, 0x38221DF4)) {
        return true;
    }
    func_001F0210(0x719AE783, m_20, 0, 0, 0);
    if (!flag) {
        return true;
    }
    if (!m_30) {
        return true;
    }
    if (m_30->m_id) {
        func_00244378(this, 0, 0);
        Item_002448C0* it = 0;
        void* owner = func_00240850();
        Link_002448C0* p = m_30;
        while (p && p->m_id) {
            it = func_0023BAD8(owner, p->m_id, 1);
            p = it->m_30;
        }
        if (!it) {
            return true;
        }
        if (it->V17()) {
            return true;
        }
        func_00243FB0(it);
    }
    return true;
}
