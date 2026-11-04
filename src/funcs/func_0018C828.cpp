struct Mat_0018C828 {
    float m[16];
};

struct Model_0018C828 {
    char pad0[0x1B0];
    unsigned long m_flags;
    int Bit(int n) const { return (int)(m_flags >> n) & 1; }
    bool Active() const { return Bit(1) && !Bit(2); }
};

struct Obj_0018C828 {
    char pad0[0x260];
    Model_0018C828* m_model;
};

struct Comp_0018C828 {
    char pad0[0xC];
    void* m_obj;
    char pad10[0x260 - 0x10];
    Model_0018C828* m_model;
    void* m264;
    void* m268;
    void* m26C;
    float m_dist[4];
    int m_count;
    int m284;
    int m288;
    void Update();
};

extern "C" void func_0013CD08(Model_0018C828* m, Mat_0018C828* mat, int a, int b);
extern "C" void func_0013D0C8(Model_0018C828* m, int b);
extern "C" int func_0013EB18(Model_0018C828* m, int lod, int hide);
extern "C" void* func_00184D70(void* p);
extern "C" Obj_0018C828* func_00185578(void* obj, unsigned int name);
extern "C" void func_0018C340(Comp_0018C828* c, Mat_0018C828* mat);
extern "C" void* func_0018DF68();
extern "C" int func_0019EBD0(void* p);
extern "C" bool func_001A2480(void* p);
extern "C" float func_001AA0A0(void* p);

void Comp_0018C828::Update()
{
    Mat_0018C828 mat;
    if (m288) {
        void* obj = m_obj;
        Model_0018C828* model = func_00185578(func_00184D70(func_0018DF68()), 0x286A8D26)->m_model;
        Obj_0018C828* o = func_00185578(obj, 0x222756D5);
        func_0018C340(this, &mat);
        func_0013CD08(model, &mat, 0, func_0019EBD0(o));
        func_0013D0C8(model, func_0019EBD0(o));
        return;
    }
    if (!m_model) {
        return;
    }
    if (!m_model->Active()) {
        return;
    }
    func_0018C340(this, &mat);
    int b = 0;
    if (m264) {
        b = func_0019EBD0(m264);
    }
    bool vis = true;
    if (m268) {
        vis = func_001A2480(m268);
    }
    if (m_count > 0) {
        for (int i = 0; i < m_count + 1; i++) {
            func_0013EB18(m_model, i, 1);
        }
        float d = func_001AA0A0(m26C);
        int found = 0;
        for (int j = 0; j < m_count; j++) {
            if (d < m_dist[j] * m_dist[j]) {
                func_0013EB18(m_model, j, 0);
                found = 1;
            }
        }
        if (!found) {
            func_0013EB18(m_model, m_count, 0);
        }
    }
    func_0013CD08(m_model, &mat, !vis, b);
}
