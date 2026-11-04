struct Rec_00293F50 { unsigned char id, a, b, c; };
struct Arr_00293F50 { char pad[0xC]; int mC; };
extern "C" int func_001E8248(void* p, unsigned int key, Arr_00293F50** out, int req);
extern "C" void* func_001E9378(Arr_00293F50*, int);
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int req);
extern "C" int func_001E8708(void* p, unsigned int key);

struct Obj_00293F50 {
    char pad0[0x2E0];
    Rec_00293F50 m2E0[10];
    int m308;
    void ReadRecs(void* s);
};

void Obj_00293F50::ReadRecs(void* s)
{
    Arr_00293F50* arr = 0;
    if (!func_001E8248(s, 0x0490F171, &arr, 0)) return;
    m308 = arr->mC;
    for (int i = 0; i < m308; i++) {
        void* st = func_001E9378(arr, i);
        int v = 0;
        func_001E7DE8(st, 0xEB7D6498, &v, 0);
        m2E0[i].id = v;
        v = 0;
        func_001E7DE8(st, 0xEDF5DB70, &v, 0);
        m2E0[i].b = v / 180;
        v = 0;
        func_001E7DE8(st, 0xA4BEE6A1, &v, 0);
        m2E0[i].c = v;
        m2E0[i].a = func_001E8708(st, 0x687E2C25);
    }
}
