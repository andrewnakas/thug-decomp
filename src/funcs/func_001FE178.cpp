struct Dev_001FE178 {
    char pad[0x4294];
    int m4294;
    int m4298;
};
struct Obj_001FE178 {
    char pad[0x20];
    Dev_001FE178* m20;
    void Close();
};
extern "C" void func_001FDCB8(Dev_001FE178* d);
extern "C" void func_0031BCE0(int s);
extern "C" void func_0031BCC0(int s);
extern "C" void func_0031BBD0(int s);

void Obj_001FE178::Close()
{
    Dev_001FE178* d = m20;
    func_001FDCB8(d);
    func_0031BCE0(d->m4298);
    func_0031BCC0(d->m4298);
    func_0031BBD0(d->m4294);
}
