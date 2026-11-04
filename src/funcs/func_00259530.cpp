typedef int qword_00259530 __attribute__((mode(TI)));

extern "C" float sqrtf(float x);

union Vec_00259530 {
    qword_00259530 q;
    struct {
        float x, y, z, w;
    } f;
};

struct Obj_00259530 {
    char m_pad0[0x10];
    Vec_00259530 m_pos;
    void* m20;
    char m_pad24[0x70 - 0x24];
    int m70;
    char m_pad74[0x80 - 0x74];
    Vec_00259530 m_start;
    char m_pad90[0xBC - 0x90];
    float m_dist;
    float m_left;
    int m_flags;
    float m_total;
    char m_padCC[0xD0 - 0xCC];
    Vec_00259530 m_last;
    char m_padE0[0xFC - 0xE0];
    int m_state;
    void Update();
};

extern "C" int func_002588F8(Obj_00259530* self);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001A6BB8(void* comp, int a);
extern "C" void func_002587E0(Obj_00259530* self);
extern "C" void func_00258F18(Obj_00259530* self);

void Obj_00259530::Update()
{
    switch (func_002588F8(this)) {
    case 0: {
        m_state = 3;
        Vec_00259530 d;
        d.f.x = m_pos.f.x - m_start.f.x;
        d.f.y = m_pos.f.y - m_start.f.y;
        d.f.z = m_pos.f.z - m_start.f.z;
        d.f.w = m_pos.f.w - m_start.f.w;
        m_last = m_pos;
        m_left = m_total;
        m_dist = sqrtf(d.f.x * d.f.x + d.f.y * d.f.y + d.f.z * d.f.z);
        break;
    }
    case 1:
        m_state = 2;
        break;
    case 2:
        func_001A6BB8(func_00185578(m20, 0x0A015E17), m70);
        m_flags &= ~4;
        m_left = m_dist - m_left;
        func_002587E0(this);
        func_00258F18(this);
        m_state = 1;
        break;
    }
}
