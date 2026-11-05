struct Sub_00206920 {
    char pad[0x1C];
    int m1C;
};
struct Obj_00206920 {
    char pad[0x2DC];
    Sub_00206920* m2DC;
    char pad2[0x31C - 0x2E0];
    int m31C;
    void Stop();
};
extern "C" void* func_00185578(Obj_00206920* self, unsigned int id);
extern "C" void func_00274938(void* p);

void Obj_00206920::Stop()
{
    if (!m31C)
        func_00274938(func_00185578(this, 0x850EEF66));
    m2DC->m1C = 0;
}
