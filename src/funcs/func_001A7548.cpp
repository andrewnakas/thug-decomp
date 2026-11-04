extern "C" int func_00229EB0(void* list);
extern "C" void* func_00229F48(void* list, int i);
extern "C" void func_0022A090(void* e, void* out);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);

struct Pos_001A7548 {
    float x, y, z, w;
};

struct C_001A7548 {
    int m_pad[134];
    void* m218;
    void Warp(void* params);
};

extern "C" void func_001A6CA0(C_001A7548* self, void* params, Pos_001A7548* pos);

void C_001A7548::Warp(void* params)
{
    int n = func_00229EB0(m218);
    if (!n) return;
    Pos_001A7548 pos;
    int i = 1;
    func_001E7DE8(params, 0xE85997D0, &i, 0);
    i--;
    if (i < 0 || i >= n) i = 0;
    func_0022A090(func_00229F48(m218, i), &pos);
    func_001A6CA0(this, params, &pos);
}
