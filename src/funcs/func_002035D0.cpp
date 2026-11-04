struct MsgDesc_002035D0 {
    unsigned char m_id;
    char pad1;
    unsigned short m_length;
    void* m_data;
    int m8;
    int m_priority;
    unsigned char m_queue;
    char pad11[0xF];
};

struct Comp_002035D0 {
    char pad[0x2C];
    int m2C;
};

struct Flag_002035D0 {
    char pad[0x1C];
    int m1C;
};

struct Timer_002035D0 {
    int m0;
    int m_active;
    int m_time;
};

struct Sub_002035D0 {
    char pad[0x9C];
    Timer_002035D0 m_timer;
};

struct Owner_002035D0 {
    char pad[0x5B0];
    Sub_002035D0* m5B0;
};

struct Pad_002035D0 {
    char pad[0x524];
    int m524;
};

class Base_002035D0 {
public:
    char pad0[0x8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void Stop();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void Teleport(int node);
};

class Skater_002035D0 : public Base_002035D0 {
public:
    char padC[0xC];
    unsigned short m18;
    char pad1A[0x2C0 - 0x1A];
    void* m2C0;
    int pad2C4;
    Pad_002035D0* m2C8;
    char pad2CC[0x14];
    Owner_002035D0* m2E0;
    int pad2E4[2];
    Flag_002035D0* m2EC;
    char pad2F0[0x2C];
    int m31C;
    int m320;
    int m324;
};

extern void* D_0038FC78;
extern void* D_00392068;

extern "C" Comp_002035D0* func_00185578(void* self, unsigned int name);
extern "C" bool func_002A19A8(void* self);
extern "C" int func_00215B68(int a, int b);
extern "C" int func_0010FC30();
extern "C" void func_001BAC48(void* self);
extern "C" void func_00205B30(Skater_002035D0* self, int a, int b);
extern "C" void func_00291AD8(void* self);
extern "C" void func_00203E80(Skater_002035D0* self, int v);
extern "C" void* func_00203EE0(Skater_002035D0* self);
extern "C" void func_00185058(void* self);
extern "C" void* func_001E55B8(unsigned int name, int assert_);
extern "C" void* func_001E9378(void* self, int index);
extern "C" bool func_001E8398(void* self, unsigned int name, unsigned int* out, int assert_);
extern "C" void func_00184BC0(Skater_002035D0* self, unsigned int id, int node, int a, int b, int c);
extern "C" void func_00186398(Skater_002035D0* self, int v);
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F938(void* self);
extern "C" MsgDesc_002035D0* func_001FA800(MsgDesc_002035D0* self);
extern "C" void* func_002A39E0(void* self, int id);
extern "C" void* func_002A52F0(void* self, int id);
extern "C" void func_002B2010(void* self);
extern "C" void func_00200C00(void* self, MsgDesc_002035D0* msg);

void func_002035D0(Skater_002035D0* self, int node, int restart)
{
    unsigned int script;

    void* skater = D_0038FC78;
    void* game = D_00392068;
    func_00185578(self, 0xD9151D4D)->m2C = 1;
    if (self->m31C) {
        self->m2C8->m524 = 0;
        self->Stop();
        if (self->m2EC)
            self->m2EC->m1C = 1;
        if (func_002A19A8(game)) {
            func_00215B68(0, 0);
            Timer_002035D0* t = &self->m2E0->m5B0->m_timer;
            if (t->m_active) {
                t->m_active = 0;
                t->m_time = func_0010FC30();
            }
        }
    }
    if (self->m2C0)
        func_001BAC48(self->m2C0);
    if (node != -1)
        self->Teleport(node);
    func_00205B30(self, restart, 0);
    if (self->m31C) {
        func_00291AD8(func_00185578(self, 0x488AF07A));
        if (self->m31C) {
            if (!self->m324) {
                func_00203E80(self, 1);
                void* x = func_00203EE0(self);
                if (x)
                    func_00185058(x);
            }
            if (node != -1 && func_001E8398(func_001E9378(func_001E55B8(0xC472ECC5, 0), node), 0x2CA8A299, &script, 0))
                func_00184BC0(self, script, node, 0, 0, 0);
        }
    }
    func_00186398(self, 1);
    if (func_0024F938(func_0022E358(skater)) == 0x6C5FF266 || func_0024F938(func_0022E358(skater)) == 0x6EF8FDA0
        || func_0024F938(func_0022E358(skater)) == 0x5D32129C) {
        MsgDesc_002035D0 msg;
        func_001FA800(&msg);
        void* server = func_002A39E0(game, self->m320);
        func_002B2010(func_002A52F0(game, self->m18));
        msg.m_id = 0x57;
        msg.m_priority = 2;
        msg.m_queue = 8;
        func_00200C00(server, &msg);
    }
}
