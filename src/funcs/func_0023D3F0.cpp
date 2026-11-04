
class Base_0023D3F0 {
public:
    char pad0[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual bool Check();
};


struct Graph_0023D3F0 {
    char pad0[0x1C];
    void* m1C;
    bool Has(unsigned int name);
};

extern "C" Base_0023D3F0* func_0023BAD8(Graph_0023D3F0* g, unsigned int name, int a);
extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

bool Graph_0023D3F0::Has(unsigned int name)
{
    Base_0023D3F0* n = func_0023BAD8(this, name, 0);
    if (n) return n->Check();
    void* p;
    int v = 0;
    if (func_001E8180(m1C, name, &p, 0)) func_001E7DE8(p, 0x49807745, &v, 1);
    return v != 0;
}
