struct Obj_002CC458;
extern "C" void func_002CC370(Obj_002CC458* o, int i, int a);

struct Obj_002CC458 {
    int m0;
    void* m4[32];
    void ClearAll();
};

void Obj_002CC458::ClearAll()
{
    for (int i = 0; i < 32; i++) {
        if (m4[i])
            func_002CC370(this, i, 0);
    }
}
