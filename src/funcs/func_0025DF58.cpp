typedef int qword_0025DF58 __attribute__((mode(TI)));

struct Vec_0025DF58 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_0025DF58 q;
    };
};

struct Mat_0025DF58 {
    Vec_0025DF58 row[4];
};

struct Flags_0025DF58 {
    char m_pad[0x1B0];
    unsigned long m_a : 2;
    long m_flags : 32;
    int GetFlags() const { return m_flags; }
};

class Base_0025DF58 {
public:
    char m_pad0[0x18];
    virtual void V0();
    virtual void Refresh();
};

class Comp_0025DF58 : public Base_0025DF58 {
public:
    char m_pad1c[0x50 - 0x1C];
    Vec_0025DF58 m_pos;
    char m_pad60[0xC0 - 0x60];
    Vec_0025DF58 m_rot[3];
    char m_padF0[0x260 - 0xF0];
    Flags_0025DF58* m_model;
    char m_pad264[0x288 - 0x264];
    int m_attached;
    void Sync();
};

extern "C" Comp_0025DF58* func_00185578(void* obj, unsigned int name);
extern "C" void* func_0018DF68(Comp_0025DF58* c);
extern "C" Comp_0025DF58* func_00184D70(void* p);
extern "C" void* func_0013D8A8(void* model);
extern "C" void func_00137BE8(void* p, float f);
extern "C" void func_0018CAF0(Comp_0025DF58* c);
extern "C" int func_0019EBD0(void* p);
extern "C" void func_0013CD08(void* model, Mat_0025DF58* mat, int a, int b);
extern "C" int func_0013D0C8(void* model, int b);

void Comp_0025DF58::Sync()
{
    Comp_0025DF58* c = func_00185578(this, 0x286A8D26);
    if (!c) {
        return;
    }
    if (c->m_model->GetFlags() & 1) {
        return;
    }
    if (c->m_attached) {
        Comp_0025DF58* root = func_00184D70(func_0018DF68(c));
        Comp_0025DF58* rc = func_00185578(root, 0x286A8D26);
        Flags_0025DF58* model = rc->m_model;
        func_00137BE8(func_0013D8A8(model), 0.0f);
        func_0018CAF0(rc);
        void* o = func_00185578(this, 0x222756D5);
        Mat_0025DF58 mat;
        mat.row[0].q = m_rot[0].q;
        mat.row[1].q = m_rot[1].q;
        mat.row[2].q = m_rot[2].q;
        mat.row[3].q = m_pos.q;
        func_0013CD08(model, &mat, 0, func_0019EBD0(o));
        func_0013D0C8(model, func_0019EBD0(o));
        root->m_pos.q = m_pos.q;
    } else {
        func_0018CAF0(c);
        c->Refresh();
    }
}
