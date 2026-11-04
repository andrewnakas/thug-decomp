extern char D_00361C08[];
extern char D_00361C30[];
extern char D_00361C48[];
extern char D_00361C70[];
extern char D_00361C88[];
extern char D_00361CA0[];
extern char D_00361CB8[];
extern char D_00361CD0[];
extern char D_0038C740[];
extern char D_0038C748[];
extern "C" int func_00103F28(char* fmt, ...);
extern "C" char* func_001E61F0(unsigned int id);

struct E_00188C20 {
    unsigned int m0;
    unsigned int m4;
    unsigned int m8;
    int mC;
    int m10;
    int m14;
    int m18;
};

struct L_00188C20 {
    E_00188C20* m_items;
    int m_count;
};

void Dump_00188C20(L_00188C20* list)
{
    func_00103F28(D_00361C08);
    func_00103F28(D_00361C30);
    if (list) {
        for (int i = 0; i < list->m_count; i++) {
            E_00188C20* e = &list->m_items[i];
            func_00103F28(D_00361C48);
            func_00103F28(D_00361C70, func_001E61F0(e->m0));
            func_00103F28(D_00361C88, func_001E61F0(e->m4));
            func_00103F28(D_00361CA0, func_001E61F0(e->m8));
            func_00103F28(D_00361CB8, e->m10 ? D_0038C740 : D_0038C748);
        }
    } else {
        func_00103F28(D_00361CD0);
    }
    func_00103F28(D_00361C08);
}
