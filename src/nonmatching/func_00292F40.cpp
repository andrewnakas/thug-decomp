/* fuzzy: 93.8 */
struct V_00292F40 { float x, y, z, w; };
struct S_00292F40 { V_00292F40 pos; float h; float ang; char pad2[8]; };
struct Entry_00292F40 {
    int m0;
    char pad[0xC];
    S_00292F40 s;
    S_00292F40* S() { return &s; }
};
struct Struct_00292F40 { char pad[0x10]; };
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001E74C0(void* p, char* s, float x, float y, float z);
extern "C" void func_001E7318(void* p, char* name, float v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" char* func_00291EE0(unsigned int type, int v);
extern char D_00391DD0[];
extern char D_00391DD8[];
extern char D_00391E00[];
extern char D_00391E08[];
extern char D_00377350[];
extern char D_00377378[];

struct Obj_00292F40;
extern "C" int func_00292E88(Obj_00292F40*, int);

struct Obj_00292F40 {
    char pad0[0x114];
    unsigned int m114;
    char pad118[8];
    Entry_00292F40 m120[8];
    void Send(int i);
    Entry_00292F40* Get(int i) { return &m120[i]; }
    S_00292F40* S2(int i) { return &m120[i].s; }
};

void Obj_00292F40::Send(int i)
{
    Struct_00292F40 s;
    func_001E6978(&s);
    switch (m120[i].m0) {
    case 1:
        func_001E7360(&s, 0x7321A8D6, 0x061A741E);
        break;
    case 2:
        func_001E7360(&s, 0x7321A8D6, 0x1806DDF8);
        func_001E7138(&s, D_00391E00, D_00377350);
        break;
    case 3:
        func_001E7360(&s, 0x7321A8D6, 0x71FD11F5);
        {
            char* n = func_00291EE0(m114, i - 2);
            func_001E7138(&s, D_00391E00, n);
        }
        func_001E7360(&s, 0, 0x3BD176D9);
        break;
    }
    func_001E73C8(&s, D_00391DD0, func_00292E88(this, i));
    func_001E74C0(&s, D_00391DD8, m120[i].S()->pos.x, Get(i)->S()->pos.y + S2(i)->h, S2(i)->pos.z);
    func_001E7318(&s, D_00391E08, S2(i)->ang * 57.295776f);
    func_001F0370(D_00377378, &s, 0, 0);
    func_001E6AE8(&s, 2);
}
