extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int req);

struct Obj_00247488 {
    char pad[0x20];
    void* m20;
    bool Fn();
};

bool Obj_00247488::Fn()
{
    int v = 0;
    func_001E7DE8(m20, 0xF0E712D2, &v, 0);
    return v == 0;
}
