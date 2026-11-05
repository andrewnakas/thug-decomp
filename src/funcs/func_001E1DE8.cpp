struct Buf_001E1DE8 {
    int m[8];
};
extern "C" void func_001DC540(Buf_001E1DE8* b);
extern "C" void func_001DC6D0(Buf_001E1DE8* b);
extern "C" int func_001E21C0(int i);
extern "C" void func_001E1B38(int i, Buf_001E1DE8* b, float f);
extern "C" void func_001DC578(Buf_001E1DE8* b, int n);

void func_001E1DE8()
{
    Buf_001E1DE8 b;
    func_001DC540(&b);
    func_001DC6D0(&b);
    for (int i = 0; i < 42; i++) {
        if (func_001E21C0(i))
            func_001E1B38(i, &b, 0.0f);
    }
    func_001DC578(&b, 2);
}
