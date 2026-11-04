struct Vec3_001EADF0 {
    int m_0;
    float x;
    float y;
    float z;
};

struct Vec2_001EADF0 {
    int m_0;
    float x;
    float y;
};

struct Array_001EADF0 {
    char m_pad[0x8];
    int m_type;
    int GetType() const { return m_type; }
};

struct Comp_001EADF0 {
    char m_0;
    unsigned char m_type;
    char m_pad2[0x8 - 2];
    union {
        int i;
        float f;
        void* p;
        Vec3_001EADF0* v3;
        Vec2_001EADF0* v2;
    };
};

extern "C" int func_001E9270(Array_001EADF0* a, int i);
extern "C" float func_001E9298(Array_001EADF0* a, int i);
extern "C" int func_001E9300(Array_001EADF0* a, int i);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void* func_001E9378(Array_001EADF0* a, int i);
extern "C" void func_001E6AC8(void* s, void* src);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* mem);
extern "C" void* func_001E93A0(Array_001EADF0* a, int i);
extern "C" void func_001E66C0(void* s, void* src);
extern "C" char* func_001E91C0(Array_001EADF0* a, int i);
extern "C" void* func_001E4DE0(char* s);
extern "C" Vec3_001EADF0* func_001E9328(Array_001EADF0* a, int i);
extern "C" void* func_001E8C80(int size);
extern "C" Vec3_001EADF0* func_001E4C68(void* mem);
extern "C" Vec2_001EADF0* func_001E9350(Array_001EADF0* a, int i);
extern "C" void* func_001E8C30(int size);
extern "C" Vec2_001EADF0* func_001E4C80(void* mem);

extern "C" void func_001EADF0(Array_001EADF0* arr, int index, Comp_001EADF0* out)
{
    out->m_type = arr->GetType();
    switch (out->m_type) {
    case 1:
        out->i = func_001E9270(arr, index);
        break;
    case 2:
        out->f = func_001E9298(arr, index);
        break;
    case 13:
        out->i = func_001E9300(arr, index);
        break;
    case 10:
        out->p = func_001E6978(func_001190D0(8));
        func_001E6AC8(out->p, func_001E9378(arr, index));
        break;
    case 12:
        out->p = func_001E8DD0(func_00122CF8(0x10));
        func_001E66C0(out->p, func_001E93A0(arr, index));
        break;
    case 3:
        out->p = func_001E4DE0(func_001E91C0(arr, index));
        break;
    case 6: {
        Vec3_001EADF0* src = func_001E9328(arr, index);
        out->v3 = func_001E4C68(func_001E8C80(0x10));
        out->v3->x = src->x;
        out->v3->y = src->y;
        out->v3->z = src->z;
        break;
    }
    case 5: {
        Vec2_001EADF0* src = func_001E9350(arr, index);
        out->v2 = func_001E4C80(func_001E8C30(0xC));
        out->v2->x = src->x;
        out->v2->y = src->y;
        break;
    }
    case 4:
    case 7:
    case 8:
    case 9:
    case 11:
    default:
        out->m_type = 0;
        out->i = 0;
        break;
    }
}
