struct Item_002C91A0 {
    char pad0[0x14C];
    int m14C;
    signed char m150;
    signed char m151;
};

struct Board_002C91A0 {
    char pad0[0x6A5C];
    int m6A5C;
};

extern "C" Item_002C91A0* func_002C0370(Board_002C91A0* b, int idx, void* p);
extern "C" int func_002C8C38(void* self);
extern "C" void func_002C8CC8(void* self, int v);
extern "C" void func_002C7488(void* self);
extern "C" void func_002C9DA8(void* self, int v);
extern "C" void func_002C95E8(void* self);

struct Sub_002C91A0 {
    int m0;
    Board_002C91A0* m4;
    Board_002C91A0* Get() { return m4; }
};

struct Obj_002C91A0 {
    char pad0[0x4];
    Sub_002C91A0 m4;
    char padC[0x74 - 0xC];
    int m74;
    char m78[4];
    void Open();
};

void Obj_002C91A0::Open()
{
    if (!func_002C8C38(this)) return;
    Item_002C91A0* found = 0;
    int count = m4.Get()->m6A5C;
    for (int i = 0; i < count; i++) {
        Item_002C91A0* it = func_002C0370(m4.Get(), i, m78);
        if (it->m151) {
            m74 = i;
            found = it;
            break;
        }
    }
    found->m14C = 0;
    func_002C8CC8(this, 0);
    func_002C7488(this);
    func_002C9DA8(this, 5);
    func_002C95E8(this);
}
