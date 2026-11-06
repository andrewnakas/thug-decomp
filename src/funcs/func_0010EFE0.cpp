struct Msg_0010EFE0 {
    int a;
    int b;
    int c;
};

extern volatile int D_00388CA0;
extern volatile int D_00388C98[2];
extern volatile Msg_0010EFE0 D_00464C38[2][16];

extern "C" void func_0010EFE0(int a, int b, int c)
{
    int q = D_00388CA0;
    volatile Msg_0010EFE0* m = &D_00464C38[q][D_00388C98[q]++];
    m->a = a;
    m->b = b;
    m->c = c;
}
