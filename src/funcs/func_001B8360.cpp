typedef int qword_001B8360 __attribute__((mode(TI)));

struct Vec_001B8360 {
    union {
        qword_001B8360 q;
        struct {
            float x, y, z, w;
        };
    };
};

struct Mat_001B8360 {
    Vec_001B8360 row[4];
    void Ident()
    {
        row[0].x = 1.0f;
        row[0].y = 0.0f;
        row[0].z = 0.0f;
        row[0].w = 0.0f;
        row[1].x = 0.0f;
        row[1].y = 1.0f;
        row[1].z = 0.0f;
        row[1].w = 0.0f;
        row[2].x = 0.0f;
        row[2].y = 0.0f;
        row[2].z = 1.0f;
        row[2].w = 0.0f;
        row[3].x = 0.0f;
        row[3].y = 0.0f;
        row[3].z = 0.0f;
        row[3].w = 1.0f;
    }
};

struct Obj_001B8360 {
    char pad[0x70];
    Mat_001B8360 m_mat;
};

extern char D_00362EF0[];
extern void* D_0038C608;
extern "C" int func_001E8A50(void* params, const char* name, unsigned int* out, int req);
extern "C" void* func_00187B48(void* mgr, unsigned int id);
extern "C" void func_001BA430(void* self, void* obj);

struct C_001B8360 {
    char pad[0xC];
    Obj_001B8360* mC;
    char pad10[0x40];
    Vec_001B8360 m50;
    Vec_001B8360 m60;
    Vec_001B8360 m70;
    void Init(void* params);
};

void C_001B8360::Init(void* params)
{
    Obj_001B8360* o = mC;
    o->m_mat.Ident();
    m50 = o->m_mat.row[0];
    m60 = o->m_mat.row[1];
    m70 = o->m_mat.row[2];
    unsigned int id = 0;
    func_001E8A50(params, D_00362EF0, &id, 1);
    func_001BA430(this, func_00187B48(D_0038C608, id));
}
