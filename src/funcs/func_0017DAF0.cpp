struct Mesh_0017DAF0 {
    char pad0[0xC];
    void* mC;
    char pad10[0x34];
    int m44;
    int m48;
    char pad4C[4];
};

struct Model_0017DAF0 {
    char pad0[0x30];
    int m30;
    int pad34;
    Mesh_0017DAF0* m38;
};

struct Mat_0017DAF0 {
    float m[4][4];
};

extern "C" void func_00162150(void* p, Mat_0017DAF0* m);

extern "C" void func_0017DAF0(Model_0017DAF0* model, int a, int b, float x, float y)
{
    Mat_0017DAF0 mat;
    mat.m[0][0] = 1.0f;
    mat.m[0][1] = 0.0f;
    mat.m[0][2] = 0.0f;
    mat.m[0][3] = 0.0f;
    mat.m[1][0] = 0.0f;
    mat.m[1][1] = 1.0f;
    mat.m[1][2] = 0.0f;
    mat.m[1][3] = 0.0f;
    mat.m[2][0] = 0.0f;
    mat.m[2][1] = 0.0f;
    mat.m[2][2] = 1.0f;
    mat.m[2][3] = 0.0f;
    mat.m[3][2] = 0.0f;
    mat.m[3][3] = 1.0f;
    mat.m[3][0] = x;
    mat.m[3][1] = y;
    Mesh_0017DAF0* mesh = model->m38;
    for (int i = 0; i < model->m30; i++, mesh++) {
        if (mesh->m48 == a && mesh->m44 == b) {
            func_00162150(mesh->mC, &mat);
        }
    }
}
