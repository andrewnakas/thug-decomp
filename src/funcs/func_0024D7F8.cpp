class Ptr_0024D7F8;
class Ret_0024D7F8;

extern "C" void func_00183CB8(void* p, Ptr_0024D7F8* ref);
extern "C" void func_00183C98(void* p, Ptr_0024D7F8* ref);

class Ret_0024D7F8 {
public:
    void* m_ptr;
    Ptr_0024D7F8* m_prev;
    Ptr_0024D7F8* m_next;

    Ret_0024D7F8(const Ret_0024D7F8& other);
    ~Ret_0024D7F8()
    {
        if (m_ptr) {
            func_00183CB8(m_ptr, (Ptr_0024D7F8*)this);
            m_ptr = 0;
        }
    }
    operator void*() const { return m_ptr; }
};

class Ptr_0024D7F8 {
public:
    void* m_ptr;
    Ptr_0024D7F8* m_prev;
    Ptr_0024D7F8* m_next;

    Ptr_0024D7F8(const Ret_0024D7F8& other)
    {
        void* o = other.m_ptr;
        Ptr_0024D7F8* p = this;
        p->m_prev = 0;
        p->m_next = 0;
        p->m_ptr = o;
        if (p->m_ptr)
            func_00183C98(p->m_ptr, p);
    }
    ~Ptr_0024D7F8()
    {
        if (m_ptr) {
            func_00183CB8(m_ptr, this);
            m_ptr = 0;
        }
    }
    operator void*() const { return m_ptr; }
};

struct Ref_0024D7F8 {
    void* m_ptr;
    void Set(void* p)
    {
        if (m_ptr) {
            func_00183CB8(m_ptr, (Ptr_0024D7F8*)this);
            m_ptr = 0;
        }
        m_ptr = p;
        if (p)
            func_00183C98(p, (Ptr_0024D7F8*)this);
    }
};

struct Script_0024D7F8 {
    char pad[0xBC];
    Ref_0024D7F8 m_object;
};

struct Slot_0024D7F8 {
    char pad[0x1C];
    int m_id;
    int m_done;
};

struct Game_0024D7F8 {
    char pad[0x20];
    void* m_params;
    char pad24[0x70];
    Slot_0024D7F8 m_slots[30];
    char pad4CC[0x10];
    int m4DC;
};

extern void* D_00389A30;

extern "C" bool func_001E7DE8(void* self, unsigned int name, int* out, int assert_);
extern "C" bool func_001E7EB0(void* self, unsigned int name, float* out, int assert_);
extern "C" Ret_0024D7F8 func_0012DB48(void* mgr, int id, int v);
extern "C" void* func_001190D0(unsigned int size);
extern "C" void* func_001E6978(void* self);
extern "C" void func_001E7360(void* self, unsigned int name, unsigned int value);
extern "C" void func_001E7200(void* self, unsigned int name, int value);
extern "C" void func_001F0210(unsigned int name, void* params, void* a, int b, int c);
extern "C" void func_001E6AE8(void* self, int flags);
extern "C" Script_0024D7F8* func_001F0750(unsigned int script, void* params, void* object, int a, int b, int c, int d, int e, int f, int g);
extern "C" void func_001EFDC0(Script_0024D7F8* self);
extern "C" bool func_0024E0C0(Game_0024D7F8* self);

void func_0024D7F8(Game_0024D7F8* self, int index)
{
    int total;
    int flag;
    int count;
    int every;
    float frac;
    int base;

    func_001E7DE8(self->m_params, 0x89473DB7, &total, 1);
    void* mgr = D_00389A30;
    int id = self->m_slots[index].m_id;
    Ptr_0024D7F8 obj = func_0012DB48(mgr, id, 1);
    void* p = func_001E6978(func_001190D0(8));
    func_001E7360(p, 0x40C698AF, id);
    func_001F0210(0x235BDE21, p, 0, 0, 0);
    if (p)
        func_001E6AE8(p, 3);
    flag = 0;
    func_001E7DE8(self->m_params, 0xD02AC196, &flag, 0);
    if (flag == 1 && (float)(self->m4DC - 1) < (float)total * 0.75f) {
        func_001E7200(self->m_params, 0xD02AC196, 0);
        for (int i = 0; i < 30; i++) {
            if (!self->m_slots[i].m_done) {
                void* o = func_0012DB48(mgr, self->m_slots[i].m_id, 1);
                Script_0024D7F8* s = func_001F0750(0xA39B24E0, 0, 0, 0, -1, 0, 0, 0, 0, 0);
                s->m_object.Set(o);
                func_001EFDC0(s);
            }
        }
    }
    void* q = func_001E6978(func_001190D0(8));
    if (func_0024E0C0(self))
        func_001E7360(q, 0, 0xEA7BA666);
    Script_0024D7F8* s = func_001F0750(0x23A6A456, q, 0, 0, -1, 0, 0, 0, 0, 0);
    s->m_object.Set(obj);
    func_001EFDC0(s);
    if (q)
        func_001E6AE8(q, 3);
    count = 0;
    func_001E7DE8(self->m_params, 0x8D958F01, &count, 0);
    every = 0;
    count++;
    func_001E7DE8(self->m_params, 0x01181B29, &every, 0);
    if (every && count % every == 0) {
        frac = 0.0f;
        func_001E7EB0(self->m_params, 0x076F65C8, &frac, 0);
        func_001E7DE8(self->m_params, 0x648D8D2A, &base, 1);
        base = (int)((1.0f - frac) * (float)base);
        func_001E7200(self->m_params, 0x648D8D2A, base);
    }
    func_001E7200(self->m_params, 0x8D958F01, count);
    self->m4DC--;
    self->m_slots[index].m_done = 1;
}
