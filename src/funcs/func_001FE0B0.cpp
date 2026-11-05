struct Dev_001FE0B0 {
    char pad[0x1804];
    int m1804;
    char pad2[0x42A0 - 0x1808];
    int m42A0;
    char pad3[0x4358 - 0x42A4];
    virtual void v0();
    virtual int v1();
};
struct Obj_001FE0B0 {
    char pad[0x20];
    Dev_001FE0B0* m20;
    void Kick();
};
extern "C" void func_0031BCE0(int s);
extern "C" void func_0031BCC0(int s);

void Obj_001FE0B0::Kick()
{
    Dev_001FE0B0* d = m20;
    d->m1804++;
    func_0031BCE0(d->m42A0);
    d->v1();
    func_0031BCC0(d->m42A0);
}
