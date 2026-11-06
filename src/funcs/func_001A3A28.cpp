extern void* D_0038E0A0;

struct Vec_001A3A28 {
    float y, x, z;
    int w;
};

extern "C" void func_001DEB18(void* mgr, int a, Vec_001A3A28* v, void* obj, int b);

void func_001A3A28(void* obj, int a, int w, int b, float x, float y, float z)
{
    void* mgr = D_0038E0A0;
    Vec_001A3A28 v;
    v.w = w;
    v.x = x;
    v.y = y;
    v.z = z;
    func_001DEB18(mgr, a, &v, obj, b);
}
