struct Obj_00202F78 {
    int m0;
    char m4[4];
    int Get(unsigned int id, unsigned int key);
};
extern "C" int func_001E8180(void* params, unsigned int id, void** out, int req);
extern "C" int func_001E8870(void* params, unsigned int id, int* out, int req);

int Obj_00202F78::Get(unsigned int id, unsigned int key)
{
    void* s = 0;
    func_001E8180(m4, id, &s, 0);
    int v;
    func_001E8870(s, key, &v, 1);
    return v;
}
