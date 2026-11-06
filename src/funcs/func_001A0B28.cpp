extern "C" void func_0013CA80(char* p, int n);
struct Obj_001A0B28 {
    char pad[0x44];
    char* m44;
    void Run(int off);
};

void Obj_001A0B28::Run(int off)
{
    func_0013CA80(m44 + off, 0);
}
