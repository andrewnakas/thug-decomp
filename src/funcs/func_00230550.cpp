typedef int qword_00230550 __attribute__((mode(TI)));

struct Vec_00230550 {
    union {
        float col[4];
        qword_00230550 q;
    };
};

struct Mat_00230550 {
    Vec_00230550 row[4];
};

struct Model_00230550 {
    char pad0[0x50];
    Vec_00230550 m_pos;
    char pad60[0x10];
    Mat_00230550 m_mat;
};

struct Inst_00230550 {
    int m0;
    int m4;
    int m8;
    Model_00230550* m_model;
    int m10;
    Inst_00230550* m_next;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void* GetShadow();
};

struct Game_00230550 {
    char pad0[0x28];
    void* m28;
    char pad2C[0x468 - 0x2C];
    int m468;
};

extern Game_00230550* D_0038FC78;
extern void* D_0038C608;
extern "C" void func_0026AE00(void* p, Mat_00230550* m);
extern "C" Inst_00230550* func_00187278(void* list, unsigned int name);

void func_00230550()
{
    if (!D_0038FC78->m468) return;
    func_0026AE00(D_0038FC78->m28, 0);
    for (Inst_00230550* i = func_00187278(D_0038C608, 0x1CDFB2A3); i; i = i->m_next) {
        Model_00230550* m = i->m_model;
        Mat_00230550 mat = m->m_mat;
        mat.row[0].col[3] = 0.0f;
        mat.row[1].col[3] = 0.0f;
        mat.row[2].col[3] = 0.0f;
        mat.row[3] = m->m_pos;
        mat.row[3].col[3] = 1.0f;
        void* s = i->GetShadow();
        if (s) func_0026AE00(s, &mat);
    }
}
