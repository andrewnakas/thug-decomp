struct Entry_00238780 {
    char m_pad[0x5C];
    char m_text[4];
};

struct Self_00238780 {
    short m0;
    short m_player;
    char m_pad4[0x44 - 0x4];
    char m_list[0x14];
};

struct Ref_00238780 {
    void* m_ptr;
    int m4;
    int m8;
    int mC;
};

extern void* D_0038FC78;
extern void* D_00389A30;
extern char D_00373658[];
extern char D_00373668[];

extern "C" void* func_0022DF08(void* game, int player);
extern "C" int func_002041F8(void* skater);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_0012DB48(Ref_00238780* out, void* mgr, unsigned int id, int a);
extern "C" void func_00183CB8(void* obj, Ref_00238780* ref);
extern "C" Entry_00238780* func_0023AFE8(void* list, int index);
extern "C" int func_0023B000(void* list);
extern "C" void func_001276E0(void* elem, char** lines, int count);
extern "C" void func_001F0370(const char* script, void* a, int b, int c);

void func_00238780(Self_00238780* self, int clear)
{
    void* mgr = D_00389A30;
    int offset = 0;
    void* skater = func_0022DF08(D_0038FC78, self->m_player);
    if (skater) {
        offset = func_002041F8(skater);
    }
    Ref_00238780 ref;
    char* lines[252];
    func_0012DB48(&ref, mgr, func_001F0D78(D_00373658) + offset, 0);
    void* elem = ref.m_ptr;
    if (ref.m_ptr) {
        func_00183CB8(ref.m_ptr, &ref);
        ref.m_ptr = 0;
    }
    if (elem) {
        if (!clear) {
            int i;
            for (i = 0; i < func_0023B000(self->m_list); i++) {
                lines[i] = func_0023AFE8(self->m_list, i)->m_text;
            }
            func_001276E0(elem, lines, func_0023B000(self->m_list));
        } else {
            func_001276E0(elem, lines, 0);
        }
        func_001F0370(D_00373668, 0, 0, 0);
    }
}
