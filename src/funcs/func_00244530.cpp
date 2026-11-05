struct Node_00244530 {
    char pad0[0x20];
    void* m20;
    char pad24[0x54 - 0x24];
    int m54;
    char pad58[0xA0 - 0x58];
    int mA0;
    void Init();
};

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E8618(void* params, unsigned int name);
extern "C" bool func_00246740(Node_00244530* n);

void Node_00244530::Init()
{
    int a = 0;
    func_001E7DE8(m20, 0xF0E712D2, &a, 0);
    if (a == 1) return;
    if (func_00246740(this) && !func_001E8618(m20, 0x906B67BA)) return;
    m54 = 120;
    int t;
    if (func_001E7DE8(m20, 0x906B67BA, &t, 0)) m54 = t;
    mA0 = 0;
    m54 = m54 * 1000 + 20;
}
