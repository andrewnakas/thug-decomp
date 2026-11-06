struct Obj_001AB720 {
    char pad[0x1248];
    int m1248;
    int m124C[10];
    void Clear();
};

void Obj_001AB720::Clear()
{
    int i;
    m1248 = 0;
    for (i = 9; i >= 0; i--) {
        m124C[i] = 0;
    }
}
