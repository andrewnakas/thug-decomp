extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Mat_0014C590 {
    float m[4][4];
    Mat_0014C590() {}
    static void* operator new[](unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
    void Identity()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    }
};

struct Obj_0014C590 {
    char pad[0x1C0];
    Mat_0014C590* m1C0;
    bool Alloc(int n);
};

bool Obj_0014C590::Alloc(int n)
{
    m1C0 = new Mat_0014C590[n * 2];
    for (int i = 0; i < n * 2; i++) m1C0[i].Identity();
    return true;
}
