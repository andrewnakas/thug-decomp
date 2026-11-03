extern "C" unsigned int func_0010FC30();
extern "C" float func_001E5318(unsigned int, int);
extern "C" unsigned int func_0033EBE0(float);
extern "C" int func_00103F28(const char* fmt, ...);
extern char D_00376B80[];
extern char D_00376B9F[];
extern char D_00376C38[];

struct Obj_0028EC88 {
    char pad0[0x37C];
    int m37C;
    unsigned int m380;
    void Tick();
};

void Obj_0028EC88::Tick()
{
    if (!m37C) return;
    unsigned int start = m380;
    unsigned int el = func_0010FC30() - start;
    if (func_0033EBE0(func_001E5318(0xF4813AD5, 0) * 1000.0f) < el) {
        m37C--;
        func_00103F28(D_00376B80, D_00376B9F, 0x20C4, D_00376C38);
        if (m37C) m380 = func_0010FC30();
    }
}
