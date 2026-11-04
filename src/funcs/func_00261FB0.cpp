struct Info_00261FB0 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Array_00261FB0 {
    char m_pad[0xC];
    int mC;
};

struct Profile_00261FB0 {
    int m0;
    char m4[0x58];
    char m5C[4];
};

extern "C" void func_00264728(Info_00261FB0* info);
extern "C" void* func_00262358(Profile_00261FB0* p);
extern "C" bool func_001E8A80(void* params, unsigned int name, Array_00261FB0** out, int required);
extern "C" void func_001E93D0(void* p, int a);
extern "C" void* func_001E9378(Array_00261FB0* arr, int index);
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E88D8(void* params, unsigned int name, int* out, int required);

Info_00261FB0 GetInfo_00261FB0(Profile_00261FB0* p, int index)
{
    Info_00261FB0 info;
    func_00264728(&info);
    void* store = func_00262358(p);
    Array_00261FB0* arr;
    func_001E8A80(store, 0, &arr, 1);
    if (index < 0 || index >= arr->mC) {
        func_001E93D0(p->m5C, 0);
        func_001E93D0(store, 0);
    }
    void* e = func_001E9378(arr, index);
    func_001E8A30(e, 0x5B077CE1, &info.m4, 1);
    func_001E8A30(e, 0xA92A2280, &info.m8, 1);
    int flag = 0;
    func_001E88D8(e, 0xB56A8816, &flag, 0);
    if (flag)
        info.mC = 1;
    return info;
}
