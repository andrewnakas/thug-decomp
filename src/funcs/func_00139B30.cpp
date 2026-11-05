struct Tex_00139B30 {
    int m0;
    unsigned short m4;
};

extern "C" void func_0010BFC0(char* name);
extern "C" void func_0010BFC8();
extern "C" Tex_00139B30* func_00139D70(int key);
extern "C" Tex_00139B30* func_0014A028(int key, int a1, int a2, int a3, int t0, int t1, int t2);
extern "C" void func_0013AA58(void* table, int* key, Tex_00139B30* t);
extern char D_003C38C0[];
extern char D_0035DFE0[];

extern "C" Tex_00139B30* func_00139B30(int base, int a1, int a2, int a3, int index, int t1, int t2)
{
    func_0010BFC0(D_0035DFE0);
    int key = base + index;
    Tex_00139B30* t = func_00139D70(key);
    if (t) {
        t->m4++;
    } else {
        t = func_0014A028(key, a1, a2, a3, index, t1, t2);
        t->m0 = key;
        func_0013AA58(D_003C38C0, &key, t);
    }
    func_0010BFC8();
    return t;
}
