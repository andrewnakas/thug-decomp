typedef int qword_0020B0A0 __attribute__((mode(TI)));

struct Vec_0020B0A0 {
    qword_0020B0A0 q;
};

struct Mat_0020B0A0 {
    Vec_0020B0A0 row[4];
    Mat_0020B0A0& operator=(const Mat_0020B0A0& o)
    {
        row[0] = o.row[0];
        row[1] = o.row[1];
        row[2] = o.row[2];
        row[3] = o.row[3];
        return *this;
    }
};

struct Obj_0020B0A0 {
    char pad0[0x50];
    Vec_0020B0A0 m_pos;
    char pad60[0x10];
    Mat_0020B0A0 m_mat;
};

class CompBase_0020B0A0 {
public:
    char pad0[0x18];
    virtual void Func0();
    virtual void Refresh();
};

class Comp_0020B0A0 : public CompBase_0020B0A0 {
public:
    int m_1C;
    int m_20;
};

extern void* D_0038C608;

extern "C" Obj_0020B0A0* func_00187B48(void* mgr, unsigned int id);
extern "C" Comp_0020B0A0* func_00185578(Obj_0020B0A0* o, unsigned int type);
extern "C" void* func_0013B0E8(void* model);
extern "C" const Mat_0020B0A0* func_00114E48(void* frame);
extern "C" const Vec_0020B0A0* func_00114E18(void* frame);
extern "C" void func_0013B040(void* model, int a);

bool func_0020B0A0(unsigned int id, void* model, bool sync)
{
    Obj_0020B0A0* o = func_00187B48(D_0038C608, id);
    if (!o)
        return false;
    Comp_0020B0A0* c = func_00185578(o, 0xC4E311FA);
    if (!c)
        return true;
    if (sync) {
        o->m_mat = *func_00114E48(func_0013B0E8(model));
        o->m_pos = *func_00114E18(func_0013B0E8(model));
        c->Refresh();
    }
    func_0013B040(model, c->m_20);
    return true;
}
