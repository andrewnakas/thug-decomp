struct Node_00290568 { char pad[0x31C]; int m31C; };
extern void* D_0038FC78;
extern void* D_00392068;
extern "C" int func_0022EF38(void*);
extern "C" int func_002A8548(void*);
extern "C" void func_002A84E0(void*);

struct Base_00290568 {
    int m0;
    unsigned int m_type;
    int m8;
    Node_00290568* m_node;
    int m10;
    int m14;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int);
};

struct Comp_00290568 : public Base_00290568 {
    int m1C;
    void Update();
};

void Comp_00290568::Update()
{
    if (!func_0022EF38(D_0038FC78)) {
        v6(1);
        return;
    }
    if (!m_node->m31C) return;
    if (!(m1C & 2)) return;
    if (func_002A8548(D_00392068)) return;
    func_002A84E0(D_00392068);
}
