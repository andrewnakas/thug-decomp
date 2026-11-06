/* sym: __13Base_001F2CD8 = 0x001829A8 */
/* sym: _vt$12Obj_001F2CD8 = 0x003660C0 */
struct Pool_001F2CD8 {
    char pad[0xEC];
    void* mEC;
};
extern Pool_001F2CD8* D_00388A70;
extern "C" void func_0010A950(Pool_001F2CD8* pool, void* ctx);
extern "C" void* func_0010A638(Pool_001F2CD8* pool, int size, int a, int b);
extern "C" void* func_001F32E8(void* p, int n);
extern "C" void func_0010A9B0(Pool_001F2CD8* pool);

struct Base_001F2CD8 {
    char pad[0x14];
    Base_001F2CD8();
    virtual void V0();
};

struct Obj_001F2CD8 : public Base_001F2CD8 {
    void* m18;
    int m1C;
    int m20;
    int m24;
    Obj_001F2CD8();
    virtual void V0();
};

Obj_001F2CD8::Obj_001F2CD8()
{
    func_0010A950(D_00388A70, D_00388A70->mEC);
    m18 = func_001F32E8(func_0010A638(D_00388A70, 0x18, 1, 0), 8);
    func_0010A9B0(D_00388A70);
    m1C = 0;
    m20 = 0;
    m24 = 0;
}
