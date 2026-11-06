extern "C" int func_001E8870(void* params, unsigned int name, int* out, int flags);

struct Base_001B74F0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    virtual ~Base_001B74F0();
    virtual void V1(void* params);
    virtual void V2(void* params);
};

struct Obj_001B74F0 : Base_001B74F0 {
    void Method(void* params);
};

void Obj_001B74F0::Method(void* params)
{
    int v = 0;
    if (func_001E8870(params, 0x286A8D26, &v, 0))
        V2(params);
}
