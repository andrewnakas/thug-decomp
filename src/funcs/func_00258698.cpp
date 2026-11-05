struct Obj_00258698;
extern "C" int func_00258528(Obj_00258698* self, int* buf, int a);

struct Obj_00258698 {
    int Fn(int idx, int a);
};

int Obj_00258698::Fn(int idx, int a)
{
    int buf[256];
    int n = func_00258528(this, buf, a);
    if (n == 0) return -1;
    if (n > 0) {
        return buf[idx < n ? idx : idx % n];
    }
    return -1;
}
