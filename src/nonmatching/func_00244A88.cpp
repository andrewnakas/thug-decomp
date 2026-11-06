/* fuzzy: 97.9 */
/* near miss: 9 words, only $s2/$s3 swapped between 'record' (game s2) and 'net' (game s3); tried decl orders/types */
struct Link_00244A88 {
    int m_id;
    int m4;
    int m8;
};

struct Comp_00244A88 {
    char pad[0x1C];
    void* m1C;
};

struct Score_00244A88 {
    char pad[0x18];
    int m18;
};

struct Base_00244A88 {
    char pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual int V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual int V11(int a, int b);
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual int V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
};

struct Goal_00244A88 : Base_00244A88 {
    char pad18[0x20 - 0x18];
    void* m_20;
    char pad24[0x2C - 0x24];
    Link_00244A88* m_2C;
    char pad30[0x44 - 0x30];
    int m_44;
    char pad48[4];
    unsigned int m_4C;
    int m_50;
    char pad54[0x64 - 0x54];
    unsigned int m_64;
    bool Win();
};

extern void* D_00392068;
extern void* D_0038FC78;
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" bool func_002A19A8(void* net);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void* func_0022DD38(void* mgr);
extern "C" Comp_00244A88* func_00185578(void* obj, unsigned int name);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" int func_002392B8(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_00248388(Goal_00244A88* self, void* params, int a);
extern "C" void func_001E78A8(void* params, unsigned int name, void* value);
extern "C" void func_00248630(Goal_00244A88* self);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001E6D18(void* params, unsigned int name);
extern "C" int func_00248800(Goal_00244A88* self, unsigned int name);
extern "C" void func_00244378(Goal_00244A88* self, int a, int b);
extern "C" void* func_00240850();
extern "C" Goal_00244A88* func_0023BAD8(void* owner, int id, int create);
extern "C" void func_00243FB0(Goal_00244A88* goal);
extern "C" void func_0023BC10(void* owner, int id, int a);

bool Goal_00244A88::Win()
{
    func_001E7200(m_20, 0xC22A2B72, 0);
    Link_00244A88* link = m_2C;
    if (!link->m_id) {
        func_001E7360(m_20, 0, 0xC309CAD1);
        bool record = false;
        m_44++;
        void* net = D_00392068;
        if (!func_002A19A8(net)) {
            unsigned int type;
            if (func_001E8398(m_20, 0x96963902, &type, 0)) {
                if (type == 0xCD66C8AE) {
                    int score;
                int given;
                if (func_001E7DE8(m_20, 0xFC9630AB, &given, 0)) {
                    score = given;
                } else {
                    Score_00244A88* s = (Score_00244A88*)func_00185578(func_0022DD38(D_0038FC78), 0xD262802F)->m1C;
                    if (func_001E8708(m_20, 0xC63432A7)) {
                        score = s->m18;
                    } else {
                        score = func_002392B8(s);
                    }
                }
                if (m_50 < score) {
                        m_50 = score;
                        func_001E7200(m_20, 0xC22A2B72, score);
                        record = true;
                    }
                } else if (type == 0x906B67BA) {
                    if (m_64 < m_4C) {
                        m_4C = m_64;
                        func_001E7200(m_20, 0xC22A2B72, m_64);
                        record = true;
                    }
                }
            }
        }
        if (!V17() && !func_002A19A8(net)) {
            void* p = func_001E6978(func_001190D0(8));
            func_00248388(this, p, 1);
            if (record) {
                func_001E7360(p, 0, 0xE7B8254F);
            }
            func_001E78A8(m_20, 0x128B3088, p);
            func_00248630(this);
        } else {
            func_001E6B90(m_20, 0x128B3088);
        }
        if (record) {
            func_001E7360(m_20, 0, 0xE7B8254F);
        } else {
            func_001E6D18(m_20, 0xE7B8254F);
        }
        func_00248800(this, 0x90FF204D);
        bool keep = func_001E8708(m_20, 0x54D3CAC1);
        if (V3()) {
            V11(0, 1);
        }
        if (!keep) {
            V23();
        }
        if (func_002A19A8(net)) {
            func_00244378(this, 0, 0);
        }
        func_001E6D18(m_20, 0xC309CAD1);
        return true;
    } else {
        void* owner = func_00240850();
        V11(0, 1);
        func_00244378(this, 0, 0);
        func_00243FB0(func_0023BAD8(owner, link->m_id, 1));
        func_0023BC10(owner, link->m_id, 0);
        link->m8 = 1;
    }
    return true;
}
