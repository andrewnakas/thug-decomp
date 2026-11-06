/* sym: __13Emit_00186CF8 = 0x00184EB8 */

extern "C" void* func_001046B0(int size);
extern "C" void func_00183F08(void* obj, int type);

class Emit_00186CF8 {
public:
    char pad[0x110];
    Emit_00186CF8();
    static void* operator new(unsigned int size) { return func_001046B0(size); }
};

class Mgr_00186CF8 {
public:
    char pad0[0x2C];
    virtual void V1();
    virtual void Add(Emit_00186CF8* e);
    Emit_00186CF8* NewEmitter();
};

Emit_00186CF8* Mgr_00186CF8::NewEmitter()
{
    Emit_00186CF8* e = new Emit_00186CF8;
    func_00183F08(e, 0xB);
    Add(e);
    return e;
}
