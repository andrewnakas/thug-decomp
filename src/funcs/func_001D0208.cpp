/* sym: __13Base_001D0208 = 0x001D0FB0 */
/* sym: _vt$10A_001D0208 = 0x00363AD8 */
/* sym: _vt$10B_001D0208 = 0x00363C48 */
/* sym: _vt$10C_001D0208 = 0x00363CF8 */
/* sym: _vt$10D_001D0208 = 0x00363B80 */
/* sym: _vt$10E_001D0208 = 0x00363E38 */
extern "C" void* func_001046B0(unsigned int size);
extern "C" int func_001CFFA0(void* self, char* name);
extern "C" int func_001E53A0(unsigned int name, int flags);
extern "C" int func_001F0D78(char* name);
extern "C" int func_001D0DD8(void* table, const int* key, void* value);
extern "C" void func_001D1070(void* obj, int key);

class Base_001D0208 {
public:
    int m0;
    int m4;
    int m8;
    char mC;
    char mD;
    char padE[0xA];
    Base_001D0208* m18;
    Base_001D0208* m1C;
    Base_001D0208();
    virtual ~Base_001D0208();
    virtual int Init(char* name, void* a, void* b, void* c, void* d);
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual int V11();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class A_001D0208 : public Base_001D0208 {
public:
    A_001D0208() {}
    virtual ~A_001D0208();
};

class B_001D0208 : public Base_001D0208 {
public:
    B_001D0208() {}
    virtual ~B_001D0208();
};

class C_001D0208 : public Base_001D0208 {
public:
    C_001D0208() {}
    virtual ~C_001D0208();
};

class D_001D0208 : public Base_001D0208 {
public:
    D_001D0208() {}
    virtual ~D_001D0208();
};

class E_001D0208 : public Base_001D0208 {
public:
    int m24;
    E_001D0208() {}
    virtual ~E_001D0208();
};

struct Mgr_001D0208 {
    char pad[0xC];
    void* m_table;
    Base_001D0208* m_head;
    int Create(char* name, void* a, void* b, int c, int d, void* e, void* f);
};

int Mgr_001D0208::Create(char* name, void* a, void* b, int c, int d, void* e, void* f)
{
    Base_001D0208* p = 0;
    switch (func_001CFFA0(this, name)) {
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        p = new A_001D0208;
        break;
    case 6:
        p = new B_001D0208;
        break;
    case 7:
        p = new C_001D0208;
        break;
    case 8:
        p = new D_001D0208;
        break;
    case 9:
        p = new E_001D0208;
        break;
    }
    p->mC = c;
    p->m8 = d;
    p->mD = 0;
    if (p->Init(name, a, b, e, f)) {
        if (!func_001E53A0(0x25DC7904, 0))
            delete p;
        return 0;
    }
    int key = func_001F0D78(name);
    func_001D0DD8(m_table, &key, p);
    func_001D1070(p, key);
    p->m1C = m_head;
    p->m18 = m_head->m18;
    m_head->m18->m1C = p;
    m_head->m18 = p;
    return p->V11();
}
