struct Mesh_0017DBC8 {
    char pad0[0xC];
    void* mC;
    char pad10[0x34];
    int m44;
    int m48;
    char pad4C[4];
};

struct Model_0017DBC8 {
    char pad0[0x30];
    int m30;
    int pad34;
    Mesh_0017DBC8* m38;
};

extern "C" void func_00162150(void* p, void* m);

extern "C" void func_0017DBC8(Model_0017DBC8* model, int a, int b, void* m)
{
    Mesh_0017DBC8* mesh = model->m38;
    for (int i = 0; i < model->m30; i++, mesh++) {
        if (mesh->m48 == a && mesh->m44 == b) {
            func_00162150(mesh->mC, m);
        }
    }
}
