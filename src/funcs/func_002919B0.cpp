struct Node_002919B0 { char pad[0x18]; int m18; };
struct Aux_002919B0 { char pad[0x244]; int m244; };
extern void* D_00392068;
extern "C" void* func_002A52F0(void* table, unsigned short id);
extern "C" int func_002B30A0(void*);
extern "C" int* func_002A39E0(void*, int);
extern "C" void func_0027C928(void*);

struct Obj_002919B0;
extern "C" void func_00291A78(Obj_002919B0*);
extern "C" int func_002918E0(Obj_002919B0*, int, int, int, int);

struct Obj_002919B0 {
    char pad0[0xC];
    Node_002919B0* m_node;
    char pad1[0x1C - 0x10];
    int m1C;
    int m20;
    int m24;
    int m28;
    char pad2[0x30 - 0x2C];
    Aux_002919B0* m30;
    void* m34;
    void Update();
};

void Obj_002919B0::Update()
{
    if (m20) {
        func_00291A78(this);
        m20 = 0;
    }
    if (m24) {
        func_0027C928(m34);
        m24 = 0;
    }
    if (m28) {
        void* pl = func_002A52F0(D_00392068, m_node->m18);
        void* mg = D_00392068;
        int* c = func_002A39E0(mg, func_002B30A0(pl));
        func_002918E0(this, m_node->m18, m1C ^ 1, *c, 1);
        m28 = 0;
    }
    m30->m244 = 0;
}
