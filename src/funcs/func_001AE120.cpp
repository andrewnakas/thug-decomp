extern "C" void* func_001190D0(unsigned int size);

class Struct1E6978 {
public:
    int m_w[2];
    Struct1E6978();
    ~Struct1E6978();
    static void* operator new(unsigned int size) { return func_001190D0(size); }
};

struct Obj_001AE120 {
    int m_pad[5];
    void* m14;
};

struct Flag_001AE120 {
    int m_pad[78];
    int m138;
};

struct Entry_001AE120 {
    int m_script;
    int m_arg;
    int m8;
    int mC;
    int m10;
};

struct C_001AE120 {
    int m_pad[3];
    Obj_001AE120* mC;
    int m10[9];
    Flag_001AE120* m34;
    int m38[652];
    int mA68;
    void* mA6C;
    int mA70;
    int mA74;
    Entry_001AE120 mA78[1];
    void Run(unsigned int a, void* b, void* params);
};

extern "C" void func_001ADD78(C_001AE120* self);
extern "C" void func_00184A40(void* obj);
extern "C" void func_001EEF18(void* p, unsigned int a, void* b);
extern "C" void* func_001E55B8(int id, int flags);
extern "C" void* func_001E9378(void* scr, int arg);
extern "C" int func_001ADF90(C_001AE120* self, void* p, void* extra, void* params);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void func_001E7200(Struct1E6978* s, unsigned int name, unsigned int v);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_00184AB0(void* obj, unsigned int a, void* b);
extern "C" int func_001EFDC0(void* p);
extern "C" int func_001B0E78(C_001AE120* self);
extern "C" void* func_001E5548(unsigned int id, int flags);

void C_001AE120::Run(unsigned int a, void* b, void* params)
{
    m34->m138 = 0;
    mA68 = 0;
    while (mA70 != -1) {
        int one = 1;
        int i = mA70;
        int script = mA78[i].m_script;
        int arg = mA78[i].m_arg;
        mA68 = mA78[i].m10;
        func_001ADD78(this);
        if (!script)
            continue;
        if (a) {
            func_00184A40(mC);
            func_001EEF18(mC->m14, a, b);
        }
        void* scr = func_001E9378(func_001E55B8(script, 0), arg);
        if (func_001ADF90(this, scr, 0, params))
            return;
        unsigned int id = 0;
        func_001E8398(scr, 0xA92A2280, &id, 0);
        if (!id)
            return;
        unsigned int v = 0;
        if (func_001E7DE8(mA6C, id, &v, 0)) {
            Struct1E6978* s = new Struct1E6978;
            func_001E7200(s, 0xB4A39841, v);
            func_001E6AC8(s, params);
            Obj_001AE120* o = mC;
            func_00184AB0(o, 0x2D90485D, s);
            delete s;
            func_001EFDC0(o->m14);
            m34->m138 = one;
            func_001B0E78(this);
            return;
        }
        unsigned int w = 0;
        func_001E8398(mA6C, id, &w, 0);
        if (!w)
            return;
        void* s2 = func_001E5548(w, 0);
        if (!s2)
            return;
        func_001ADF90(this, s2, 0, params);
        return;
    }
}
