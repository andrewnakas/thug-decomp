struct Obj_00207EF8 {
    char pad[0x24];
    int m24;
    int m28;
    int* m2C;
    bool Replace(int a, int b);
};

bool Obj_00207EF8::Replace(int a, int b)
{
    for (int i = 0; i < m24; i++) {
        if (m2C[i] == a) {
            m2C[i] = b;
            return true;
        }
    }
    return false;
}
