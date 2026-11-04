extern char D_00366888[];
extern char D_00366730[];
extern char D_00366740[];
extern char D_00366750[];
extern char D_00366760[];
extern char D_00366778[];
extern char D_00366790[];
extern char D_003667A8[];
extern char D_003667C0[];
extern char D_0038EBC0[];
extern char D_003667D8[];
extern char D_003667E8[];
extern char D_00366800[];
extern char D_00366810[];
extern char D_00366820[];
extern char D_00366830[];
extern char D_00366848[];
extern char D_00366858[];
extern char D_00366868[];

extern "C" int func_0031BB90();
extern "C" int func_0031BB30(int thread, int priority);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct Node_001F9AB8 {
    int m0;
    unsigned int m_key;
    int m4;
    Node_001F9AB8* m_prev;
    Node_001F9AB8* m_next;
    void* m_vt;
};

struct Entry_001F9AB8 {
    char m_name[16];
};

struct Obj_001F9AB8 {
    int m0;
    Node_001F9AB8 m_list0;
    Node_001F9AB8 m_list1;
    char pad34[0x134 - 0x34];
    int m134;
    char pad138[0x13C - 0x138];
    char m13C[0x150 - 0x13C];
    Entry_001F9AB8 m_entries[3];
    char m180[0x10];
    char m190[0x2A0 - 0x190];
    int m2A0;
    int m2A4;
    int m2A8;
    int m2AC;
    int m2B0;
    int m2B4;
    int m2B8;
    char pad2BC[4];
    int m2C0;
    int m2C4;
    int m2C8;
    int m2CC;
    int m2D0;
};

extern "C" void func_001FA670(Obj_001F9AB8* self, unsigned char id, const char* name);
extern "C" void func_001FA688(Obj_001F9AB8* self, unsigned char id, int flag);

static inline void InitNode(Node_001F9AB8* n)
{
    n->m_key = 0xFFFFFFFF;
    n->m4 = 0;
    n->m_prev = n;
    n->m_next = n;
    n->m_vt = D_00366888;
}

Obj_001F9AB8* Construct_001F9AB8(Obj_001F9AB8* self)
{
    InitNode(&self->m_list0);
    InitNode(&self->m_list1);
    func_0031BB30(func_0031BB90(), 11);
    self->m2C4 = 0;
    self->m2CC = 0;
    self->m2D0 = 0;
    self->m2C8 = 0;
    for (int i = 0; i < 255; i++) {
        func_001FA670(self, i, D_00366730);
        func_001FA688(self, i, 0);
    }
    func_001FA670(self, 1, D_00366740);
    func_001FA670(self, 2, D_00366750);
    func_001FA670(self, 3, D_00366760);
    func_001FA670(self, 4, D_00366778);
    func_001FA670(self, 5, D_00366790);
    func_001FA670(self, 6, D_003667A8);
    func_001FA670(self, 7, D_003667C0);
    func_001FA670(self, 8, D_0038EBC0);
    func_001FA670(self, 0x11, D_003667D8);
    func_001FA670(self, 0x10, D_003667E8);
    func_001FA670(self, 9, D_00366800);
    func_001FA670(self, 10, D_00366810);
    func_001FA670(self, 11, D_00366820);
    func_001FA670(self, 12, D_00366830);
    func_001FA688(self, 9, 1);
    func_001FA688(self, 8, 1);
    func_003331D0(self->m13C, D_00366848);
    func_003331D0(self->m180, D_00366858);
    func_003331D0(self->m190, D_00366868);
    self->m2A0 = 0;
    self->m2B4 = 5;
    self->m134 = 0;
    self->m2AC = 0;
    self->m2A8 = 0;
    self->m2B0 = 0;
    self->m2A4 = 0;
    self->m2B8 = 0;
    for (int j = 2; j >= 0; j--) {
        self->m_entries[j].m_name[0] = 0;
    }
    self->m2C0 = 0x1068;
    return self;
}
