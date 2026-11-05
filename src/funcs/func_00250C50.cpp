struct Obj_00250C50 {
    char pad[0x14];
    int m14[8];
    int Fn(int n);
};

int Obj_00250C50::Fn(int n)
{
    int a = 0;
    int b = 0;
    for (int i = 0; i < n + 1; i++) {
        int v = m14[i];
        if (v > a) {
            b = a;
            a = v;
        } else if (v > b) {
            b = v;
        }
    }
    return a + b;
}
