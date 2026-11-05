extern "C" int func_0031A168(int a, int b, int c);
extern "C" void* func_003315B8(void* p, int c, int n);

struct Obj_00107BF0 {
    char pad[0x10];
    int m10;
    int m14;
    int m18;
    int m1C;
    char m20[0x20];
    char pad40[0xDC - 0x40];
    int mDC;
    void Begin();
};

void Obj_00107BF0::Begin()
{
    if (mDC == 0) {
        int r = func_0031A168(m10, m14, m1C);
        if (r == 1) {
            func_003315B8(m20, 0, 0x20);
            mDC = r;
            m18 = 0;
        }
    }
}
