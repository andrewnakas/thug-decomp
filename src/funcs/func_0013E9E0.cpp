extern "C" void func_0013C410(void* e);

struct Mesh_0013E9E0;
extern "C" int func_0013E9D8(Mesh_0013E9E0* m);
extern "C" void* func_0013E9B8(Mesh_0013E9E0* m, short i);

struct Mesh_0013E9E0 {
    int m0;
    void ResetAll();
};

void Mesh_0013E9E0::ResetAll()
{
    int n = func_0013E9D8(this);
    for (short i = 0; i < n; i++)
        func_0013C410(func_0013E9B8(this, i));
}
