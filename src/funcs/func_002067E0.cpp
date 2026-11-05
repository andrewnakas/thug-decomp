struct Obj_002067E0 {
    char pad[0x23C];
    int m23C;
    void Start();
};
extern "C" void func_001F0210(unsigned int id, int a, Obj_002067E0* self, int b, int c);

void Obj_002067E0::Start()
{
    func_001F0210(0xAF4475DE, 0, this, 0, 0);
    m23C = 1;
}
