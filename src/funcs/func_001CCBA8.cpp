struct Obj_001CCBA8 {
    char pad[0xA34];
    void* mA34;
    int mA38;
    void* mA3C;
    char pad2[0xA70 - 0xA40];
    char mA70[0xB50 - 0xA70];
    int mB50;
    void Update();
};
extern "C" void func_001BF130(Obj_001CCBA8* self, int v);
extern "C" void func_001BB080(void* p, int n, void* out);
extern "C" void func_001CE768(void* p, void* q);

void Obj_001CCBA8::Update()
{
    func_001BF130(this, 0);
    if (mB50) {
        func_001BB080(mA34, 5, mA70);
        func_001CE768(mA3C, mA70);
    }
}
