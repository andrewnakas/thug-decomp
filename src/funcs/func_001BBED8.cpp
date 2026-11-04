extern "C" void func_0026F938(void* p);
extern "C" void func_0026F1C0(void* p, void* arg);

struct Obj_001BBED8 {
    int m_pad[65];
    int m104;
};

struct C_001BBED8 {
    int m_pad[3];
    Obj_001BBED8* mC;
    int m10[4];
    int m20;
    int m24[319];
    int m520;
    int m524;
    int m528;
    void Update(void* arg);
};

extern "C" void func_001BC150(C_001BBED8* self, void* arg);
extern "C" int func_001BBD98(C_001BBED8* self);

void C_001BBED8::Update(void* arg)
{
    if (mC->m104 & 1) return;
    func_001BC150(this, arg);
    int r = func_001BBD98(this);
    int busy = m524 || m528;
    if (busy || r) {
        func_0026F938(m24);
        if (r) m20 = 0;
    } else {
        func_0026F1C0(m24, arg);
    }
}
