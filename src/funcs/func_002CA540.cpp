extern char D_0037ABE0[];
extern char D_0037AC08[];
extern char D_0037AC90[];
extern char D_0037ACA0[];

struct St_002CA540 {
    int m0;
    int m4;
    char pad[8];
};

struct Item_002CA540 {
    int m0;
    char* m4;
    char pad8[0x150 - 8];
    signed char m150;
};

struct Item_002CA540;
struct Big_002CA540;
extern "C" Item_002CA540* func_002C0370(Big_002CA540* b, int i, int c);
struct Big_002CA540 {
    char pad[0x6A5C];
    int m6A5C;
};

struct Sub_002CA540 {
    int m0;
    Big_002CA540* m4;
    int Count() { return m4->m6A5C; }
    Item_002CA540* Get(int i) { return func_002C0370(m4, i, 0); }
};

extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" Item_002CA540* func_002C0370(Big_002CA540* b, int i, int c);
extern "C" void* func_001E6978(St_002CA540* p);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002CA540 {
    int m0;
    Sub_002CA540 m4;
    char padC[4];
    int m10;
    void Dump();
};

void Obj_002CA540::Dump()
{
    func_001F0370(D_0037ABE0, 0, 0, 0);
    func_001F0370(D_0037AC08, 0, 0, 0);
    for (int i = 0; i < m4.Count(); i++) {
        Item_002CA540* it = m4.Get(i);
        if (it->m150) {
            St_002CA540 st;
            func_001E6978(&st);
            func_001E7138(&st, D_0037AC90, it->m4);
            func_001F0370(D_0037ACA0, &st, 0, 0);
            func_001E6AE8(&st, 2);
        }
    }
    m10 = 0;
}
