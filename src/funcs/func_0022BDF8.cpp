class Net_0022BDF8 {
public:
    char pad0[0x4358];
    virtual void Delete(int flags);
};

class Comp_0022BDF8 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
    virtual void Delete(int flags);
};

struct Man_0022BDF8 {
    char pad0[0x14];
    void* m_vt;
    Comp_0022BDF8* m18;
    Comp_0022BDF8* m1C;
    Comp_0022BDF8* m20;
    Comp_0022BDF8* m24;
    char pad28[0x5C - 0x28];
    Net_0022BDF8* m_net;
};

extern "C" void func_00182A10(Man_0022BDF8* self, int flags);

extern char D_00372778[];
extern int D_0038FC00;

void Destroy_0022BDF8(Man_0022BDF8* self, int flags)
{
    self->m_vt = D_00372778;
    if (self->m_net) {
        self->m_net->Delete(3);
    }
    if (self->m18) {
        self->m18->Delete(3);
    }
    if (self->m20) {
        self->m20->Delete(3);
    }
    if (self->m24) {
        self->m24->Delete(3);
    }
    if (self->m1C) {
        self->m1C->Delete(3);
    }
    D_0038FC00 = 0;
    func_00182A10(self, flags);
}
