extern "C" void func_001617A0(int a);
extern int D_003942A0;
extern int D_0039427C;

void Sync_00178060()
{
    int cur = D_003942A0;
    if (D_0039427C != cur)
        func_001617A0(cur);
}
