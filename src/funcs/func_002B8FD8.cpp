struct Arr_002B8FD8 {
    char pad[0xC];
    int m_size;
};

extern "C" void* func_001E9378(Arr_002B8FD8* a, int i);
extern "C" int func_001E8398(void* s, unsigned int name, void* out, int req);

struct Obj_002B8FD8 {
    int GetNext(Arr_002B8FD8* arr, int* idx);
};

int Obj_002B8FD8::GetNext(Arr_002B8FD8* arr, int* idx)
{
    int n = arr->m_size;
    while (*idx < n) {
        void* e = func_001E9378(arr, *idx);
        unsigned int type = 0;
        func_001E8398(e, 0x12B4E660, &type, 0);
        if (type == 0xBF4D3536) {
            int v;
            if (func_001E8398(e, 0xA1DC81F9, &v, 0)) {
                (*idx)++;
                return v;
            }
        }
        (*idx)++;
    }
    return 0;
}
