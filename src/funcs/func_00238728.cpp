struct It_00238728 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Obj_00238728 {
    char pad0[0xC];
    int m_C;
    char pad10[0x44 - 0x10];
    char m_44[0x14];
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    void Reset();
};

extern "C" void func_0023B408(It_00238728* it, void* list);
extern "C" void func_0023B420(It_00238728* it);
extern "C" void func_0023ACE0(Obj_00238728* self);

void Obj_00238728::Reset()
{
    m_C = 0;
    It_00238728 it;
    func_0023B408(&it, m_44);
    func_0023B420(&it);
    m_58 = 0;
    m_5C = 0;
    m_60 = -1;
    m_64 = -1;
    func_0023ACE0(this);
}
