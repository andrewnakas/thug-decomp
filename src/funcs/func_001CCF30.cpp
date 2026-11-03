typedef int qword __attribute__((mode(TI)));

struct Mat_001CCF30 {
    qword r[4];
};

struct Src_001CCF30 {
    char m_pad[0x70];
    Mat_001CCF30 m_70;
    void GetMatrix(Mat_001CCF30& out)
    {
        out.r[0] = m_70.r[0];
        out.r[1] = m_70.r[1];
        out.r[2] = m_70.r[2];
        out.r[3] = m_70.r[3];
    }
};

struct Obj_001CCF30 {
    char m_pad0[0xC];
    Src_001CCF30* m_C;
    char m_pad1[0x28 - 0x10];
    float m_28;
    char m_pad2[0x40 - 0x2C];
    Mat_001CCF30 m_40;
    float m_80;
    void Init(void* params);
};

extern char D_003636D8[];
extern void* D_0038C608;
extern "C" void func_001E84E8(void* params, char* name, int* out, int flag);
extern "C" void* func_00187B48(void* mgr, int id);
extern "C" void func_001CDFB0(Obj_001CCF30* self, void* p);

void Obj_001CCF30::Init(void* params)
{
    int id = 0;
    func_001E84E8(params, D_003636D8, &id, 1);
    func_001CDFB0(this, func_00187B48(D_0038C608, id));
    m_80 = 1.0f;
    m_28 = 1.0f;
    m_C->GetMatrix(m_40);
}
