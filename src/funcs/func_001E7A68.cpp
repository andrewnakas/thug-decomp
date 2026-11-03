struct Struct_001E7A68;

extern "C" void func_001E7200(Struct_001E7A68*, unsigned int, int);
extern "C" void func_001E72B0(Struct_001E7A68*, unsigned int, float);
extern "C" void func_001E78A8(Struct_001E7A68*, unsigned int, void*);
extern "C" void func_001E7720(Struct_001E7A68*, unsigned int, void*);
extern "C" void func_001E7360(Struct_001E7A68*, unsigned int, int);

union Val_001E7A68 {
    int i;
    float f;
    void* p;
};

extern "C" void func_001E7A68(Struct_001E7A68* s, unsigned int name, int type, Val_001E7A68 v)
{
    switch (type) {
    case 1:
        func_001E7200(s, name, v.i);
        break;
    case 2:
        func_001E72B0(s, name, v.f);
        break;
    case 11:
        func_001E78A8(s, name, v.p);
        break;
    case 12:
        func_001E7720(s, name, v.p);
        break;
    case 13:
        func_001E7360(s, name, v.i);
        break;
    }
}
