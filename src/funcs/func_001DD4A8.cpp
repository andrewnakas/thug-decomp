struct Info_001DD4A8 {
    char m_pad[0x1C];
    float m1C;
};

struct Entry_001DD4A8 {
    int m0;
    int m4;
    Info_001DD4A8* m8;
    char m_padC[0x3C - 0xC];
};

extern Entry_001DD4A8 D_003EC2F8[42];
extern int D_0038881C;

extern "C" bool func_001DC418();
extern "C" int func_001DC840(void* self, unsigned int id);
extern "C" bool func_001DC658(void* obj);
extern "C" void func_001DD1E8(void* self, void* obj, float* vol, Info_001DD4A8* info);
extern "C" void func_001E1B38(int index, void* obj, float vol);
extern "C" int func_001E53A0(unsigned int key, int a);

extern "C" bool func_001DD4A8(void* self, unsigned int id, void* obj, float vol)
{
    if (func_001DC418())
        return true;
    int index = func_001DC840(self, id);
    if (index >= 0) {
        Info_001DD4A8* info = D_003EC2F8[index].m8;
        if (!info)
            return false;
        if (!func_001DC658(obj))
            func_001DD1E8(self, obj, &vol, info);
        vol = vol * info->m1C * 0.01f;
        func_001E1B38(index, obj, vol);
        return true;
    }
    if (!D_0038881C)
        func_001E53A0(0x6D2E270E, 0);
    return false;
}
