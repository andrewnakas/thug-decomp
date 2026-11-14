/* force: {"kind": "reorg", "uid": 219, "pred": 1} */
typedef int qword_00145DC0 __attribute__((mode(TI)));

struct Vec_00145DC0 {
    qword_00145DC0 q;
};

struct Mat_00145DC0 {
    Vec_00145DC0 row[4];
};

struct Node_00145DC0 {
    int m0;
    int m_data;
    int m_pri;
    Node_00145DC0* m_next;
};

class Obj_00145DC0 {
public:
    int m0;
    int m4;
    int m8;
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
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void Render(int a, int b);
};

struct Viewport_00145DC0 {
    char pad[0x18];
    void* m_camera;
};

extern int D_0038A0E8;
extern unsigned int D_0039424C;
extern int D_00394250;
extern int D_00394254;
extern float D_003875E8;
extern void* D_00389C34;
extern void* D_00389C38;

extern "C" void func_00177A60();
extern "C" void func_00177D50();
extern "C" int func_0016D5E8();
extern "C" void func_0016D610();
extern "C" Viewport_00145DC0* func_0013AF50(int i);
extern "C" Vec_00145DC0* func_00114E18(void* cam);
extern "C" Mat_00145DC0* func_00114E48(void* cam);
extern "C" float func_00114DB0(void* cam);
extern "C" float func_00114AF0(Viewport_00145DC0* vp);
extern "C" void func_0016C940(Vec_00145DC0* pos);
extern "C" void func_00178088(int i, Mat_00145DC0* m, Viewport_00145DC0* vp, int split, float fov, float aspect, float a, float b);
extern "C" void func_00178060();
extern "C" void func_001688F0();
extern "C" void func_0017B4E8();
extern "C" int func_00177A58();
extern "C" void func_001411E0();
extern "C" void func_001427E8(void* p);
extern "C" float func_0010FAB8();
extern "C" void func_00145670(void* p, float t);
extern "C" void func_00145698(void* p);
extern "C" void func_00143E80();
extern "C" void func_00144078();
extern "C" Node_00145DC0* func_00132480(int i);
extern "C" void* func_00185578(int obj, unsigned int name);
extern "C" Obj_00145DC0* func_001A41C8(void* comp);
extern "C" void func_00143918(int i, int a);

extern "C" void func_00145DC0()
{
    func_00177A60();
    func_00177D50();
    int locked = func_0016D5E8();
    for (int i = 0; i < D_0038A0E8; i++) {
        Viewport_00145DC0* vp = func_0013AF50(i);
        void* cam = vp->m_camera;
        if (cam) {
            func_0016C940(func_00114E18(cam));
            Mat_00145DC0 m = *func_00114E48(cam);
            m.row[3] = *func_00114E18(cam);
            float fov = func_00114DB0(cam);
            float aspect = func_00114AF0(vp);
            func_00178088(i, &m, vp, D_0039424C >= 2, fov, aspect, -1.0f, D_003875E8);
            func_00178060();
            func_001688F0();
            func_0017B4E8();
            if (func_00177A58()) {
                func_001411E0();
                func_001427E8(D_00389C34);
                func_00145670(D_00389C38, func_0010FAB8());
                func_00145698(D_00389C38);
                func_00143E80();
                func_00144078();
            }
            func_00178060();
            if (D_0039424C) {
                Node_00145DC0* n = func_00132480(i)->m_next;
                for (;;) {
                    Node_00145DC0* c = 0;
                    if (n->m_data != -1)
                        c = n;
                    if (!c)
                        break;
                    void* comp = func_00185578(c->m_data, 0xA432DC41);
                    if (comp) {
                        Obj_00145DC0* o = func_001A41C8(comp);
                        if (o)
                            o->Render(D_00394254, D_00394250);
                    }
                    n = c->m_next;
                }
            }
        }
        func_00143918(i, 0);
    }
    if (locked)
        func_0016D610();
}
