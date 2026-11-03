extern "C" void func_00142CF0(void* q);
extern "C" void* func_00142D00(void* q, int a);
extern "C" void func_00142298(void* e);

struct Queue1427E8 {
    void* m0;
    void Flush();
};

void Queue1427E8::Flush()
{
    func_00142CF0(m0);
    void* e = func_00142D00(m0, 0);
    while (e) {
        func_00142298(e);
        e = func_00142D00(m0, 0);
    }
}
