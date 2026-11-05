struct Obj_00203018 {
    int m0;
    char m4[4];
    int Get(unsigned int id, unsigned int key);
};
extern "C" int func_001E89F0(void* params, unsigned int id, void** out, int req);
extern "C" int func_001E8A30(void* params, unsigned int id, int* out, int req);

int Obj_00203018::Get(unsigned int id, unsigned int key)
{
    void* s = 0;
    func_001E89F0(m4, id, &s, 1);
    int v;
    func_001E8A30(s, key, &v, 1);
    return v;
}
