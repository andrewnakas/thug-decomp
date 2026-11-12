/* cflags: -fno-gcse */
extern "C" void func_002BCDF8(void* self);
extern "C" int* func_002BCE20(void* self, int a);
extern "C" void* func_00122CF8(unsigned int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90A8(void* arr, int i, int v);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);
extern "C" void* func_001190D0(unsigned int size);
extern "C" void* func_001E6978(void* p);
extern "C" void* func_002977B0();
extern "C" void func_00295498(void* p, unsigned int name, void* s);
extern "C" void func_001E78A8(void* s, unsigned int name, void* v);
extern "C" void* func_0029C320();
extern "C" void func_0029ACC0(void* p, void* s);
extern "C" void func_001E7200(void* s, unsigned int name, int v);

struct Info_002BCF50 {
    char pad0[0x28];
    int m28;
};

struct Obj_002BCF50 {
    Info_002BCF50* m0;
    void Save(void* params);
};

void Obj_002BCF50::Save(void* params)
{
    func_002BCDF8(this);
    int* data = func_002BCE20(this, 1);
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    int count = 3750;
    func_001E8E98(arr, count, 1);
    for (int i = 0; count > i; i++) {
        func_001E90A8(arr, i, data[i]);
    }
    func_001E7720(params, 0x337C5289, arr);
    void* s = func_001E6978(func_001190D0(8));
    func_00295498(func_002977B0(), 0xE8B4B836, s);
    func_001E78A8(params, 0xD8EB825E, s);
    func_0029ACC0(func_0029C320(), params);
    func_001E7200(params, 0xB7E39B53, m0->m28);
}
