/* fuzzy: 78.9 */
struct Blk_001F5040 {
    int m0;
    char pad[0x4CE3C];
};
struct Obj_001F5040 {
    int m0;
    Blk_001F5040* m4;
    int m8;
    int mC;
    int m10;
    void Init(int a, Blk_001F5040* b, int n);
};

void Obj_001F5040::Init(int a, Blk_001F5040* b, int n)
{
    m8 = 0;
    mC = 0;
    m10 = n;
    m4 = b;
    m0 = a;
    for (int i = 0; i < n; i++)
        m4[i].m0 = 0;
}
