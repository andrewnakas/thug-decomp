extern char D_003735A8[];

struct List_002381E0 {
    int m0;
    int m_size;
};

extern "C" void* func_0023B2B8(List_002381E0* list, int* key, int* out);
extern "C" void func_0023B380(List_002381E0* list, int* key);

struct Iter_002381E0 {
    List_002381E0* m_list;
    int GetSize() { return m_list->m_size; }
    void* First(int* key, int* out) { return func_0023B2B8(m_list, key, out); }
    void Remove(int* out) { func_0023B380(m_list, out); }
};

struct Score_002381E0 {
    short m0;
    short m_skater;
    int m_rating;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    char m_log[0x68 - 0x2C];
    int m68;
};

struct Skater_002381E0 {
    char m_pad[0x31C];
    int m_local;
};

extern void* D_0038FC78;
extern void* D_00388A70;

extern "C" Skater_002381E0* func_0022DF08(void* self, int index);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_0023AC98(Score_002381E0* self);
extern "C" void func_00238728(Score_002381E0* self);
extern "C" Iter_002381E0* func_0023B370(Iter_002381E0* out, void* table);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_00238780(Score_002381E0* self, int a);
extern "C" void func_00238EF8(Score_002381E0* self, int a, int b);
extern "C" void* func_0022E358(void* self);
extern "C" unsigned int func_0024F938(void* self);
extern "C" void func_0023AC30(Score_002381E0* self, int a);
extern "C" void func_002383A8(Score_002381E0* self);
extern "C" void* func_00185578(void* self, unsigned int id);
extern "C" void func_0029E5C0(void* comp);

static inline void FreeAll_002381E0(Iter_002381E0* it, void* table)
{
    func_0023B370(it, table);
    int size = it->GetSize();
    for (int i = 0; i < size; i++) {
        int key = 0;
        int out;
        void* p = it->First(&key, &out);
        it->Remove(&out);
        if (p) {
            func_0010A8D8(D_00388A70, p);
        }
    }
}

void func_002381E0(Score_002381E0* self)
{
    void* mgr = D_0038FC78;
    Skater_002381E0* skater = func_0022DF08(mgr, self->m_skater);
    func_00103F28(D_003735A8);
    func_0023AC98(self);
    func_00238728(self);
    Iter_002381E0 it;
    FreeAll_002381E0(&it, self->m_log);
    if (skater && skater->m_local) {
        func_00238780(self, 0);
        func_00238EF8(self, 0, 0);
    }
    if (func_0024F938(func_0022E358(mgr)) == 0xBFF33600 || func_0024F938(func_0022E358(mgr)) == 0x3D6D444F) {
        self->m_rating = 100;
    } else {
        self->m_rating = 0;
    }
    self->mC = 0;
    self->m18 = 0;
    self->m1C = 0;
    self->m68 = 0;
    self->m28 = 0;
    func_0023AC30(self, 0);
    self->m10 = 0;
    self->m8 = 0;
    func_002383A8(self);
    Skater_002381E0* s = func_0022DF08(D_0038FC78, self->m_skater);
    if (s && s->m_local) {
        func_0029E5C0(func_00185578(s, 0x8BCE7E66));
    }
}
