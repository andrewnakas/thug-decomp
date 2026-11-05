struct Obj_002069C0 {
    char pad[0x2B8];
    void* m2B8;
    char pad2[0x328 - 0x2BC];
    int m328;
    void Reset();
};
extern "C" void func_001B6BF0(void* p);
extern "C" void func_00185128(Obj_002069C0* self, int v);

void Obj_002069C0::Reset()
{
    func_001B6BF0(m2B8);
    func_00185128(this, 0);
    m328 = 1;
}
