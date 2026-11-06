extern "C" void* func_001317D0(void* name);
extern "C" void* func_00134F18(void* p);
extern "C" void* func_0013C2E0(void* p, int a, int b);
extern "C" void func_0013C568(void* p, int a);
extern "C" int func_0013D518(void* a, void* b, int c);

class Comp_0018B860 {
public:
    char pad0[0x260];
    void* m260;
    char pad264[0x28];
    int m28C;

    void Attach(void* name);
};

void Comp_0018B860::Attach(void* name)
{
    void* p = func_001317D0(name);
    if (!p) {
        return;
    }
    void* q = func_00134F18(p);
    if (!q) {
        return;
    }
    void* r = func_0013C2E0(q, 1, 0);
    func_0013C568(r, 1);
    func_0013D518(m260, r, 0);
    m28C = 1;
}
